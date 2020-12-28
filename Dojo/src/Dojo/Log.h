#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Dojo
{
	class DOJO_API Log
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

// CORE LOG MACROS
#define DOJO_CORE_TRACE(...)    ::Dojo::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define DOJO_CORE_INFO(...)     ::Dojo::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DOJO_CORE_WARN(...)     ::Dojo::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define DOJO_CORE_ERROR(...)    ::Dojo::Log::GetCoreLogger()->error(__VA_ARGS__)
#define DOJO_CORE_CRITICAL(...) ::Dojo::Log::GetCoreLogger()->critical(__VA_ARGS__)

// CLIENT LOG MACROS
#define DOJO_TRACE(...)     ::Dojo::Log::GetClientLogger()->trace(__VA_ARGS__)
#define DOJO_INFO(...)      ::Dojo::Log::GetClientLogger()->info(__VA_ARGS__)
#define DOJO_WARN(...)      ::Dojo::Log::GetClientLogger()->warn(__VA_ARGS__)
#define DOJO_ERROR(...)     ::Dojo::Log::GetClientLogger()->error(__VA_ARGS__)
#define DOJO_CRITICAL(...)  ::Dojo::Log::GetClientLogger()->critical(__VA_ARGS__)