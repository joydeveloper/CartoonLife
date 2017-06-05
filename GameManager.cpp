#include "stdafx.h"
#include "GameProcess.h"
using namespace BaseInterface;
GameManager::GameManager(GameType::GameParams gp)
{
	PlayerFactory(gp.porder);
	BoardFactory(Data::BoardType::line, gp);
	ci.SetCursor(20, 0);
	LaunchGameProcess();
}


GameManager::~GameManager()
{

}
void GameManager::BoardFactory(Data::BoardType bt)
{
	switch (bt)
	{
	case Data::line:
		BoardManager::BoardManager();
		break;
	case Data::circle:
		break;
	case Data::grid:
		break;
	default:
		break;
	}

};
void GameManager::BoardFactory(Data::BoardType bt, GameType::GameParams gp)
{
	switch (bt)
	{
	case Data::line:
		bm = BoardManager::BoardManager(gp);
		break;
	case Data::circle:
		break;
	case Data::grid:
		break;
	default:
		break;
	}

};
void GameManager::PlayerFactory(Data::PlayerOrder po)
{
	pp.CreateQueue(po);
	//	PlayerPool::CreateQueue(po);
}
void GameManager::LaunchGameProcess()
{

	GameProcess& _gameprocess = GameProcess::getInstance();
	Game game;
	game.game_manager = this;
	_gameprocess.StartGame(*game.game_manager);
	std::vector<Command*> v;
	std::string playertype;
	while (_gameprocess.gameprocess)
	{
		//pp.PlayersInfo();
		playertype = (typeid(*game.game_manager->pp.playerqueue.front()).name());
		if (playertype == "class HumanPlayer")
		{

			//game.game_manager->
			v.push_back(new ShowStatusCommand(&game));
			v.push_back(new GameMenuCommand(&game));
			v.push_back(new MakeMoveCommand(&game));
		}
		else
		{
			
			ComputerActions* c = &ComputerPlayerActions();
			c->ExecuteSimple(&game);
		}

		for (size_t i = 0; i < v.size(); ++i)
		{
			v[i]->Execute();
			
		}
		v.clear();
		
	}

}
void Game::Make_move(char _input)
{
	switch (_input)
	{
	case '1':

		PlayerActions::ThrowBones(this);
		break;
	case '2':PlayerActions::GetRest(this);
		break;
	
		break;
	default:
		break;
	}
}
void Game::NextTurn()
{
	std::string pname = game_manager->pp.playerqueue.front()->info();
	if (GameProcess::Is_alive(&game_manager->pp.playerqueue.front()->status))
	{
		game_manager->pp.playerqueue.push(game_manager->pp.playerqueue.front());
		game_manager->pp.playerqueue.pop();
	}
	else
	{
		game_manager->pp.playerqueue.pop();
		ShowMessage(pname,0);
		ShowMessage(" Умер");
		this->NextTurn();
	}
}
void Game::ShowStatus()
{

	this->game_manager->pp.playerqueue.front()->ShowStatus(0);
	if (this->game_manager->pp.playerqueue.front()->status.currentsquare_id == 0)
		ShowMessage("Старт");
	
}

void MakeMoveCommand::Execute() {


	char move = BaseInterface::GetInput_Keyboard();

	pgame->Make_move(move);
}
void NextTurnCommand::Execute()
{
	pgame->NextTurn();

}
void GameMenuCommand::Execute()
{

	Menu GameMenu;
	GameMenu.SetTitle("Выбор действия");
	GameMenu.AddItem("Бросить кости");
	GameMenu.AddItem("Отдохнуть");
	//GameMenu.AddItem("Показать статус");
	GameMenu.Show();
}

void ShowStatusCommand::Execute()
{
	pgame->ShowStatus();

}