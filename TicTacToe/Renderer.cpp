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
