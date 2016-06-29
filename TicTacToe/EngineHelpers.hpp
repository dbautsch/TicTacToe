#ifndef ENGINE_HELPERS_HPP_INCLUDED
#define ENGINE_HELPERS_HPP_INCLUDED

#include <string>
#include <SDL.h>

namespace EngineHelpers
{
	SDL_Surface		*	Load_PNG_Picture(const std::string & strFileName);
};

#endif
