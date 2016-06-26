#include "Renderer.hpp"

#include <SDL.h>

Renderer::Renderer()
{
	pMainSurface	= NULL;
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
	pMainSurface	= SDL_SetVideoMode(800, 600, 0, SDL_HWSURFACE);

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
