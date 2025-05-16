#pragma once


#include <SDL.h>

class Timer {
public:
    Timer();

    void start();
    void stop();
    void pause();
    void resume();
	void reset();
	
    Uint32 getTicks() const;
    bool isStarted() const;
    bool isPaused() const;
    Uint32 getSeconds() const;

private:
    Uint32 startTicks;
    Uint32 pausedTicks;

    bool started;
    bool paused;
};



