#include "Events.h"

EventHandling::EventHandling(RenderWindow *p_Win):m_window(p_Win)
{
    ContinueRunning = true;
}




void EventHandling::handleEvents() {
    SDL_PollEvent(&m_event);
    switch(m_event.type) {
        case(SDL_WINDOWEVENT):
            handleWindowEvents();
            break;

        case(SDL_KEYDOWN):
        case(SDL_KEYUP):
            handleKeyboardEvents();
            break;

        case(SDL_JOYAXISMOTION):
        case(SDL_JOYBALLMOTION):
        case(SDL_JOYBUTTONDOWN):
        case(SDL_JOYBUTTONUP):
        case(SDL_JOYDEVICEADDED):
        case(SDL_JOYDEVICEREMOVED):
        case(SDL_JOYHATMOTION):
            handleGamepadEvents();
            break;

        case(SDL_QUIT):
            ContinueRunning = false;
            break;
    }
}

void EventHandling::handleWindowEvents() {
    switch(m_event.type)
    {
        case(SDL_WINDOWEVENT_RESIZED):

            break;
    }
}

void EventHandling::handleKeyboardEvents() {

}

void EventHandling::handleGamepadEvents() {
    switch(m_event.type)
    {
 
    }
}
