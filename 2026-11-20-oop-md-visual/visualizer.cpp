#include "visualizer.h"

Visualizer::Visualizer(unsigned int w, unsigned int h, float scale)
    : width(w), height(h), meters_to_pixels(scale) {
    
    // Create window (SFML 3 uses Vector2u)
    window = std::make_unique<sf::RenderWindow>(sf::VideoMode({w, h}), "Physics Simulation");
    window->setFramerateLimit(120);
}

void Visualizer::initialize(const std::vector<Particle>& bodies,
                           float b_radius,
                           float b_cx,
                           float b_cy) {
    boundary_radius = b_radius;
    boundary_cx = b_cx;
    boundary_cy = b_cy;
    
    // Create particle shapes once
    particle_shapes.clear();
    for (const auto& body : bodies) {
        float pixel_radius = body.rad * meters_to_pixels;
        
        sf::CircleShape shape(pixel_radius);
        shape.setFillColor(sf::Color::Cyan);
        shape.setOrigin({pixel_radius, pixel_radius});
        
        particle_shapes.push_back(shape);
    }
    
    // Create boundary circle
    float boundary_pixel_radius = boundary_radius * meters_to_pixels;
    boundary_circle.setRadius(boundary_pixel_radius);
    boundary_circle.setFillColor(sf::Color::Transparent);
    boundary_circle.setOutlineThickness(2.f);
    boundary_circle.setOutlineColor(sf::Color::Red);
    boundary_circle.setOrigin({boundary_pixel_radius, boundary_pixel_radius});
    
    // Position boundary at center offset
    sf::Vector2f boundary_screen_pos;
    boundary_screen_pos.x = (width / 2.0f) + (boundary_cx * meters_to_pixels);
    boundary_screen_pos.y = (height / 2.0f) - (boundary_cy * meters_to_pixels);
    boundary_circle.setPosition(boundary_screen_pos);
    
    // Start render clock
    render_clock.restart();
    frame_counter = 0;
}

bool Visualizer::update_and_render(const std::vector<Particle>& bodies,
                                   double time,
                                   double dt) {
    // Handle events (SFML 3 uses std::optional)
    while (const auto event = window->pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window->close();
            return false;
        }
    }
    
    // Update particle positions only (no shape recreation)
    for (size_t i = 0; i < bodies.size() && i < particle_shapes.size(); ++i) {
        sf::Vector2f screen_pos;
        screen_pos.x = (width / 2.0f) + (bodies[i].R[0] * meters_to_pixels);
        screen_pos.y = (height / 2.0f) - (bodies[i].R[2] * meters_to_pixels);
        particle_shapes[i].setPosition(screen_pos);
    }
    
    // Clear screen
    window->clear(sf::Color::Black);
    
    // Draw boundary
    window->draw(boundary_circle);
    
    // Draw particles
    for (const auto& shape : particle_shapes) {
        window->draw(shape);
    }
    
    // Display and reset clock
    window->display();
    frame_counter++;
    render_clock.restart();
    
    return window->isOpen();
}

bool Visualizer::is_open() const {
    return window && window->isOpen();
}

float Visualizer::get_last_render_time_ms() const {
    return render_clock.getElapsedTime().asMilliseconds();
}