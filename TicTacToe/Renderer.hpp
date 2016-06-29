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

#ifndef RENDERER_HPP_INCLUDED
#define RENDERER_HPP_INCLUDED

#include <vector>

#include "GameDefs.hpp"
#include "RendererDefs.hpp"

struct SDL_Surface;

class Game;

class Renderer
{
public:
						Renderer(Game * pGame);

						~Renderer();

	bool				Init();

	void				Redraw();

	void				OnResize(int iW, int iH);

private:
	SDL_Surface		*	pMainSurface;

	Game			*	pGame;

	ImageList			player1_Pictures;

	ImageList			player2_Pictures;


	void				Finish();

	void				DrawBoard();

	void				DrawWelcomeBoard();

	void				DrawGameBoard();

	bool				LoadPictures();

	void				UnloadPictures();
};

#endif
