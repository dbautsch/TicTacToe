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

#include "Renderer.hpp"
#include "Game.hpp"

#include <SDL.h>

Renderer::Renderer(Game * pGame)
{
	pMainSurface	= NULL;

	this->pGame		= pGame;
}

Renderer::~Renderer()
{
	Finish();
}

bool Renderer::Init()
{
	//	1.) initialize SDL library engine
	if((SDL_Init(SDL_INIT_VIDEO) < 0))
	{
		return false;
    }

	//	2.) create renderer window
	pMainSurface	= SDL_SetVideoMode(800, 600, 0, SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);

	if (pMainSurface == NULL)
	{
		//	SDL has failed to initialize window
		SDL_Quit();

		return false;
	}

	return true;
}

void Renderer::Finish()
{
	if (pMainSurface)
	{
		SDL_FreeSurface(pMainSurface);
	}

	SDL_Quit();
}

void Renderer::DrawBoard()
{
	/*!
	*	Draw current board.
	*/

	switch (pGame->state)
	{
	case EGB_Welcome:
		DrawWelcomeBoard();
		break;

	case EGB_Game:
		DrawGameBoard();
		break;
	}
}

void Renderer::Redraw()
{
	//!<	force renderer to redraw the entire screen (or window).

	DrawBoard();

	SDL_UpdateRect(pMainSurface, pMainSurface->clip_rect.w, pMainSurface->clip_rect.h, pMainSurface->clip_rect.x, pMainSurface->clip_rect.y);
	SDL_Flip(pMainSurface);
}

void Renderer::DrawWelcomeBoard()
{

}

void Renderer::DrawGameBoard()
{
	SDL_Rect rc;

	SDL_GetClipRect(pMainSurface, &rc);
	SDL_FillRect(pMainSurface, &rc, SDL_MapRGB(pMainSurface->format, 128, 128, 128));
}

void Renderer::OnResize(int iW, int iH)
{
	SDL_SetVideoMode(iW, iH, 0, SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);
	Redraw();
}
