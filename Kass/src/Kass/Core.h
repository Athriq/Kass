#pragma once

#ifdef KSS_PLATFORM_WINDOWS
	#ifdef KSS_BUILD_DLL
		#define KASS_API __declspec(dllexport)
	#else
		#define KASS_API __declspec(dllimport)
	#endif
#else
	#error Kass only support Windows!
#endif