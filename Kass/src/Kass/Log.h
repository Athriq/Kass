#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Kass {
	class KASS_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define KSS_CORE_TRACE(...)		::Kass::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define KSS_CORE_INFO(...)		::Kass::Log::GetCoreLogger()->info(__VA_ARGS__)
#define KSS_CORE_WARN(...)		::Kass::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define KSS_CORE_ERROR(...)		::Kass::Log::GetCoreLogger()->error(__VA_ARGS__)
#define KSS_CORE_FATAL(...)		::Kass::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define KSS_TRACE(...)			::Kass::Log::GetClientLogger()->trace(__VA_ARGS__)
#define KSS_INFO(...)			::Kass::Log::GetClientLogger()->info(__VA_ARGS__)
#define KSS_WARN(...)			::Kass::Log::GetClientLogger()->warn(__VA_ARGS__)
#define KSS_ERROR(...)			::Kass::Log::GetClientLogger()->error(__VA_ARGS__)
#define KSS_FATAL(...)			::Kass::Log::GetClientLogger()->fatal(__VA_ARGS__)