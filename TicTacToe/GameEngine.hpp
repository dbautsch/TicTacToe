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

#ifndef GAME_ENGINE_HPP_INCLUDED
#define GAME_ENGINE_HPP_INCLUDED

#include <vector>

enum EPlayer
{
	EP_NN,			//!<	player not set
	EP_Player1,		//!<	first player. It will be always a human
	EP_Player2		//!<	second player. Can be a human (multiplayer) or AI (computer).
};

typedef std :: vector < EPlayer >				GameStateColumnList;

typedef std :: vector < GameStateColumnList >	GameStatesList;

class GameEngine
{
public:
					GameEngine();

					~GameEngine();

	void			StartNewGame(unsigned uWidth);

	unsigned		GetCurrentGameWidth();

	bool			GameInProgress();

	EPlayer			GetGameState(unsigned uColumn, unsigned uRow);

	void			SetGameState(unsigned uColumn, unsigned uRow, EPlayer playerState);

    unsigned        Width();

private:
	unsigned		uWidth;

	bool			bInProgress;

	GameStatesList	gameStatesList;


	void			InitGame();
};

#endif
