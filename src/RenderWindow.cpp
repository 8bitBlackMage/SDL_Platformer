#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "RenderWindow.h"

RenderWindow::RenderWindow(const char* p_title, int p_width, int p_height):m_Window(nullptr),m_Render(nullptr)
{
 	m_Window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_width, p_height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
 	if(m_Window == nullptr)
 	{
 		std::cout <<"window has failed to init Error:" << SDL_GetError() << std::endl;
 	}
 	m_Render = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);
    m_renderTexture = SDL_CreateTexture(m_Render, SDL_PIXELFORMAT_UNKNOWN,  SDL_TEXTUREACCESS_TARGET, 640,480);
}


RenderWindow::~RenderWindow()
{
    SDL_DestroyRenderer(m_Render);
	SDL_DestroyWindow(m_Window);

}

SDL_Texture *RenderWindow::loadTexture(const char *p_filePath)
{
    SDL_Texture * ret = nullptr;

    ret = IMG_LoadTexture(m_Render, p_filePath);
    if(ret == nullptr)
    {
        std::cout << "Texture Load Failed Error:" << SDL_GetError() << std::endl;
    }
    return ret;
}

void RenderWindow::clear() {
    m_timer1 = SDL_GetTicks();
    SDL_SetRenderTarget(m_Render,m_renderTexture);
    SDL_RenderClear(m_Render);

}

void RenderWindow::render(TextureWrapper &p_Texture)
{
switch(p_Texture.kRenderType)
{
    case(SingleTexture):
    {
        SDL_RenderCopy(m_Render,
                       p_Texture.TexturePtr,
                       nullptr,
                       &p_Texture.destRect);
        break;
    }
    case(MultiTexture):
    {
        break;
    }
    default:
    SDL_assert( true);

}

}

void RenderWindow::display() {
    SDL_SetRenderTarget(m_Render, NULL);
    SDL_RenderCopy(m_Render ,m_renderTexture, nullptr, nullptr );
    SDL_RenderPresent(m_Render);
    m_timer2 = SDL_GetTicks();
    clampFPS();
}

void RenderWindow::PreserveAspectRatio() {

}
