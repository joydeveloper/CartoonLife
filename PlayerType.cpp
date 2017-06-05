#include "stdafx.h"
#include "PlayerType.h"
using namespace BaseInterface;

void PlayerType::ShowStatus()
{
	ShowMessage(this->status.bonecount);
	ShowMessage(this->status.bonefaces);
	ShowMessage(this->status.bonusvalue);
	ShowMessage(this->status.skipturn);
	ShowMessage(this->status.skipvalue);
	ShowMessage(this->status.lastsquare_id);
	ShowMessage(this->status.currentsquare_id);
	//ShowMessage(this->status.afterthrowsquare_id);
	ShowMessage(this->status.EN);
	ShowMessage(this->status.HP);
	ShowMessage(this->status.Money);
}
void PlayerType::ShowStatus(int s)
{
	std::cout << "Здоровье " << this->status.HP<< '\n';
	std::cout << "Энергия " << this->status.EN << '\n';
	std::cout << "Деньги " << this->status.Money << '\n';
	std::cout << "Текущая позиция " << this->status.currentsquare_id << '\n';

}

PlayerType* HumanPlayer::Clone()
{
	
	return new HumanPlayer(*this);


}

std::string  HumanPlayer::info()
{
	
	return name = "Человек";
}

PlayerType* ComputerPlayer::Clone()
{
	return new ComputerPlayer(*this);
}

std::string  ComputerPlayer::info()
{
	return name = "Компьютер";
}
PlayerType* NPC::Clone()
{
	return new NPC(*this);
}

std::string  NPC::info()
{
	return name = "Не управляемый игрок";
}
PlayerType* PrototypeFactory::createHuman()
{
	
		static HumanPlayer prototype;
		prototype.status.bonecount = 1;
		prototype.status.bonefaces = 6;
		prototype.status.bonusvalue = 0;
		prototype.status.skipturn = 0;
		prototype.status.skipvalue = 0;
	//	prototype.status.afterthrowsquare_id = 0;
		prototype.status.currentsquare_id = 0;
		prototype.status.EN = 50;
		prototype.status.HP = 100;
		prototype.status.lastsquare_id = 0;
		prototype.status.Money = 1000;
		return prototype.Clone();
	
}
PlayerType* PrototypeFactory::createComputer()
{

	static ComputerPlayer prototype;
	prototype.status.bonecount = 1;
	prototype.status.bonefaces = 6;
	prototype.status.bonusvalue = 0;
	prototype.status.skipturn = 0;
	prototype.status.skipvalue = 0;
	//prototype.status.afterthrowsquare_id = 0;
	prototype.status.currentsquare_id = 0;
	prototype.status.EN = 99;
	prototype.status.HP = 999;
	prototype.status.lastsquare_id = 0;
	prototype.status.Money = 9999;
	return prototype.Clone();

}
PlayerType* PrototypeFactory::createNPC()
{

	static NPC prototype;

	return prototype.Clone();

}

PlayerType* PlayerPool::AddToPool()
{
	for (size_t i = 0; i < m_pool.size(); ++i)
	{
		if (!m_pool[i].in_use)
		{
			m_pool[i].in_use = true; // переводим объект в список используемых
			return m_pool[i].instance;
		}
	}
	// если не нашли свободный объект, то расширяем пул
	PoolRecord record;
	PrototypeFactory pf;
	record.instance=pf.createComputer();
	record.in_use = true;

	m_pool.push_back(record);

	return record.instance;
}
std::queue<PlayerType*>  PlayerPool::CreateQueue(Data::PlayerOrder po)
{
	PrototypeFactory pf;
	for (int k = 0; k < po.playercount;k++)
		playerqueue.push(pf.createHuman());
	for (int k = 0; k < po.computer_player_count; k++)
		playerqueue.push(pf.createComputer());
	return playerqueue;

}

void PlayerPool::PlayersInfo()
{
	
	
	while (!playerqueue.empty())
	{
		ShowMessage(playerqueue.front()->info());
		playerqueue.front()->ShowStatus();
		playerqueue.pop();
	}

}
