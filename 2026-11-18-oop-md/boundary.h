#pragma once
// boundary.h
#include <valarray>
#include <iostream>

class Boundary{
  double RMAX_{0.0}, EN_{0.0}; // RMAX is the radius of the sphere, EN is the normal restitution coefficient 
  std::valarray<double> C_{0.0, 0.0, 0.0}; // Sphere center

  public:
    Boundary(double RMAX, double CX, double CY, double CZ, double EN) {
      RMAX_ = RMAX;
      C_[0] = CX;
      C_[1] = CY;
      C_[2] = CZ;
      EN_ = EN;
    }

    template <class particle_array_t>
    void apply(particle_array_t & parray) {
      // applySphericalConstraint
      for (auto & p : parray) {
            std::valarray<double> Rprime = p.R - C_;
            double rprime = std::sqrt((Rprime*Rprime).sum());
            double delta = rprime + p.rad - RMAX_;
            if (delta > 0) {
                std::valarray<double> N = Rprime/rprime;
                p.R = p.R - delta*N;
                p.V = p.V - (1+EN_)*((p.V*N).sum())*N;
            }
        }
    }
};