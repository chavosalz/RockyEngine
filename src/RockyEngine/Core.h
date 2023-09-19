#pragma once

#ifdef RK_PLATFORM_WINDOWS
	#ifdef RK_BUILD_DLL
		#define ROCKY_API _declspec(dllexport)
	#else
		#define ROCKY_API _declspec(dllimport)
	#endif

#else
	#error Rocky only supports Windows!
#endif