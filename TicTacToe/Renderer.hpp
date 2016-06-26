#ifndef RENDERER_HPP_INCLUDED
#define RENDERER_HPP_INCLUDED

struct SDL_Surface;

class Renderer
{
public:
						Renderer();

						~Renderer();

	bool				Init();

private:
	SDL_Surface		*	pMainSurface;


	void				Finish();
};

#endif
