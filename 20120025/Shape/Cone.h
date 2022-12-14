#pragma once
#include "./Cylinder.h"

class Cone : public Cylinder {
    // Cone is a special case of Cylinder with top radius = 0.0f

public:
    Cone(float x, float y, float z, float radius, float height, int slices = 360)
        : Cylinder(x, y, z, radius, 0.0f, height, slices) {}
};