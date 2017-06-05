#pragma once
#include "GameType.h"
#include "BoardManager.h"
#include "PlayerType.h"
class GameManager
{
public:
	GameManager(GameType::GameParams);
	GameManager(){}
	~GameManager();
	BoardManager bm;
	PlayerPool pp;
	BaseInterface::ConsoleInterface ci = BaseInterface::ConsoleInterface(0);
private:
	void BoardFactory(Data::BoardType, GameType::GameParams);
	void BoardFactory(Data::BoardType);
	void SetSectors();
	void PlayerFactory(Data::PlayerOrder);
	void LaunchGameProcess();
	void SaveState();
};

class Game
{
public:
	void Open();
	void Save();
	void Make_move(char);
	void ShowStatus();
	void NextTurn();
	GameManager* game_manager;

};
class Command
{
public:
	virtual ~Command() {}
	virtual void Execute() = 0;
protected:
	Command(Game* p) : pgame(p) {}
	Game * pgame;

};

class CreateGameCommand : public Command
{
public:
	CreateGameCommand(Game * p) : Command(p) {}
	void Execute();
};

class OpenGameCommand : public Command
{
public:
	OpenGameCommand(Game * p) : Command(p) {}
	void Execute();
};

class SaveGameCommand : public Command
{
public:
	SaveGameCommand(Game * p) : Command(p) {}
	void Execute();
};

class MakeMoveCommand : public Command
{
public:
	MakeMoveCommand(Game * p) : Command(p) {}
	void Execute();
};

class UndoCommand : public Command
{
public:
	UndoCommand(Game * p) : Command(p) {}
	void Execute();
};
class GameMenuCommand : public Command
{
public:
	GameMenuCommand(Game * p) : Command(p) {}
	void Execute();
};
class NextTurnCommand : public Command
{
public:
	NextTurnCommand(Game * p) : Command(p) {}
	void Execute();
};
class ShowStatusCommand : public Command
{
public:
	ShowStatusCommand(Game * p) : Command(p) {}
	void Execute();
};


