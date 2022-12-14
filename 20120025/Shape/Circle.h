#pragma once
#include "./MyEllipse.h"

class Circle : public MyEllipse {
    // Circle is a special case of MyEllipse with a = b

public:
    Circle(float x, float y, float z, float radius, int slices = 180) : MyEllipse(x, y, z, radius, radius, slices) {}

    Circle(float x, float y, float z, float radius, int slices, int texture, float angle, float deltaAngle)
        : MyEllipse(x, y, z, radius, radius, slices, texture, angle, deltaAngle) {}
};