#include "GameState.hpp"

#include "MPACK.hpp"

namespace Game
{
	GameState::GameState()
	{
	}

	GameState::~GameState()
	{
#ifdef ANDROID_PLATFORM
		MPACK::Global::pContext->pInputService->ClearLinks();
#elif 	defined(WINDOWS_PLATFORM)

#endif
	}
}
