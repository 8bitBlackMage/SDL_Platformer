#pragma once

#include <memory>
#include "SDL2/SDL.h"
#include "RenderWindow.h"

class EventHandling
{
public:
    EventHandling(RenderWindow *p_window);
    void handleEvents();
    inline bool keepWindowOpen(){return ContinueRunning;}

private:
    SDL_Event m_event;
    bool ContinueRunning;
    RenderWindow* m_window;
    void handleWindowEvents();
    void handleKeyboardEvents();
    void handleGamepadEvents();


};

