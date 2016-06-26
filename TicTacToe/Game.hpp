#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include "SDL.h"

class Renderer;

class Game
{
public:
						Game();

						~Game();

	int					Run();

private:
	Renderer		*	pRenderer;


	void				StartMessageHandler();
	
};

#endif
