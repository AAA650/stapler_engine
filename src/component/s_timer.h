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
	template<typename _Ref,typename _Period>
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

	template<typename _Ref, typename _Period>
	inline void STimer<_Ref, _Period>::set_callback(void(*callback))
	{
		callback_func_ = callback;
	}

	template<typename _Ref, typename _Period>
	inline void STimer<_Ref, _Period>::set_length(_Ref)
	{
	}

	template<typename _Ref, typename _Period>
	inline void STimer<_Ref, _Period>::start()
	{
		if (callback_func_ == nullptr)
			throw("STimer: No callback function inserted");
		//task_ = std::async(std::launch::async, thread_func, callback_func_);
	}

	template<typename _Ref, typename _Period>
	inline bool STimer<_Ref, _Period>::thread_func(void(*callback))
	{
		for (; !should_be_end_;) {
			for (;;) {

			}

			if (!auto_restart_)
				break;
		}
	}

	template<typename _Ref, typename _Period>
	inline STimer<_Ref, _Period>::STimer()
	{
		callback_func_ = nullptr;
		auto_restart_ = false;
		should_be_end_ = false;
	}
}

#endif