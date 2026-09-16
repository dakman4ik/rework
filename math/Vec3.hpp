#pragma once

class Vec3{
public:
    float x,y,z;

    Vec3();
    Vec3(float xx, float yy, float zz);

    Vec3 operator+ (const Vec3& other) const;
    Vec3 operator- (const Vec3& other) const;

    Vec3& operator+= (const Vec3& other);
    Vec3& operator-= (const Vec3& other);

    Vec3 cross(const Vec3& other) const;
    float dot(const Vec3& other) const;
};