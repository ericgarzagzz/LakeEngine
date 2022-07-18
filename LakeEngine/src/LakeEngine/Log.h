#pragma once

#include <memory>
#include "Core.h"
#include <spdlog/spdlog.h>

namespace LakeEngine {
	class LAKE_ENGINE_API Log
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
#define LE_CORE_TRACE(...)    LakeEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LE_CORE_INFO(...)     LakeEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LE_CORE_WARN(...)     LakeEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LE_CORE_ERROR(...)    LakeEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LE_CORE_FATAL(...)    LakeEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define LE_TRACE(...)    LakeEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LE_INFO(...)     LakeEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define LE_WARN(...)     LakeEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LE_ERROR(...)    LakeEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define LE_FATAL(...)    LakeEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)