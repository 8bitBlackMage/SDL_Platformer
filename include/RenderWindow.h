#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
//header file for class that handles Render Window
#include "Entity.h"
class RenderWindow
{
public:
    RenderWindow(const char * p_title, int p_width, int p_height);
    ~RenderWindow();

//clears the buffer from previous frames data
    void clear();

//draws an entity to the screen
    void render(Entity &p_entity);

//swaps the GL buffers to update the screen
    void display();

    void PreserveAspectRatio();

//takes a char* path and loads a texture on the GPU
    SDL_Texture* loadTexture(const char * p_filePath);

    inline SDL_Window * getWindow(){return m_Window;}
private:
    void clampFPS()
    {
        uint32_t targetFrameTime = 1000/ (m_TargetFPS);
        uint32_t frameTime = m_timer2 - m_timer1;
        if((frameTime) < targetFrameTime)
        {
            SDL_Delay(targetFrameTime - frameTime);
        }

    }

    float calculatePillarBox(float p_Wres, float p_Hres)
    {



    }


    uint32_t m_timer1;
    uint32_t m_timer2;
    float m_TargetFPS = 60;
	SDL_Window * m_Window;
	SDL_Renderer * m_Render;
	SDL_Texture * m_renderTexture;
};