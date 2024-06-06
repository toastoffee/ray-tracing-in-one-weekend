/**
  ******************************************************************************
  * @file           : rtweekend.h
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/6/5
  ******************************************************************************
  */


#ifndef RAY_TRACING_IN_ONE_WEEKEND_RTWEEKEND_H
#define RAY_TRACING_IN_ONE_WEEKEND_RTWEEKEND_H

#include <cmath>
#include <limits>
#include <memory>

// Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions

inline double degrees_to_radians(double degrees){
    return degrees * pi / 180.0;
}

inline double random_double() {
    // Returns a random real in [0,1).
    return rand() / (RAND_MAX + 1.0);
}

inline double random_double(double min, double max) {
    // Returns a random real in [min,max).
    return min + (max-min)*random_double();
}

inline double clamp(double x, double min, double max) {
    if (x < min) return min;
    if (x > max) return max;
    return x;
}

// Common Headers

#include "ray.hpp"
#include "vec3.hpp"

#endif //RAY_TRACING_IN_ONE_WEEKEND_RTWEEKEND_H
