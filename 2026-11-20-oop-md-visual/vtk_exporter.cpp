#include "vtk_exporter.h"
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

VTKExporter::VTKExporter(const std::string& output_directory) 
    : output_dir(output_directory) {
    // Create output directory if it doesn't exist
    if (!fs::exists(output_dir)) {
        try {
            fs::create_directories(output_dir);
            std::cout << "Created output directory: " << output_dir << "\n";
        } catch (const std::exception& e) {
            std::cerr << "Warning: Could not create output directory: " << e.what() << "\n";
        }
    }
}

void VTKExporter::write_frame(const std::vector<Particle>& bodies, double time) {
    // Generate filename
    std::ostringstream filename_stream;
    filename_stream << output_dir << "/frame_" 
                   << std::setfill('0') << std::setw(6) << frame_counter 
                   << ".vtk";
    std::string filename = filename_stream.str();
    
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file for writing: " << filename << "\n";
        return;
    }
    
    // VTK Legacy Format Header
    file << "# vtk DataFile Version 2.0\n";
    file << "Particle simulation - Time: " << std::fixed << std::setprecision(6) 
         << time << " s\n";
    file << "ASCII\n";
    file << "DATASET UNSTRUCTURED_GRID\n";
    
    // Points (particle positions)
    file << "POINTS " << bodies.size() << " float\n";
    for (const auto& p : bodies) {
        file << std::scientific << std::setprecision(8)
             << p.R[0] << " " << p.R[1] << " " << p.R[2] << "\n";
    }
    
    // Cells (particles as vertices)
    file << "CELLS " << bodies.size() << " " << bodies.size() * 2 << "\n";
    for (size_t i = 0; i < bodies.size(); ++i) {
        file << "1 " << i << "\n";
    }
    
    // Cell types (1 = VTK_VERTEX)
    file << "CELL_TYPES " << bodies.size() << "\n";
    for (size_t i = 0; i < bodies.size(); ++i) {
        file << "1\n";
    }
    
    // Point data (velocities)
    file << "POINT_DATA " << bodies.size() << "\n";
    file << "VECTORS velocity float\n";
    for (const auto& p : bodies) {
        file << std::scientific << std::setprecision(8)
             << p.V[0] << " " << p.V[1] << " " << p.V[2] << "\n";
    }
    
    // Scalar data (kinetic energy, speed)
    file << "SCALARS kinetic_energy float 1\n";
    file << "LOOKUP_TABLE default\n";
    for (const auto& p : bodies) {
        double speed_sq = p.V[0]*p.V[0] + p.V[1]*p.V[1] + p.V[2]*p.V[2];
        double KE = 0.5 * p.mass * speed_sq;
        file << std::scientific << std::setprecision(8) << KE << "\n";
    }
    
    // Speed magnitude
    file << "SCALARS speed float 1\n";
    file << "LOOKUP_TABLE default\n";
    for (const auto& p : bodies) {
        double speed_sq = p.V[0]*p.V[0] + p.V[1]*p.V[1] + p.V[2]*p.V[2];
        double speed = std::sqrt(speed_sq);
        file << std::scientific << std::setprecision(8) << speed << "\n";
    }

	// Particle radius
	file << "SCALARS radius float 1\n";
	file << "LOOKUP_TABLE default\n";
	for (const auto& p : bodies) {
		file << std::scientific << std::setprecision(8) << p.rad << "\n";
	}

	// Particle mass (bonus)
	file << "SCALARS mass float 1\n";
	file << "LOOKUP_TABLE default\n";
	for (const auto& p : bodies) {
		file << std::scientific << std::setprecision(8) << p.mass << "\n";
	}    
    
    file.close();
    std::cout << "Wrote VTK frame: " << filename << " (t = " << time << " s)\n";
    frame_counter++;
}

void VTKExporter::reset_counter() {
    frame_counter = 0;
}