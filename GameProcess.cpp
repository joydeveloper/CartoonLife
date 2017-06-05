#include "stdafx.h"
#include "GameProcess.h"

using namespace BaseInterface;
void GameProcess::StartGame(GameManager  &gm)
{
	
	gameprocess = true;
	rules.die = 0;
	rules.slowpenalty = 0;
	rules.skipturn_bonus = 12;
	rules.win = gm.bm.sector_count;
	rules.black = 10;
	rules.blue = 10;
	rules.grey = 10;
	rules.red = 10;
	//std::cout << p_status->currentsquare_id;
	std::cout << "Игра началась" << '\n';
}
void GameProcess::SetPlayerPosition(PlayerType::Status* p_st, int value)
{

	p_st->lastsquare_id = p_st->currentsquare_id;
	p_st->currentsquare_id += value;

}
void ChangePlayer_BoneCount(PlayerType::Status* p_st, int value)
{
	p_st->bonecount += value;
}
void GameProcess::ChangePlayer_BoneFaces(PlayerType::Status* p_st, int value)
{
	p_st->bonefaces += value;
}
void GameProcess::ChangePlayer_BonusValue(PlayerType::Status* p_st, int value)
{

	p_st->bonusvalue += value;
}

void GameProcess::ChangePlayer_Energy(PlayerType::Status* p_st, int value)
{
	p_st->EN += value;
}
void GameProcess::ChangePlayer_Health(PlayerType::Status* p_st, int value)
{
	p_st->HP += value;
}
void GameProcess::ChangePlayer_Money(PlayerType::Status* p_st, int value)
{
	p_st->Money += value;
}
void GameProcess::ChangePlayer_SkipTurn(PlayerType::Status* p_st, bool value)
{
	p_st->skipturn = value;
}
bool GameProcess::Is_alive(PlayerType::Status* p_st)
{

	if (p_st->HP > GameProcess::getInstance().rules.die)
		return true;
	else
		return false;
}
bool GameProcess::Is_canmove(PlayerType::Status* p_st, int value)
{
	if (p_st->EN >= value)
		return true;
	else
		return false;

}
bool GameProcess::Is_winner(PlayerType::Status* p_st)
{

	if (p_st->currentsquare_id >= GameProcess::getInstance().rules.win)
		return true;
	else
		return false;

}
void  GameProcess::ExecuteEvent(Game* game)
{

	White white;
	Blue blue;
	Green green;
	Yellow yellow;
	Red red;
	Black black;
	Grey grey;

	PlayerEvents pe;

	Element*elements[] = { &white, &blue, &green, &yellow, &red, &black, &grey };

	int ty = (game->game_manager->bm.Board[game->game_manager->pp.playerqueue.front()->status.currentsquare_id]->id);
	switch (ty)
	{
	case WHITE_EVENT:elements[WHITE_EVENT]->accept(pe);

		break;
	case BLUE_EVENT:elements[BLUE_EVENT]->accept(pe);
		GameProcess::ChangePlayer_Energy(&game->game_manager->pp.playerqueue.front()->status, pe.value);
		break;
	case GREEN_EVENT:elements[GREEN_EVENT]->accept(pe);
		break;
	case YELLOW_EVENT:elements[YELLOW_EVENT]->accept(pe);
		break;
	case RED_EVENT:elements[RED_EVENT]->accept(pe);
		GameProcess::ChangePlayer_Health(&game->game_manager->pp.playerqueue.front()->status, pe.value);
		break;
	case BLACK_EVENT:elements[BLACK_EVENT]->accept(pe);
		GameProcess::ChangePlayer_Health(&game->game_manager->pp.playerqueue.front()->status, -game->game_manager->pp.playerqueue.front()->status.HP*pe.value / 100);
		GameProcess::ChangePlayer_Energy(&game->game_manager->pp.playerqueue.front()->status, -game->game_manager->pp.playerqueue.front()->status.EN*pe.value / 100);
		GameProcess::ChangePlayer_Money(&game->game_manager->pp.playerqueue.front()->status, -game->game_manager->pp.playerqueue.front()->status.Money*pe.value / 100);
		break;
	case GREY_EVENT:elements[GREY_EVENT]->accept(pe);
		GameProcess::ChangePlayer_Health(&game->game_manager->pp.playerqueue.front()->status, -game->game_manager->pp.playerqueue.front()->status.HP*pe.value / 100);
		break;
	}

}
void PlayerActions::ThrowBones(Game* game)
{

	int bones_value;

	bones_value = (game->game_manager->bm.bones.ThrowBones());
	ShowMessage(bones_value);
	if (GameProcess::Is_canmove(&game->game_manager->pp.playerqueue.front()->status, bones_value))
	{
		GameProcess::SetPlayerPosition(&game->game_manager->pp.playerqueue.front()->status, bones_value);
		GameProcess::ChangePlayer_Energy(&game->game_manager->pp.playerqueue.front()->status, -bones_value);
		if (GameProcess::Is_winner(&game->game_manager->pp.playerqueue.front()->status))
		{
			ShowMessage("Вы победили");
			GameProcess::getInstance().gameprocess = false;
		}
		else
			GameProcess::ExecuteEvent(game);
	}
	else
		ShowMessage("Не хватает энергии");
	Command* c = new NextTurnCommand(game);
	c->Execute();
}
void PlayerActions::GetRest(Game* game)
{
	GameProcess::ChangePlayer_Energy(&game->game_manager->pp.playerqueue.front()->status, GameProcess::getInstance().rules.skipturn_bonus);
	Command* c = new NextTurnCommand(game);
	c->Execute();
}


void ComputerPlayerActions::ThrowBones(Game* game)
{
	int bones_value;
	bones_value = (game->game_manager->bm.bones.ThrowBones());
	if (GameProcess::Is_canmove(&game->game_manager->pp.playerqueue.front()->status, bones_value))
	{
		GameProcess::SetPlayerPosition(&game->game_manager->pp.playerqueue.front()->status, bones_value);
		GameProcess::ChangePlayer_Energy(&game->game_manager->pp.playerqueue.front()->status, -bones_value);
		if (GameProcess::Is_winner(&game->game_manager->pp.playerqueue.front()->status))
		{
			ShowMessage("Компьютер выйграл");
			GameProcess::getInstance().gameprocess = false;
		}
		else
			GameProcess::ExecuteEvent(game);
	}
	else
		GetRest(game);
		//ShowMessage("Компьютеру не хватает энергии");
	Command* c = new NextTurnCommand(game);
	c->Execute();

};
void ComputerPlayerActions::GetRest(Game* game)
{
	GameProcess::ChangePlayer_Energy(&game->game_manager->pp.playerqueue.front()->status, GameProcess::getInstance().rules.skipturn_bonus);
	Command* c = new NextTurnCommand(game);
	c->Execute();

};
void ComputerActions::ExecuteSimple(Game* game)
{
	ComputerDeclaration();
	ThrowBones(game);

}
void ComputerActions::ComputerDeclaration()
{
	ShowMessage("Ход Компьютера...");
};
void PlayerEvents::Visit(White&ref)
{

	ShowMessage("Работа");
}
void PlayerEvents::Visit(Red&ref)
{
	
	std::srand(unsigned(std::time(0)));
	int x = std::rand() % 2;
	if (x == 0)
		value = GameProcess::getInstance().rules.red;
	else
		value = -GameProcess::getInstance().rules.red;
	

	ShowMessage("Здоровье");
}
void PlayerEvents::Visit(Blue&ref)
{
	std::srand(unsigned(std::time(0)));
	int x = std::rand() % 2;
	if (x == 0)
		value = GameProcess::getInstance().rules.blue;
	else
		value = -GameProcess::getInstance().rules.blue;
	
	ShowMessage("Энергия");
	
}

void PlayerEvents::Visit(Black&ref)
{
	value = GameProcess::getInstance().rules.black;
	ShowMessage("Всему минус");
}
void PlayerEvents::Visit(Grey&ref)
{
	value = GameProcess::getInstance().rules.grey;
	ShowMessage("Минус здоровье");
}
void PlayerEvents::Visit(Green&ref)
{
	

	ShowMessage("Пора покупок");
	Menu GameMenu;
	GameMenu.SetTitle("Деревенский магазин");
	GameMenu.AddItem("Топор");
	GameMenu.AddItem("Вилы");
	GameMenu.AddItem("Хлеб");
	GameMenu.AddItem("Пощипать доярку");

	//GameMenu.AddItem("Показать статус");
	GameMenu.Show();
	char x;
	std::cin >> x;
	switch (x)
	{
	case '1':
		ShowMessage("Топор куплен");
		break;
	case '2':ShowMessage("Вилы куплены");
		break;
	case '3':ShowMessage("Хлеб куплен");
		break;
	case '4':ShowMessage("Доярка улыбается");
		break;
	default:
		break;
	}
}
void PlayerEvents::Visit(Yellow&ref)
{
	std::srand(unsigned(std::time(0)));
	int x = std::rand() % 5;
	switch (x)
	{
	case 0:ShowMessage("Бригадир");
		break;
	case 1:ShowMessage("Кладбище");
		break;
	case 2:ShowMessage("Бабка");
		break;
	case 3:ShowMessage("Вонючая яма");
		break;
	case 4:ShowMessage("Убей Василия");
		break;

	}
	//ShowMessage("Интересная история");
}
void PlayerEvents::a(PlayerType::Status* p_st)
{


}
