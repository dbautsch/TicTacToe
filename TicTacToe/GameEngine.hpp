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

private:
	unsigned		uWidth;

	bool			bInProgress;

	GameStatesList	gameStatesList;


	void			InitGame();
};

#endif
