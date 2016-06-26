#include "Game.hpp"
#include "Renderer.hpp"

#include <windows.h>

Game::Game()
{
	pRenderer	= NULL;
}

Game::~Game()
{
	delete pRenderer;
}

int	Game::Run()
{
	/*!
	*	Begin the execution of game.
	*	Will return 0 on success.
	*/

	if (pRenderer)
		return 0;

	pRenderer	= new Renderer();

	if (pRenderer->Init() == false)
	{
		//	renderer has failed to initialize
		MessageBox(0, TEXT("Failed to initialize SDL."), TEXT("Error"), MB_ICONERROR);

		return -1;
	}

	StartMessageHandler();

	return 0;
}

void Game::StartMessageHandler()
{
	/*!
	*	This is the main event loop.
	*	It handles all messages for main window.
	*	This function would return only at the end of the application.
	*/

	SDL_Event e;
	bool bQuitLoop		= false;

	while(true)
    {  
		if (SDL_PollEvent(&e))
		{
			switch(e.type)
			{  
				case SDL_KEYDOWN:
				{
					break;
				}

				case SDL_QUIT:
				{
					bQuitLoop	= true;
					break;
				}
			}
		}

		if (bQuitLoop)
		{
			break;
		}

		Sleep(10);
    }
}