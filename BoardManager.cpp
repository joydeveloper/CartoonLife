#include "stdafx.h"
#include "BoardManager.h"

using namespace BaseInterface;
BoardManager::BoardManager()
{
	Director dir;
	SprintBuilder s_builder;
	Parts *ra = dir.DeployParts(s_builder);
	//ShowMessage(ra->info());

}



BoardManager::BoardManager(GameType::GameParams gp)
{
	Director dir;
	SprintBuilder s_builder;
	parts = dir.DeployParts(s_builder, gp);
	sector_count = gp.gmode.black_count + gp.gmode.blue_count + gp.gmode.green_count + gp.gmode.grey_count + gp.gmode.red_count + gp.gmode.white_count + gp.gmode.yellow_count;
	s_builder.~SprintBuilder();
	BuildingBoard();
	ShufleBoard();
	///PrintBoard();
	bones = Bones(gp.gmode.bonefaces, gp.gmode.bonecount);

	//parts->~Parts();
}

BoardManager::~BoardManager()
{
}
void BoardManager::BuildingBoard()
{

	int boardid = 0;
	Board = std::vector<AbstractEntity*>(sector_count);
	do
	{
		for (int i = 0; i < parts->vBlue.size(); i++)
		{
			Board[boardid] = &(parts->vBlue[i]);
			boardid++;
		}
		for (int i = 0; i < parts->vGreen.size(); i++)
		{
			Board[boardid] = &(parts->vGreen[i]);
			boardid++;
		}
	
		for (int i = 0; i < parts->vRed.size(); i++)
		{
			Board[boardid] = &(parts->vRed[i]);
			boardid++;
		}
		for (int i = 0; i < parts->vYellow.size(); i++)
		{
			Board[boardid] = &(parts->vYellow[i]);
			boardid++;
		}

		for (int i = 0; i < parts->vBlack.size(); i++)
		{
			Board[boardid] = &(parts->vBlack[i]);
			boardid++;
		}
		for (int i = 0; i < parts->vGrey.size(); i++)
		{
			Board[boardid] = &(parts->vGrey[i]);
			boardid++;
		}
	} while (boardid < sector_count);
		//parts->~Parts();



}
void BoardManager::ShufleBoard()
{
	std::rand() % sector_count;
	std::srand(unsigned(std::time(0)));
	std::random_shuffle(Board.begin(), Board.end());

}
void BoardManager::PrintBoard()
{
	for (int i = 0; i < sector_count; i++)
		ShowMessage(Board[i]->info());
	//parts->~Parts();

}
std::string White::info()
{
	if (name != "") return name; else return "Есть работка";
};



std::string Blue::info()
{
	if (name != "") return name; else return "Штраф энергии";
};


std::string Green::info()

{
	if (name != "") return name; else return "Магазин";
};


std::string Yellow::info()

{
	if (name != "") return name; else return "Квест";
};


std::string Red::info()

{
	if (name != "") return name; else return "Штраф здоровья";
};


std::string Black::info()

{
	if (name != "") return name; else return "Вообще невезуха";
};


std::string Grey::info()
{
	if (name != "") return name; else return "Невезуха";
};

AbstractEntity *AbstractEntity::createObject(Object_ID id, std::string _name)
{

	AbstractEntity *p;
	switch (id)
	{
	case WhiteA:
		p = new White();
		p->SetName(_name);
		return p;
		break;
	case BlueA:
		p = new Blue();
		p->SetName(_name);
		p->SetID(1);
		return p;
		break;
	case GreenA:
		p = new Green();
		p->SetName(_name);
		p->id = 0;
		return p;
		break;
	case YellowA:
		p = new Yellow();
		p->SetName(_name);
		return p;
		break;
	case RedA:
		p = new Red();
		p->SetName(_name);
		return p;
		break;
	case BlackA:
		p = new Black();
		p->SetName(_name);
		return p;
		break;
	case GreyA:
		p = new Grey();
		p->SetName(_name);
		return p;
		break;
	default:
		return NULL;
		break;
	}
	delete[]p;
}
AbstractEntity *AbstractEntity::createObject(Object_ID id)
{
	switch (id)
	{
	case WhiteA:
		return new White();
		break;
	case BlueA:
		return new Blue();
		break;
	case GreenA:
		return new Green();
		break;
	case YellowA:
		return new Yellow();
		break;
	case RedA:
		return new Red();
		break;
	case BlackA:
		return new Black();
		break;
	case GreyA:
		return new Grey();
		break;
	default:
		return NULL;
		break;
	};
}
std::vector<std::string> Parts::info()
{
	std::vector<std::string> infovector;
	for (int i = 0; i < vWhite.size(); ++i)  infovector.push_back(vWhite[i].info());
	for (int i = 0; i < vBlue.size(); ++i)  infovector.push_back(vBlue[i].info());
	for (int i = 0; i < vGreen.size(); ++i)  infovector.push_back(vGreen[i].info());
	for (int i = 0; i < vYellow.size(); ++i)  infovector.push_back(vYellow[i].info());
	for (int i = 0; i < vRed.size(); ++i)  infovector.push_back(vRed[i].info());
	for (int i = 0; i < vBlack.size(); ++i)  infovector.push_back(vBlack[i].info());
	for (int i = 0; i < vGrey.size(); ++i)  infovector.push_back(vGrey[i].info());
	return infovector;
}
void SprintBuilder::createParts()
{
	p = new Parts;
};
void SprintBuilder::buildBlue()
{
	p->vBlue.push_back(Blue());
	
}
void SprintBuilder::buildGreen()
{
	p->vGreen.push_back(Green());
}
void SprintBuilder::buildYellow()
{
	p->vYellow.push_back(Yellow());
}
void SprintBuilder::buildRed()
{
	p->vRed.push_back(Red());
}
void SprintBuilder::buildBlack()
{
	p->vBlack.push_back(Black());
}
void SprintBuilder::buildGrey()
{
	p->vGrey.push_back(Grey());
}
////////////////////////////////////Create with count
void SprintBuilder::buildBlue(int count)
{
	for (int i = 0; i < count; i++)
		p->vBlue.push_back(Blue());
}
void SprintBuilder::buildGreen(int count)
{
	for (int i = 0; i < count; i++)
		p->vGreen.push_back(Green());
}
void SprintBuilder::buildYellow(int count)
{
	for (int i = 0; i < count; i++)
		p->vYellow.push_back(Yellow());
}
void SprintBuilder::buildRed(int count)
{
	for (int i = 0; i < count; i++)
		p->vRed.push_back(Red());
}
void SprintBuilder::buildBlack(int count)
{
	for (int i = 0; i < count; i++)
		p->vBlack.push_back(Black());
}
void SprintBuilder::buildGrey(int count)
{
	for (int i = 0; i < count; i++)
		p->vGrey.push_back(Grey());
}


Parts* Director::DeployParts(PartsBuilder & builder)
{
	builder.createParts();
	builder.buildWhite();
	builder.buildBlue();
	builder.buildGreen();
	builder.buildYellow();
	builder.buildRed();
	builder.buildBlack();
	builder.buildGrey();
	return(builder.getParts());
}

Parts* Director::DeployParts(PartsBuilder & builder, GameType::GameParams gp)
{
	builder.createParts();
	builder.buildWhite(gp.gmode.white_count);
	builder.buildBlue(gp.gmode.blue_count);
	builder.buildGreen(gp.gmode.green_count);
	builder.buildYellow(gp.gmode.yellow_count);
	builder.buildRed(gp.gmode.red_count);
	builder.buildBlack(gp.gmode.black_count);
	builder.buildGrey(gp.gmode.grey_count);
	return(builder.getParts());

}
Bones::Bones()
{
	bonecount = 1;
	bonefaces = 6;
}
Bones::Bones(int _bonefaces, int _bonecount)
{
	bonefaces = _bonefaces;
	bonecount = _bonecount;
}
int Bones::SetFaces(int _faces)
{

	bonefaces = _faces;
	return bonefaces;

}
int Bones::SetCount(int _count)
{

	bonecount = _count;
	return _count;

}
int Bones::ThrowBones()
{
	std::srand(unsigned(std::time(0)));
	return std::rand() % bonefaces*bonecount+1;
}