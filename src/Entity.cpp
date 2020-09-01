#include <SDL2/SDL.h>
#include "Entity.h"


Entity::Entity(float p_X, float p_Y, SDL_Texture *p_Tex) :
m_Xpos(p_X),m_Ypos(p_Y),m_Texture(p_Tex), m_CurrentFrame({0,0,0,0})
{

}

Entity::~Entity()
{
    //leave empty for now
}

void Entity::Update()
{

}
