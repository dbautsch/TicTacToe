#include "EngineHelpers.hpp"

#include <SDL_Image.h>

using namespace std;

namespace EngineHelpers
{
	SDL_Surface	* EngineHelpers::Load_PNG_Picture(const string & strFileName)
	{
		SDL_Surface * pRET		= NULL;
		SDL_RWops * pRW			= SDL_RWFromFile(strFileName.c_str(), "rb");

		if (pRW == NULL)
			return NULL;

		if (IMG_isPNG(pRW) == 0)
		{
			pRW->close(pRW);

			return NULL;
		}

		pRET					= IMG_LoadPNG_RW(pRW);

		pRW->close(pRW);

		return pRET;
	}

};	//	namespace EngineHelpers
