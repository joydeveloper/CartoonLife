#pragma once

class GameType
{
	
public:
	GameType(){};
	virtual  ~GameType(){};
	struct GameParams
	{
		Data::Mode gmode;
		Data::COption goption;
		Data::PlayerOrder porder;
	};
	virtual GameParams StartGame(Data::Mode, Data::COption, Data::PlayerOrder);

	
};
class SprintMode :
	public GameType
{
public:
	//SprintMode(){};
	
	GameParams StartGame(Data::Mode, Data::COption, Data::PlayerOrder);
	
};
class THMode :
	public GameType
{
public:
	//THMode(){};

	GameParams StartGame(Data::Mode, Data::COption, Data::PlayerOrder);
	
};


