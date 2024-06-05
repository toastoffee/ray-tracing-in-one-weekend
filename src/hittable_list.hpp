/**
  ******************************************************************************
  * @file           : hittable_list.h
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/6/5
  ******************************************************************************
  */



#ifndef RAY_TRACING_IN_ONE_WEEKEND_HITTABLE_LIST_HPP
#define RAY_TRACING_IN_ONE_WEEKEND_HITTABLE_LIST_HPP

#include "hittable.h"

#include <memory>
#include <vector>

class HittableList : public Hittable {
public:
    std::vector<std::shared_ptr<Hittable>> objects;

public:
    HittableList() {}
    HittableList(std::shared_ptr<Hittable> object){ add(object); }

    void clear() { objects.clear(); }
    void add(std::shared_ptr<Hittable> object) { objects.push_back(object); }

    bool hit(const Ray &r, double t_min, double t_max, hit_record &rec) const override {
        hit_record temp_rec;
        bool hit_anything = false;
        auto closest_so_far = t_max;

        for (const auto& object : objects) {
            if (object->hit(r, t_min, closest_so_far, temp_rec)) {
                hit_anything = true;
                closest_so_far = temp_rec.t;
                rec = temp_rec;
            }
        }

        return hit_anything;
    }


};

#endif //RAY_TRACING_IN_ONE_WEEKEND_HITTABLE_LIST_HPP
