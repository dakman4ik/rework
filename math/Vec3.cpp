#include "Vec3.hpp"

Vec3::Vec3(float xx, float yy, float zz) : x(xx), y(yy), z(zz) {}
Vec3::Vec3() : x(0.0), y(0.0), z(0.0) {}

Vec3 Vec3::operator+(const Vec3& other) const{
    return Vec3(other.x + this->x,other.y + this->y,other.z + this->z);
}

Vec3 Vec3::operator-(const Vec3& other) const{
    return Vec3(this->x - other.x,this->y - other.y,this->z - other.z);
}

Vec3& Vec3::operator+=(const Vec3& other){
    this->x += other.x;
    this->y += other.y;
    this->z += other.z;
    return *this;
}
Vec3& Vec3::operator-=(const Vec3& other){
    this->x -= other.x;
    this->y -= other.y;
    this->z -= other.z;
    return *this;
}

Vec3 Vec3::cross(const Vec3& other) const{
    return Vec3((this->y*other.z)-(this->z*other.y), (this->z*other.x)-(this->x*other.z), (this->x*other.y)-(this->y*other.x));
}

float Vec3::dot(const Vec3& other) const{
    return this->x*other.x + this->y*other.y + this->z*other.z;
}
