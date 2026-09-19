#pragma once
#include <SDL2/SDL.h>
#include "../math/Vec3.hpp"

namespace Projection{
    SDL_Point project_point(Vec3 point, float half_width, float half_height,float fov);
}