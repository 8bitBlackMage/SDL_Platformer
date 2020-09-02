#include <SDL2/SDL.h>
#include "Entity.h"


Entity::Entity(float p_X, float p_Y, TextureWrapper p_Tex) :
m_Xpos(p_X),m_Ypos(p_Y),m_Texture(p_Tex)
{

}

Entity::~Entity()
{
    //leave empty for now
}

void Entity::Update()
{

}
