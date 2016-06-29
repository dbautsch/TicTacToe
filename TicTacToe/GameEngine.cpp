#include "GameEngine.hpp"
#include "Exception.hpp"

GameEngine::GameEngine()
{
	uWidth		= 0;
	bInProgress	= false;
}

GameEngine::~GameEngine()
{

}

void GameEngine::StartNewGame(unsigned uWidth)
{
	if (GameInProgress())
	{
		throw Exception("Another instance of game is already running.");
	}

	InitGame();


	bInProgress	= true;
}

unsigned GameEngine::GetCurrentGameWidth()
{
	return uWidth;
}

bool GameEngine::GameInProgress()
{
	return bInProgress;
}

EPlayer GameEngine::GetGameState(unsigned uColumn, unsigned uRow)
{
	//!<	get game state at given row and column.
	//!<	It may throw an exception when coordinates are out of range.

	if (uRow >= gameStatesList.size())
	{
		throw Exception("GameEngine::GetGameState(): row index out of range.");
	}

	const GameStateColumnList & columnList = gameStatesList[uRow];

	if (uColumn >= columnList.size())
	{
		throw Exception("GameEngine::GetGameState(): column index out of range.");
	}

	return columnList[uColumn];
}

void GameEngine::SetGameState(unsigned uColumn, unsigned uRow, EPlayer playerState)
{
	//!<	Set the game state at given board coordinates.
	//!<	It may throw an exception when coordinates are out of range.

	if (uRow >= gameStatesList.size())
	{
		throw Exception("GameEngine::GetGameState(): row index out of range.");
	}

	GameStateColumnList & columnList	= gameStatesList[uRow];

	if (uColumn >= columnList.size())
	{
		throw Exception("GameEngine::GetGameState(): column index out of range.");
	}

	columnList[uColumn]					= playerState;
}

void GameEngine::InitGame()
{
	gameStatesList.clear();

	gameStatesList.reserve(uWidth);

	for (unsigned i = 0; i < gameStatesList.size(); ++i)
	{
		GameStateColumnList & columns	= gameStatesList[i];

		columns.reserve(uWidth);

		for (unsigned iColumn = 0; iColumn < columns.size(); ++iColumn)
		{
			columns[iColumn]			= EP_NN;
		}
	}
}
