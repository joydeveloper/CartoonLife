#include "stdafx.h"

GameType::GameParams GameType::StartGame(Data::Mode m, Data::COption c, Data::PlayerOrder)
{
	GameParams SprintParams;
	
	return SprintParams;
}

GameType::GameParams SprintMode::StartGame(Data::Mode m, Data::COption c,Data::PlayerOrder p)
{
	GameParams SprintParams;
	m.boardtype = Data::line;
	m.bonecount = 1;
	m.bonefaces = 6;
	m.black_count = 5;
	m.blue_count = 45;
	m.red_count = 40;
	m.green_count = 20;
	m.grey_count = 10;
	m.yellow_count = 12;
	p.computer_player_count =1;
	p.playercount = 1;
	p.players_max = 4;
	SprintParams.gmode = m;
	SprintParams.goption = c;
	SprintParams.porder = p;
	return SprintParams;
}




GameType::GameParams THMode::StartGame(Data::Mode m, Data::COption c, Data::PlayerOrder)
{
	GameParams THParams;
	//m.boardtype = Data::line;
	//m.bonecount = 1;
	//m.bonefaces = 6;
	//m.maxplayers = 4;
	//SprintParams.gmode = m;
	//SprintParams.goption = c;
	return THParams;

}


