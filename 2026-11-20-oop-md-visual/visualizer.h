#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <memory>
#include "particle.h"

class Visualizer {
private:
    std::unique_ptr<sf::RenderWindow> window;
    std::vector<sf::CircleShape> particle_shapes;
    sf::CircleShape boundary_circle;
    
    // Settings
    float meters_to_pixels;
    unsigned int width, height;
    float boundary_radius;
    float boundary_cx, boundary_cy;
    
    // Performance tracking
    sf::Clock render_clock;
    int frame_counter = 0;
    
public:
    // Constructor
    Visualizer(unsigned int width = 800, 
               unsigned int height = 600, 
               float scale = 100.0f);
    
    // Destructor
    ~Visualizer() = default;
    
    // Setup (call once before main loop)
    void initialize(const std::vector<Particle>& bodies,
                   float boundary_radius,
                   float boundary_cx = 0.0f,
                   float boundary_cy = 0.0f);
    
    // Update and render (call each frame, returns false if window closed)
    bool update_and_render(const std::vector<Particle>& bodies, 
                          double time, 
                          double dt);
    
    // Query state
    bool is_open() const;
    
    // Get render time statistics
    float get_last_render_time_ms() const;
};

#endif