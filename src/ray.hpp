/**
  ******************************************************************************
  * @file           : ray.hpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/6/5
  ******************************************************************************
  */



#ifndef RAY_TRACING_IN_ONE_WEEKEND_RAY_HPP
#define RAY_TRACING_IN_ONE_WEEKEND_RAY_HPP

#include "vec3.hpp"

class Ray {
public:
    Point3 orig;
    Vec3 dir;

public:
    Ray() {}
    Ray(const Point3& origin, const Vec3& direction)
        : orig(origin), dir(direction) {}

    Point3 origin() const { return orig; }
    Vec3 direction() const { return dir; }
    Point3 at(double t) const {
        return orig + t * dir;
    }

};

#endif //RAY_TRACING_IN_ONE_WEEKEND_RAY_HPP
