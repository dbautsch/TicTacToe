/*!
*	Copyright (c) 2016 Dawid Bautsch dawid.bautsch@gmail.com
*	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
*	EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
*	MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
*	NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
*	HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
*	IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
*	IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
*	THE SOFTWARE.
*/

#include "Game.hpp"
#include "Renderer.hpp"

#include <windows.h>
#include <SDL_Events.h>

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

	pRenderer	= new Renderer(this);

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

	//	the event queue is updated every 10 msecs, the game should
	//	run at average 100 fps.

	SDL_Event e;
	bool bQuitLoop		= false;

	ChangeGameState(EGB_Game);

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

				case SDL_VIDEORESIZE:
				{
					pRenderer->OnResize(e.resize.w, e.resize.h);
					pRenderer->Redraw();
					break;
				}

				case SDL_VIDEOEXPOSE:
				{
					pRenderer->Redraw();
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

void Game::ChangeGameState(EGameBoard board)
{
	state = board;

	pRenderer->Redraw();
}
