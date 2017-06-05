#pragma once
#include <queue>
//#include "AppInterface.h"
class PlayerType
{
public:
	virtual PlayerType* Clone() = 0;
	virtual std::string info() = 0;
	std::string name;
		struct Status
		{
			int bonusvalue;
			bool skipturn;
			int skipvalue;
			int bonecount;
			int bonefaces;
			int lastsquare_id;
			int currentsquare_id;
			//int afterthrowsquare_id;
			double HP;
			double EN;
			double Money;
		};
	public:
		
		Status status;
		void ShowStatus();
		void ShowStatus(int);
	private:
	//virtual ~PlayerType() {}
};


class HumanPlayer: public PlayerType
{
	friend class PrototypeFactory;
public:
	PlayerType* Clone();
	std::string info();
private:
	HumanPlayer() {}
};

class ComputerPlayer : public PlayerType
{
	friend class PrototypeFactory;
public:
	PlayerType* Clone();
	std::string info();
private:
	ComputerPlayer() {}
};

class NPC : public PlayerType
{
	friend class PrototypeFactory;
public:
	PlayerType* Clone();
	std::string  info();
private:
	NPC() {}
};

class PrototypeFactory
{
public:
	PlayerType* createHuman();
	PlayerType* createComputer();
	PlayerType* createNPC();
};
class PlayerPool
{
private:
	struct PoolRecord
	{
		PlayerType* instance;
		bool  in_use;
	};

	std::vector<PoolRecord> m_pool;
	
public:
	std::queue<PlayerType*> playerqueue;
	void PlayersInfo();
	std::queue<PlayerType*> CreateQueue(Data::PlayerOrder);
	PlayerType* AddToPool();
	
	//template<typename T>
	//Object* AddToPool(std::vector<T> _Objects)
	//{
	//	int i = 0;
	//	for each (T temp in _Objects)
	//	{
	//		if (!m_pool[i].in_use)
	//		{
	//			m_pool[i].in_use = true; // переводим объект в список используемых
	//			return m_pool[i].instance;
	//		}
	//		i++;
	//	}
	//}
	//void ReturnObject(Object* object)
	//{

	//	for (size_t i = 0; i < m_pool.size(); ++i)
	//	{
	//		if (m_pool[i].instance == object)
	//		{
	//			m_pool[i].in_use = false;
	//			break;
	//		}
	//	}
	//}
	//void GetObject(Object* object)
	//{

	//	for (size_t i = 0; i < m_pool.size(); ++i)
	//	{
	//		if (m_pool[i].instance == object)
	//		{
	//			m_pool[i].in_use = true;
	//			break;
	//		}
	//	}
	//}
	//virtual ~ObjectPool()
	//{
	//	// теперь уже "по-настоящему" удаляем объекты
	//	for (size_t i = 0; i < m_pool.size(); ++i)
	//		delete m_pool[i].instance;
	//}
	//int GetPoolSize()
	//{
	//	return m_pool.size();
	//}
};
