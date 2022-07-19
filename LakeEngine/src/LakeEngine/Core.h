#pragma once

#ifdef LE_PLATFORM_WINDOWS
	#ifdef LE_BUILD_DLL
		#define LAKE_ENGINE_API __declspec(dllexport)
	#else
		#define LAKE_ENGINE_API __declspec(dllimport)
	#endif // LE_BUILD_DLL
#else
	#error Windows support only
#endif // LE_PLATFORM_WINDOWS

#define BIT(x) (1 << x)