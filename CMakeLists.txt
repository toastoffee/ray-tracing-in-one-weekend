cmake_minimum_required(VERSION 3.27)
project(ray_tracing_in_one_weekend)

set(CMAKE_CXX_STANDARD 17)

add_executable(ray_tracing_in_one_weekend
        main.cpp
        src/vec3.hpp
        src/color.hpp
        src/ray.hpp
        src/hittable.h
        src/sphere.hpp
        src/hittable_list.h)
