#ifndef VTK_EXPORTER_H
#define VTK_EXPORTER_H

#include <string>
#include <vector>
#include "particle.h"

class VTKExporter {
private:
    std::string output_dir;
    int frame_counter = 0;
    
public:
    // Constructor
    explicit VTKExporter(const std::string& output_directory = "output");
    
    // Export particle data to VTK legacy format
    void write_frame(const std::vector<Particle>& bodies, double time);
    
    // Reset counter
    void reset_counter();
};

#endif