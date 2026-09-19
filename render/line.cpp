#include "../math/Vec3.hpp"
#include "line.hpp"
#include <SDL2/SDL.h> 
#include <cmath>
#include <chrono>
#include <vector>
#include "renderer.hpp"

void draw_line(int x1, int y1, int x2, int y2, int width, int height){
    if(x1 == x2){
        if(y1 > y2) std::swap(y1,y2);
        for(int y = y1; y <=y2; ++y){
            SDL_RenderDrawPoint(render::renderer,x1,y);
        }  
    }
    else{
        if(x1 > x2){
            std::swap(x1,x2);
            std::swap(y1,y2);
        }
        int ystep = (y2 >= y1) ? +1 : -1;
        int dx = abs(x2-x1), 
            dy = abs(y2-y1);
        int D = 2*dy - dx;
        int y = y1;
        for(int x = x1; x <= x2; ++x){
            SDL_RenderDrawPoint(render::renderer,x,y);
            if(D >= 0){
                y+=ystep;
                D = D+2*(dy-dx);
            }
            else{
                D = D + 2 * dy;
            }       
        }
    }
}
