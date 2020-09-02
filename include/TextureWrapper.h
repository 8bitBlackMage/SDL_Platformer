#pragma once
#include "SDL2/SDL.h"

//this is a wrapper struct around a SDL_texture, holding data for processing textures in spritesheets such as tilesets and animation sheets



enum Rendertype
{
    SingleTexture,
    MultiTexture
};

struct TextureWrapper
{
    TextureWrapper()
    {

    }
    TextureWrapper(SDL_Texture* p_TexPtr, int p_xpos, int p_ypos, int p_height, int p_width ):TexturePtr(p_TexPtr),
    destRect(SDL_Rect{p_xpos,p_ypos,p_height,p_width}),
    kRenderType(SingleTexture)
    {}
    TextureWrapper(SDL_Texture* p_TexPtr, int p_xpos, int p_ypos):TexturePtr(p_TexPtr),
    kRenderType(SingleTexture)
    {
        destRect.x = p_xpos;
        destRect.y = p_ypos;

        SDL_QueryTexture(p_TexPtr,NULL, NULL, &destRect.w, &destRect.h);
    }

    TextureWrapper(SDL_Texture* p_TexPtr, SDL_Rect p_TexturePortion, int p_xpos, int p_ypos):TexturePtr(p_TexPtr),
    srcRect(p_TexturePortion),
    kRenderType(MultiTexture)
    {
        destRect.x = p_xpos;
        destRect.y = p_ypos;
        SDL_QueryTexture(TexturePtr,NULL,NULL,&destRect.w,&destRect.h );
    }

    TextureWrapper(SDL_Texture* p_TexPtr, int p_TextureportionX, int p_TextureportionY, int p_TextureportionH, int p_TextureportionW  ,int p_xpos, int p_ypos):
    TexturePtr(p_TexPtr),
    srcRect(SDL_Rect{p_TextureportionX,p_TextureportionY,p_TextureportionW,p_TextureportionH }),
    destRect(SDL_Rect{p_xpos,p_ypos,p_TextureportionW,p_TextureportionH }),
    kRenderType(MultiTexture)
    {

    }


SDL_Texture* TexturePtr;
SDL_Rect srcRect;
SDL_Rect destRect;
Rendertype kRenderType;

};
