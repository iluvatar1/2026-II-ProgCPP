// main_visual_md.cpp
// SFML 3 compatible version with Visualizer and VTKExporter classes
// g++ -std=c++23 -g -I /opt/homebrew/include/ -L /opt/homebrew/lib/ particle.cpp main_visual_md.cpp visualizer.cpp vtk_exporter.cpp -lsfml-window -lsfml-graphics -lsfml-system
// LINUX: g++ -std=c++23 -DSFML_STATIC  particle.cpp visualizer.cpp vtk_exporter.cpp main_visual_md.cpp -lsfml-graphics-s -lsfml-window-s -lsfml-audio-s -lsfml-system-s -lfreetype -lX11 -lXrandr -lXcursor -lXi -ludev -lsfml-audio-s 
#include "particle.h"
#include "integrator.h"
#include "collider.h"
#include "boundary.h"
#include "visualizer.h"
#include "vtk_exporter.h"
#include <vector>
#include <map>
#include <string>
#include <iostream>

void initial_conditions(std::vector<Particle>& particles);

int main(int argc, char** argv) {
    std::vector<Particle> bodies;
    bodies.resize(1); // only one particle for now

    // Physics parameters
    std::map<std::string, double> p;
    p["T0"] = 0.0;
    p["TF"] = 100.8767;
    p["DT"] = 0.01;
    p["G"] = 0.0; //-9.81;

	p["RMAX"] = 2.345;
    
    // Force collider
    Collider collider(p);

    // Time initialization
    TimeIntegrator integrator(p["DT"]);

    // Boundary conditions
    Boundary bc(p["RMAX"], 0.0, 0.0, 0.0, 1.0); // RMAX, CX, CY, CZ, EN

    // Initial conditions and properties
    initial_conditions(bodies);
    collider.computeForces(bodies); // force at t = 0
    integrator.startIntegration(bodies); // start integration algorithm
    
    std::cout << "=== Simulation Start ===\n";
    std::cout << p["T0"] << "\t";
    bodies[0].print();
    std::cout << "\n";

    // --- VISUALIZATION & I/O SETUP ---
    // Create visualizer
    Visualizer visualizer(800, 600, 100.0f);  // width, height, scale
    
    // Initialize visualizer with particles and boundary
    visualizer.initialize(bodies, p["RMAX"], 0.0f, 0.0f);
    
    // Create VTK exporter
    VTKExporter vtk_exporter("output");
    vtk_exporter.reset_counter();

    // Time iteration
    const int niter = int((p["TF"] - p["T0"]) / p["DT"]);
    double time = p["T0"];

    for (int ii = 1; ii < niter; ++ii) {
        // Physics simulation
        collider.computeForces(bodies);
        integrator.timeStep(bodies);
        bc.apply(bodies);
        time += p["DT"];

        // Render (handles window events internally)
        if (!visualizer.update_and_render(bodies, time, p["DT"])) {
            break;  // Window closed
        }

        // Export to VTK every 100 frames
        if (ii % 100 == 0) {
            vtk_exporter.write_frame(bodies, time);
        }

        // Optional: Print to stdout every 1000 frames
        if (ii % 1000 == 0) {
            std::cout << time << "\t";
            bodies[0].print();
            std::cout << "\n";
        }
    }

    std::cout << "=== Simulation Complete ===\n";
    std::cout << "Final time: " << time << " s\n";
    std::cout << "VTK files saved to output/ directory\n";
    
    return 0;
}

void initial_conditions(std::vector<Particle>& particles) {
    particles[0].R[2] = 0.987;    // z is upwards, x to the right
    particles[0].V[0] = 4.9876;   // initial velocity in x
    particles[0].V[2] = 0.0;      // initial velocity in z
    particles[0].rad = 0.103;     // particle radius
    particles[0].mass = 0.337;    // particle mass
}