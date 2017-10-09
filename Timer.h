#ifndef TIMER_H
#define TIMER_H
#include <SDL.h>
#include <chrono>
using namespace std::chrono;

class Timer {
	time_point<high_resolution_clock>timePrev;
	uint32_t last_tick;
	uint32_t delta;
public:
	Timer() : timePrev(high_resolution_clock::now()), last_tick(0), delta(0) {}

	double getDelta() {
		auto timeCurrent = high_resolution_clock::now();
		duration<double>delta(timeCurrent - timePrev);
		timePrev = high_resolution_clock::now();
		return delta.count();
	}

	uint32_t tick() {
		uint32_t tick_time = SDL_GetTicks();
		delta = tick_time - last_tick;
		last_tick = tick_time;
		return delta;
	}
};
#endif
