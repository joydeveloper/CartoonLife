#pragma once
//#include "AppInterface.h"
#include "GameType.h"
#include <ctime> 
#include "PlayerType.h"
#define WHITE_EVENT 0
#define BLUE_EVENT 1
#define GREEN_EVENT 2
#define YELLOW_EVENT 3
#define RED_EVENT 4
#define BLACK_EVENT 5
#define GREY_EVENT 6
class AbstractEntity
{
private:

public:
	enum Object_ID { WhiteA, BlueA, GreenA, YellowA, RedA, BlackA, GreyA };
	virtual std::string info() = 0;
	virtual ~AbstractEntity() {};
	int id;
	int GetID(){ return id; };
	void SetID(int _id){ id = _id; }
	std::string name;
	std::string GetName() { return name; };
	void SetName(std::string _name) { name = _name; }
	static AbstractEntity *createObject(Object_ID id, std::string _name);
	static AbstractEntity *createObject(Object_ID id);

};
template<typename TYPE, size_t COUNT>
inline size_t lenof(TYPE(&)[COUNT]){ return COUNT; }
class White;
class Blue;
class Green;
class Yellow;
class Red;
class Black;
class Grey;
class Visitor{
public:
	virtual void Visit(White&ref) = 0;
	virtual void Visit(Blue&ref) = 0;
	virtual void Visit(Green&ref) = 0;
	virtual void Visit(Yellow&ref) = 0;
	virtual void Visit(Red&ref) = 0;
	virtual void Visit(Black&ref) = 0;
	virtual void Visit(Grey&ref) = 0;
	virtual void a(PlayerType::Status*)=0;
};

class Element{
public:
	//virtual void accept(Visitor&v) = 0;
	virtual void accept(Visitor&v) = 0;
	//virtual void a(Visitor&v, PlayerType::Status*p) = 0;
};
class White : public AbstractEntity, public Element
{
public:
	void accept(Visitor&v){ v.Visit(*this); }
	White(){ SetID(0); }
	std::string info();
};
class Blue : public AbstractEntity, public Element
{
public:
	Blue(){ SetID(1);}
	void accept(Visitor&v){ v.Visit(*this); }
//	void a(Visitor&v, PlayerType::Status*p){ v.Visit(*this), p->currentsquare_id = 100; }
	std::string info();
};
class Green : public AbstractEntity, public Element
{
public:
	void accept(Visitor&v){ v.Visit(*this); }
	Green(){ SetID(2); }
	std::string info();
};
class Yellow : public AbstractEntity, public Element
{
public:
	void accept(Visitor&v){ v.Visit(*this); }
	Yellow(){ SetID(3); }
	std::string info();
};
class Red : public AbstractEntity, public Element
{
public:
	void accept(Visitor&v){ v.Visit(*this); }
	
	Red(){ SetID(4); }
	std::string info();
};
class Black : public AbstractEntity, public Element
{
public:
	void accept(Visitor&v){ v.Visit(*this); }
	int value;
	Black(){ SetID(5);  }
	std::string info();
};
class Grey : public AbstractEntity, public Element
{
public:
	void accept(Visitor&v){ v.Visit(*this); }
	int value;
	Grey(){ SetID(6);}
	std::string info();
};

class Parts
{
public:
	std::vector<White> vWhite;
	std::vector<Blue> vBlue;
	std::vector<Green> vGreen;
	std::vector<Yellow> vYellow;
	std::vector<Red> vRed;
	std::vector<Black> vBlack;
	std::vector<Grey> vGrey;
	std::vector<std::string> info();
	~Parts(){};
};
class PartsBuilder
{
protected:
	Parts* p;
public:
	PartsBuilder() : p(0) {}
	virtual ~PartsBuilder() {}
	virtual void createParts() {}
	virtual void buildWhite() {}
	virtual void buildBlue() {}
	virtual void buildGreen() {}
	virtual void buildYellow() {}
	virtual void buildRed() {}
	virtual void buildBlack() {}
	virtual void buildGrey() {}
	virtual void buildWhite(int){}
	virtual void buildBlue(int){}
	virtual void buildGreen(int){}
	virtual void buildYellow(int){}
	virtual void buildRed(int){}
	virtual void buildBlack(int){}
	virtual void buildGrey(int){}
	virtual Parts* getParts() { return p; }
};
class SprintBuilder : public PartsBuilder
{
public:
	virtual ~SprintBuilder() {}
	virtual void createParts();
	virtual void buildBlue();
	virtual void buildGreen();
	virtual void buildYellow();
	virtual void buildRed();
	virtual void buildBlack();
	virtual void buildGrey();
	virtual void buildBlue(int);
	virtual void buildGreen(int);
	virtual void buildYellow(int);
	virtual void buildRed(int);
	virtual void buildBlack(int);
	virtual void buildGrey(int);
};
class THBuilder : public PartsBuilder
{
public:
	void createParts();

};

class Director
{
public:
	Parts* DeployParts(PartsBuilder & builder);
	Parts* DeployParts(PartsBuilder & builder, GameType::GameParams);

};
class Bones
{

	int bonefaces;
	int bonecount;
	int Modificator();
public:
	int ThrowBones();
	int SetFaces(int);
	int SetCount(int);
	Bones();
	Bones(int, int);
};
class BoardManager
{
public:
	BoardManager();
	BoardManager(GameType::GameParams);
	std::vector<AbstractEntity*>Board;
	Bones bones;
	Parts* parts;
	void BuildingBoard();
	void ShufleBoard();
	void PrintBoard();
	~BoardManager();
	int sector_count;

};


