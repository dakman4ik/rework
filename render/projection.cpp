#include "../math/Vec3.hpp"
#include "projection.hpp"
#include <SDL2/SDL.h> 

SDL_Point Projection::project_point(Vec3 point, float half_width, float half_height,float fov){
    float z = (point.z == 0.0f) * 0.001f + (point.z != 0.0f) * point.z;
    float inv_z = fov / z;
    return {static_cast<int>(point.x * inv_z + half_width),
            static_cast<int>(point.y * inv_z + half_height)};
}
