#pragma once
// integrator.h
class TimeIntegrator{
    double dt{0.0};

public:
    TimeIntegrator(double DT) { dt = DT; }

    template <class particle_array_t>
        void startIntegration(particle_array_t & parray) {
        // this function moves the initial velocity to -dt/2
        // V = V - A dt/2 = V - F dt /2m
        for (auto & p : parray) {
            p.V = p.V - p.F*dt/(2*p.mass); // assumes valarray or similar
        }
    }

    template <class particle_array_t>
        void timeStep(particle_array_t & parray) {
        // this function moves the velocity by dt
        for (auto & p : parray) {
            p.V = p.V + p.F*dt/(p.mass); // assumes valarray or similar
            p.R = p.R + p.V*dt; // assumes valarray or similar
        }

    }
};