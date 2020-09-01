#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include "RenderWindow.h"
#include "Entity.h"
#include "Events.h"
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


    SDL_Texture * Quote = Game.loadTexture("res/Images/Quote.png");
    std::vector<Entity>Entities;
    for(int y = 0; y < 15; y++)
    {

        {
            for(int x = 0; x < 20; x++)
            {
                Entity quote(x * 32, y*32, Quote);
                Entities.push_back(quote);
            }
        }
    }

    while(EventHandler.keepWindowOpen())
    {
        //event handler
        EventHandler.handleEvents();
        Game.clear();
        for(auto & entity : Entities)
            Game.render(entity);
        Game.display();


    }
	SDL_Quit();

	return 0;	
}