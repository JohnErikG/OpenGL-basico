#pragma once

#include <SDL.h>

class Timer {
    static Timer* instance;
    double inicio;
    double startTicks;
    Uint32 pausedTicks = 0; // Initialize pausedTicks to resolve the warning
    bool started = false;
    bool paused = false;

    explicit Timer() : startTicks(SDL_GetTicks()), inicio(0), pausedTicks(0) {} // Ensure pausedTicks is initialized

public:
    static void init();
    static void start();
    static void stop();
    static void pause();
    static void resume();
    static void reset();

    static Uint32 getTicks();
    static bool isStarted();
    static bool isPaused();
    static Uint32 getSeconds();
};
