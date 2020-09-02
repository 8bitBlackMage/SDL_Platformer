#pragma once
#include <SDL2/SDL.h>
#include "TextureWrapper.h"

class Entity
{
public:
Entity(float p_X, float p_Y, TextureWrapper p_Tex);
~Entity();

virtual void Update();

inline TextureWrapper getTexture() {return m_Texture;}
inline float getXpos(){return m_Xpos;}
inline float getYpos(){return m_Ypos;}
private:
    float m_Xpos;
    float m_Ypos;
    TextureWrapper m_Texture;

};