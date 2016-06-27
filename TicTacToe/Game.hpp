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

#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include <SDL.h>

#include "GameDefs.hpp"

class Renderer;

class Game
{
public:
						Game();

						~Game();

	int					Run();

private:
	friend class Renderer;

	Renderer		*	pRenderer;

	EGameBoard			state;


	void				StartMessageHandler();

	void				ChangeGameState(EGameBoard state);
	
};

#endif
