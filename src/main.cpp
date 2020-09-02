#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include "RenderWindow.h"
#include "Entity.h"
#include "Events.h"
#include "TextureWrapper.h"
int main(int argv, char* args[])
{
	if(SDL_Init(SDL_INIT_VIDEO) > 0)
	{
		std::cout << "error: " << SDL_GetError() << std::endl;
		return -1;
	}
	if(!IMG_Init(IMG_INIT_PNG))
	{
	    std::cout << "error: " << SDL_GetError() << std::endl;
        return -1;
	}
	RenderWindow Game("game1", 640,480);
    EventHandling EventHandler(&Game);


    TextureWrapper  Quote(Game.loadTexture("res/Images/Quote.png"),0,0,32,32);
    SDL_Texture * TileSheet = Game.loadTexture("res/Images/tileset.png");
    std::vector<Entity>Entities;
    for(int y = 0; y < 15; y++)
    {

        {
            for(int x = 0; x < 20; x++)
            {
               // Entity quote(x * 32, y*32, TileSheet);
              //  Entities.push_back(quote);
            }
        }
    }

    while(EventHandler.keepWindowOpen())
    {
        //event handler
        EventHandler.handleEvents();
        Game.clear();
        //for(auto & entity : Entities)
        Game.render(Quote);
        Game.display();


    }
	SDL_Quit();

	return 0;	
}