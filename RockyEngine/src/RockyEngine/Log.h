#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"


namespace Rocky {

	class ROCKY_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger()
		{
			return s_CoreLogger;
		}

		inline static std::shared_ptr<spdlog::logger>& GetClientLogger()
		{
			return s_ClientLogger;
		}

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}


//Engine Log Macros
#define RK_CORE_FATAL(...) ::Rocky::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define RK_CORE_ERROR(...) ::Rocky::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RK_CORE_WARN(...) ::Rocky::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RK_CORE_INFO(...) ::Rocky::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RK_CORE_TRACE(...) ::Rocky::Log::GetCoreLogger()->trace(__VA_ARGS__)

//Client Log Macros
#define RK_FATAL(...) ::Rocky::Log::GetClientLogger()->critical(__VA_ARGS__)
#define RK_ERROR(...) ::Rocky::Log::GetClientLogger()->error(__VA_ARGS__)
#define RK_WARN(...) ::Rocky::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RK_INFO(...) ::Rocky::Log::GetClientLogger()->info(__VA_ARGS__)
#define RK_TRACE(...) ::Rocky::Log::GetClientLogger()->trace(__VA_ARGS__)
