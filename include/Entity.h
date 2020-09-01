#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Entity
{
public:
Entity(float p_X, float p_Y, SDL_Texture * p_Tex);
~Entity();

virtual void Update();

inline SDL_Texture* getTexture() {return m_Texture;}
inline float getXpos(){return m_Xpos;}
inline float getYpos(){return m_Ypos;}
private:
    float m_Xpos;
    float m_Ypos;
    SDL_Texture * m_Texture;
    SDL_Rect m_CurrentFrame;
};