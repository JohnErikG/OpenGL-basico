#include "Timer.h"

Timer::Timer()
    : startTicks(0), pausedTicks(0), started(false), paused(false) {
}

void Timer::start() {
    started = true;
    paused = false;
    startTicks = SDL_GetTicks();
    pausedTicks = 0;
}

void Timer::stop() {
    started = false;
    paused = false;
    startTicks = 0;
    pausedTicks = 0;
}

void Timer::pause() {
    if (started && !paused) {
        paused = true;
        pausedTicks = SDL_GetTicks() - startTicks;
        startTicks = 0;
    }
}

void Timer::resume() {
    if (started && paused) {
        paused = false;
        startTicks = SDL_GetTicks() - pausedTicks;
        pausedTicks = 0;
    }
}

void Timer::reset() {
    startTicks = 0;
    pausedTicks = 0;
    started = false;
    paused = false;
}

Uint32 Timer::getTicks() const {
    if (!started) return 0;

    if (paused) {
        return pausedTicks;
    }
    else {
        return SDL_GetTicks() - startTicks;
    }
}

bool Timer::isStarted() const {
    return started;
}

bool Timer::isPaused() const {
    return paused && started;
}

Uint32 Timer::getSeconds() const
{
    return getTicks() / 1000;
}

