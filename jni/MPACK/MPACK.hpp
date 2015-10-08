#ifndef MPACK_HPP
#define MPACK_HPP

#include "Global.hpp"

#include "Algorithm.hpp"
#include "Core.hpp"
#include "Debug.hpp"
#include "Graphics.hpp"
#include "Input.hpp"
#include "Math.hpp"
#include "Physics.hpp"
#include "Resources.hpp"
#include "Sound.hpp"
#include "Time.hpp"
#include "Misc.hpp"

#define MPACK_FORCE_SEMICOLON \
	do \
	{ \
		\
	} while(0)

#define MPACK_ANDROID_MAIN	void android_main(android_app* MPACK_pApplication)
#define MPACK_ANDROID_RETURN(x)

#define MPACK_WINDOWS_MAIN	int WINAPI WinMain(HINSTANCE MPACK_hInstance,	\
                   HINSTANCE MPACK_hPrevInstance,							\
                   LPSTR MPACK_cmdLine,										\
                   int MPACK_cmdShow)
#define MPACK_WINDOWS_RETURN(x)	return x

#define MPACK_LINUX_MAIN	int main(int MPACK_argc, char *MPACK_argv[])
#define MPACK_LINUX_RETURN(x)	return x

#ifdef ANDROID_PLATFORM
	#define MPACK_MAIN	MPACK_ANDROID_MAIN
	#define MPACK_RETURN(x) MPACK_ANDROID_RETURN(x)
#elif 	defined(WINDOWS_PLATFORM)
	#define MPACK_MAIN	MPACK_WINDOWS_MAIN
	#define MPACK_RETURN(x) MPACK_WINDOWS_RETURN(x)
#elif	defined(LINUX_PLATFORM)
	#define MPACK_MAIN	MPACK_LINUX_MAIN
	#define MPACK_RETURN(x) MPACK_LINUX_RETURN(x)
#endif

#define MPACK_FILLGLOBALCONTEXT	\
	MPACK::Time::TimeService *MPACK_pTimeService = MPACK::Time::TimeService::Initialize(); \
    MPACK::Graphics::GraphicsService 	MPACK_lGraphicsService; \
    MPACK::Sound::SoundService 			MPACK_lSoundService; \
    MPACK::Input::InputService 			MPACK_lInputService; \
    MPACK::Core::Context MPACK_lContext={&MPACK_lGraphicsService, &MPACK_lInputService, &MPACK_lSoundService, MPACK_pTimeService}; \
    MPACK::Global::pContext = &MPACK_lContext

#ifdef ANDROID_PLATFORM
	#define MPACK_FILLGLOBAL \
		MPACK::Global::pAndroidApp=MPACK_pApplication;	\
		MPACK::Global::pAAssetManager=MPACK_pApplication->activity->assetManager; \
		MPACK_FILLGLOBALCONTEXT
#else
	#define MPACK_FILLGLOBAL \
		MPACK_FILLGLOBALCONTEXT
#endif

#if defined(ANDROID_PLATFORM) || defined(LINUX_PLATFORM)
	#define MPACK_INIT_EVENTLOOP_DATA void *MPACK_eventLoopData=NULL
#elif	defined(WINDOWS_PLATFORM)
	#define MPACK_INIT_EVENTLOOP_DATA void *MPACK_eventLoopData=(void*)(&MPACK_hInstance);
#endif

#define MPACK_RUN(pApp,result) \
	MPACK_INIT_EVENTLOOP_DATA; \
	MPACK::Global::pEventLoop=MPACK::Core::EventLoop::Initialize(MPACK_eventLoopData); \
    result = MPACK::Global::pEventLoop->Run(pApp)

#if defined(ANDROID_PLATFORM)
	#define MPACK_INIT_ARGV \
		MPACK_FORCE_SEMICOLON
#elif defined(LINUX_PLATFORM)
	#define MPACK_INIT_ARGV \
		for(int i=0;i<MPACK_argc;++i) \
		{ \
			MPACK::Global::arguments.push_back(std::string(MPACK_argv[i]));\
		} \
		MPACK_FORCE_SEMICOLON
#elif defined(WINDOWS_PLATFORM)
	#define MPACK_INIT_ARGV \
		LPWSTR *MPACK_szArgList; \
		int MPACK_argCount; \
		MPACK_szArgList = CommandLineToArgvW(GetCommandLine(), &MPACK_argCount); \
		if (MPACK_szArgList == NULL) \
		{ \
			return 1; \
		} \
		for(int i=0;i<MPACK_argCount;++i) \
		{ \
			MPACK::Global::arguments.push_back(std::string(MPACK_szArgList[i]));\
		} \
		LocalFree(MPACK_szArgList)
#endif

#define MPACK_INITIALIZE \
		MPACK_INIT_ARGV; \
		MPACK::Core::Log::Initialize(); \
		MPACK::Core::Random::Init(); \
		MPACK_FILLGLOBAL

#define MPACK_SHUTDOWN \
		MPACK::Core::Log::Destroy()
#endif
