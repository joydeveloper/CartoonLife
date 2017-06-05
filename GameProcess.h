#pragma once
class GameProcess
{
public:
	
	GameProcess() {}
	GameProcess(GameProcess const&) = delete;
	GameProcess& operator= (GameProcess const&) = delete;
	~GameProcess() {}
public:
	static GameProcess& getInstance()
	{

		static GameProcess instance;

		return instance;
	}
	Data::Rules rules;
	int ThrowBones();
	static bool Is_alive(PlayerType::Status*);
	static void SetPlayerPosition(PlayerType::Status*, int);
	static void ChangePlayer_BoneCount(PlayerType::Status*, int);
	static void ChangePlayer_BoneFaces(PlayerType::Status*, int);
	static void ChangePlayer_BonusValue(PlayerType::Status*, int);
	static void ChangePlayer_Energy(PlayerType::Status*, int);
	static void ChangePlayer_Health(PlayerType::Status*, int);
	static void ChangePlayer_Money(PlayerType::Status*, int);
	static void ChangePlayer_SkipTurn(PlayerType::Status*, bool);
	static bool Is_canmove(PlayerType::Status*, int);
	static bool Is_winner(PlayerType::Status*);
	//bool Is_turnover(PlayerType::Status*);
	static void ExecuteEvent(Game*);
	bool gameprocess;
	void NextPlayerTurn(GameManager &);
	void StartGame(GameManager &);

};
class PlayerActions
{
public:
	static void ThrowBones(Game*);
	//static void ExecuteEvent(Game* );
	static void GetRest(Game*);
	//	static GameProcess& gameprocess;
};

class ComputerActions
{
	void ComputerDeclaration();
	virtual void GetRest(Game*) = 0;
	virtual void ThrowBones(Game*) = 0;
public:
	// 1. Стандартизуйте основу алгоритма в шаблонном методе 
	//    базового класса
	void ExecuteSimple(Game*);

};

class ComputerPlayerActions : public ComputerActions
{
	//void GetRest(Game*);
	void ThrowBones(Game*);
	void GetRest(Game*);

};
 class PlayerEvents :public Visitor
{
public:
	//std::string value;
	int value;
	
	//PlayerEvents(){};
	//double value;
public:
	void Visit(White&ref);
	void Visit(Blue&ref);
	void Visit(Green&ref );
	void Visit(Yellow&ref );
	void Visit(Red&ref );
	void Visit(Black&ref);
	void Visit(Grey&ref);
	void a(PlayerType::Status*);
	//void Execute(Game*);
};

 


//template<typename TYPE, size_t COUNT>
//inline size_t lenof(TYPE(&)[COUNT]){ return COUNT; }
//class White;
//class Blue;
//class Green;
//class Yellow;
//class Red;
//class Black;
//class Grey;
//
//class Visitor{
//public:
//	virtual void visit(White&ref) = 0;
//	virtual void visit(Blue&ref) = 0;
//	virtual void visit(Green&ref) = 0;
//	virtual void visit(Yellow&ref) = 0;
//	virtual void visit(Red&ref) = 0;
//	virtual void visit(Black&ref) = 0;
//	virtual void visit(Grey&ref) = 0;
//
//};
//
//class Element{
//public:
//	virtual void accept(Visitor&v) = 0;
//};
//
//class White :public Element{
//public:
//	void accept(Visitor&v){ v.visit(*this); }
//};
//
//class Blue :public Element{
//public:
//	void accept(Visitor&v){ v.visit(*this); }
//};
//
//class Green :public Element{
//public:
//	void accept(Visitor&v){ v.visit(*this); }
//};
//class Yellow :public Element{
//public:
//	void accept(Visitor&v){ v.visit(*this); }
//};
//
//class Red :public Element{
//public:
//	void accept(Visitor&v){ v.visit(*this); }
//};
//
//class Black :public Element{
//public:
//	void accept(Visitor&v){ v.visit(*this); }
//};
//class Grey :public Element{
//public:
//	void accept(Visitor&v){ v.visit(*this); }
//};
//
//class GetType :public Visitor{
//public:
//	//std::string value;
//	int value;
//	//double value;
//public:
//	void visit(White&ref);
//	void visit(Blue&ref);
//	void visit(Green&ref);
//	void visit(Yellow&ref);
//	void visit(Red&ref);
//	void visit(Black&ref);
//	void visit(Grey&ref);
//	
//};
//
//
//
//
