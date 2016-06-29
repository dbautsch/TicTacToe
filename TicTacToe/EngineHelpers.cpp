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
