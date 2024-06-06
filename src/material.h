/**
  ******************************************************************************
  * @file           : material.h
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/6/6
  ******************************************************************************
  */



#ifndef RAY_TRACING_IN_ONE_WEEKEND_MATERIAL_H
#define RAY_TRACING_IN_ONE_WEEKEND_MATERIAL_H

#include "rtweekend.h"
#include "hittable.h"

struct hit_record;

class Material {
public:
    virtual bool Scatter(
            const Ray& r_in, const hit_record& rec, Color& attenuation, Ray& scattered) const = 0;
};

class Lambertian : public Material {
public:
    Lambertian(const Color& a) : albedo(a) {}

    virtual bool Scatter(
            const Ray& r_in, const hit_record& rec, Color& attenuation, Ray& scattered
    ) const override {
        auto scatter_direction = rec.normal + random_unit_vector();

        // Catch degenerate scatter direction
        if (scatter_direction.near_zero())
            scatter_direction = rec.normal;

        scattered = Ray(rec.p, scatter_direction);
        attenuation = albedo;
        return true;
    }

public:
    Color albedo;
};

#endif //RAY_TRACING_IN_ONE_WEEKEND_MATERIAL_H
