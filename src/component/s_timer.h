// s_timer.h
// a timer

#ifndef S_TIMER_H
#define S_TIMER_H

#include "s_component_base.h"
#include <time.h>
#include <chrono>
#include <future>

namespace stapler_engine::component
{
	class DLLAPI_SE STimer :public SComponent
	{
	protected:
		void* callback_func_;
		std::chrono::duration<_Ref, _Period> dur_time_;
		std::future<void> task_;
		std::promise<bool> should_be_end_;

	protected:
		static bool thread_func(void(*callback));

	public:
		bool auto_restart_;

	protected:
		void set_callback(void(*callback));
		void set_length(_Ref);
		void start();
		void stop();

	public:
		STimer();
	};
}

#endif