/**
  ******************************************************************************
  * @file           : sphere.hpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/6/5
  ******************************************************************************
  */



#ifndef RAY_TRACING_IN_ONE_WEEKEND_SPHERE_HPP
#define RAY_TRACING_IN_ONE_WEEKEND_SPHERE_HPP

#include "hittable.h"
#include "vec3.hpp"

class Sphere : public Hittable {
public:
    Point3 center;
    double radius;

public:
    Sphere() {}
    Sphere(Point3 cen, double r) : center(cen), radius(r) {}

    bool hit(const Ray &r, double t_min, double t_max, hit_record &rec) const override {
        Vec3 oc = r.origin() - center;
        auto a = r.direction().squared_length();
        auto half_b = dot(oc, r.direction());
        auto c = oc.squared_length() - radius*radius;

        auto discriminant = half_b*half_b - a*c;
        if (discriminant < 0) return false;
        auto sqrtd = sqrt(discriminant);

        // Find the nearest root that lies in the acceptable range.
        auto root = (-half_b - sqrtd) / a;
        if (root < t_min || t_max < root) {
            root = (-half_b + sqrtd) / a;
            if (root < t_min || t_max < root)
                return false;
        }

        rec.t = root;
        rec.p = r.at(rec.t);
        Vec3 outward_normal = (rec.p - center) / radius;
        rec.set_face_normal(r, outward_normal);

        return true;
    };


};

#endif //RAY_TRACING_IN_ONE_WEEKEND_SPHERE_HPP
