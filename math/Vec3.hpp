#pragma once

class Vec3{
public:
    float x,y,z;
    Vec3(float x, float y, float z);
    Vec3 operator+ (const Vec3& other) const;
    float dot(const Vec3& other) const;
};