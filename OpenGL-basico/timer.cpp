#include "Timer.h"
Timer* Timer::instance = nullptr;
void Timer::init() { 
    if (Timer::instance == nullptr) {
        Timer::instance = new Timer();
	}
	

}


void Timer::start() {
    instance->started = true;
    instance->paused = false;
    instance->startTicks = SDL_GetTicks();
    instance->pausedTicks = 0;
}

void Timer::stop() {
    instance->started = false;
    instance->paused = false;
    instance->startTicks = 0;
    instance->pausedTicks = 0;
}

void Timer::pause() {
    if (instance->started && !instance->paused) {
        instance->paused = true;
        instance->pausedTicks = SDL_GetTicks() - instance->startTicks;
    }
}

void Timer::resume() {
    if (instance->started && instance->paused) {
        instance->paused = false;
        instance->startTicks = SDL_GetTicks() - instance->pausedTicks;
        instance->pausedTicks = 0;
    }
}

void Timer::reset() {
    instance->startTicks = 0;
    instance->pausedTicks = 0;
    instance->started = false;
    instance->paused = false;
}

Uint32 Timer::getTicks() {
    if (!instance->started) return 0;

    if (instance->paused) {
        return  instance->pausedTicks;
    }
    else {
        return SDL_GetTicks() - instance->startTicks;
    }
}

bool Timer::isStarted()  {
    return  instance->started;
}

bool Timer::isPaused()  {
    return  instance->paused && instance->started;
}

Uint32 Timer::getSeconds() 
{
    return getTicks() / 1000;
}

