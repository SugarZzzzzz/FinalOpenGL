//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2005 - 2017 Media Design School
//
// File Name	:	CLevel.cpp
// Description	:	main implementation for CLevel
// Author		:	Steven Zhao
// Mail 		:	steven.zha7447@mediadesign.school.nz
//

// Library Includes //
#include <vector>
// Local Includes //
#include "CPlayer.h"
#include "CEnemy.h"
#include "CInterface.h"
#include "TextLabel.h"
#include "CubeMap.h"
// This Includes //
#include "CLevel.h"
#include "Utils.h"

// Static Variables //

// Static Function Prototypes //

// Types //
using namespace std;

// Constructor //
CLevel::CLevel()
{

}

// Destructor //
CLevel::~CLevel()
{
	
}

void CLevel::addPlayer()
{
	//Creating Player
	CharacterSpr = make_shared<CPlayer>("Resources/player_character/character_idle_1.png", 0.0f, 0.0f, 1);
	CharacterSpr->init(2.0f, 10.0f);
	CharacterSpr->addFrame("Resources/player_character/character_jump_0.png");
	CharacterSpr->objPosition = { 0.0f,50.0f,0.0f };
	CharacterSpr->objScale = { 10.0f, 10.0f, 10.0f };
	SpritesAdd(CharacterSpr);
	v_CollisionObjects.push_back(CharacterSpr);
	CharacterSpr->iObjectType = CUtility::PLAYER;
}


void CLevel::addEnemy()
{
	std::shared_ptr<CEnemy>SlimeSpr = nullptr;
	int amount = 10;
	for (int i = 0; i < 20; i++)
	{
		SlimeSpr = make_shared<CEnemy>("Resources/enemies/slime0.png", 0.0f, 0.0f, 0);
		SlimeSpr->init(2.0f, 2.0f);
		SlimeSpr->objPosition = { 100.0f + i,(-100.0f + (20.0f * i)),0.0f };
		SlimeSpr->objScale = { 0.5f,0.5f,0.5f };
		SpritesAdd(SlimeSpr);
		v_Enemies.push_back(SlimeSpr);
		v_CollisionObjects.push_back(SlimeSpr);
		SlimeSpr->iObjectType = CUtility::ENEMY;
	}
	//Creating Obstacle
	std::shared_ptr<CSprite>Obstacle = make_shared<CSprite>("Resources/enemies/slime0.png", 0.0f, 0.0f, 0);
	Obstacle->objPosition = { 400.0f,0.0f,0.0f };
	Obstacle->objScale = { 1.0f,1.0f,1.0f };
	Obstacle->iObjectType = CUtility::IMOBIL_WALL;
	SpritesAdd(Obstacle);
	v_CollisionObjects.push_back(Obstacle);
	Obstacle = make_shared<CSprite>("Resources/enemies/slime0.png", 0.0f, 0.0f, 0);
	Obstacle->objPosition = { 420.0f,0.0f,0.0f };
	Obstacle->objScale = { 1.0f,1.0f,1.0f };
	Obstacle->iObjectType = CUtility::IMOBIL_WALL;
	SpritesAdd(Obstacle);
	v_CollisionObjects.push_back(Obstacle);

	Obstacle = make_shared<CSprite>("Resources/enemies/slime0.png", 0.0f, 0.0f, 0);
	Obstacle->objPosition = { -400.0f,0.0f,0.0f };
	Obstacle->objScale = { 1.0f,1.0f,1.0f };
	Obstacle->iObjectType = CUtility::IMOBIL_WALL;
	SpritesAdd(Obstacle);
	v_CollisionObjects.push_back(Obstacle);
	Obstacle = make_shared<CSprite>("Resources/enemies/slime0.png", 0.0f, 0.0f, 0);
	Obstacle->objPosition = { -420.0f,.0f,0.0f };
	Obstacle->objScale = { 1.0f,1.0f,1.0f };
	Obstacle->iObjectType = CUtility::IMOBIL_WALL;
	SpritesAdd(Obstacle);
	v_CollisionObjects.push_back(Obstacle);

	Obstacle = make_shared<CSprite>("Resources/enemies/slime0.png", 0.0f, 0.0f, 0);
	Obstacle->objPosition = { 0.0f,210.0f,0.0f };
	Obstacle->objScale = { 1.0f,1.0f,1.0f };
	Obstacle->iObjectType = CUtility::IMOBIL_WALL;
	SpritesAdd(Obstacle);
	v_CollisionObjects.push_back(Obstacle);
	Obstacle = make_shared<CSprite>("Resources/enemies/slime0.png", 0.0f, 0.0f, 0);
	Obstacle->objPosition = { 0.0f,190.0f,0.0f };
	Obstacle->objScale = { 1.0f,1.0f,1.0f };
	Obstacle->iObjectType = CUtility::IMOBIL_WALL;
	SpritesAdd(Obstacle);
	v_CollisionObjects.push_back(Obstacle);

	Obstacle = make_shared<CSprite>("Resources/enemies/slime0.png", 0.0f, 0.0f, 0);
	Obstacle->objPosition = { 0.0f,-190.0f,0.0f };
	Obstacle->objScale = { 1.0f,1.0f,1.0f };
	Obstacle->iObjectType = CUtility::IMOBIL_WALL;
	SpritesAdd(Obstacle);
	v_CollisionObjects.push_back(Obstacle);
	Obstacle = make_shared<CSprite>("Resources/enemies/slime0.png", 0.0f, 0.0f, 0);
	Obstacle->objPosition = { 0.0f,-210.0f,0.0f };
	Obstacle->objScale = { 1.0f,1.0f,1.0f };
	Obstacle->iObjectType = CUtility::IMOBIL_WALL;
	SpritesAdd(Obstacle);
	v_CollisionObjects.push_back(Obstacle);
}

void CLevel::addLevel()
{
	std::shared_ptr<CSprite>Point1 = make_shared<CSprite>("Resources/entrance.png", 0.0f, 0.0f, 0);;
	Point1->objPosition = { 400.0f, 200.0f, 0.0f };
	Point1->objScale = { 1.0f,1.0f,1.0f };
	SpritesAdd(Point1);
	std::shared_ptr<CSprite>Point2 = make_shared<CSprite>("Resources/entrance.png", 0.0f, 0.0f, 0);;
	Point2->objPosition = { -400.0f, 200.0f, 0.0f };
	Point2->objScale = { 1.0f,1.0f,1.0f };
	SpritesAdd(Point2);
	std::shared_ptr<CSprite>Point3 = make_shared<CSprite>("Resources/entrance.png", 0.0f, 0.0f, 0);;
	Point3->objPosition = { -400.0f, -200.0f, 0.0f };
	Point3->objScale = { 1.0f,1.0f,1.0f };
	SpritesAdd(Point3);
	std::shared_ptr<CSprite>Point4 = make_shared<CSprite>("Resources/entrance.png", 0.0f, 0.0f, 0);;
	Point4->objPosition = { 400.0f, -200.0f, 0.0f };
	Point4->objScale = { 1.0f,1.0f,1.0f };
	SpritesAdd(Point4);
	std::shared_ptr<CSprite>Point5 = make_shared<CSprite>("Resources/entrance.png", 0.0f, 0.0f, 0);;
	Point5->objPosition = { 0.0f, 0.0f, 0.0f };
	Point5->objScale = { 1.0f,1.0f,1.0f };
	SpritesAdd(Point5);


	std::shared_ptr<CSprite>BackGroundSpr = make_shared<CSprite>("Resources/dungeon.png", Utility::SCR_WIDTH, Utility::SCR_HEIGHT, 0);
	//std::shared_ptr<CSprite>EntranceSpr = make_shared<CSprite>("Resources/entrance.png", 0.0, 0.0, 0);
	//std::shared_ptr<CSprite>ExitSpr = make_shared<CSprite>("Resources/exit.png", 0.0, 0.0 , 0);
	//EndSpr = ExitSpr;
	BackGroundSpr->objPosition = { 0.0f, 0.0f, -200.0f };
	//BackGroundSpr->objScale = { 30.0f, 30.0f, 30.0f };
	//BackGroundSpr->objScale = { 5.0f,2.5f,1.0f};
	//EntranceSpr->objPosition = { -550.0f, -195.0f, 1.0f };
	//ExitSpr->objPosition = { 550.0f,-195.0f,1.0f };
	SpritesAdd(BackGroundSpr);
	//SpritesAdd(EntranceSpr);
	//SpritesAdd(ExitSpr);
}

void CLevel::addMenu()
{
	std::shared_ptr<CSprite> MenuSpr = make_shared<CSprite>("Resources/start0.png", 0.0, 0.0, 0);
	MenuSpr->objPosition = { 0.0f, 0.0f, 0.0f };

	SpritesAdd(MenuSpr);

}

void CLevel::addCubeMap()
{
	std::vector<std::string> cubemapPaths =
	{
		"right.jpg",
		"left.jpg",
		"top.jpg",
		"bottom.jpg",
		"back.jpg",
		"front.jpg"
	};
	m_cubemap = new CCubeMap(cubemapPaths);
	m_cubemap->objScale = { 10000.0f,10000.0f,10000.0f };
	m_cubemap->objRotate = { 90.0f, 0.0f, 0.0f };
}

void CLevel::addEndMenu()
{
	std::shared_ptr<CSprite> EndSpr = make_shared<CSprite>("Resources/dungeon.png", Utility::SCR_WIDTH, Utility::SCR_HEIGHT, 0);
	SpritesAdd(EndSpr);
}

void CLevel::render()
{
	m_cubemap->render();

	CScene::render();
}

void CLevel::update()
{
	CScene::update();

	if (CharacterSpr != nullptr)
	{
		for (auto it : v_Enemies)
		{
			if (CharacterSpr != nullptr)
			{
				it->update(*CharacterSpr, &v_CollisionObjects);
			}
		}
	}
	/*
	if (CControls::GetInstance()->cKeyState[32] == CControls::INPUT_FIRST_PRESSED && (abs(CharacterSpr->objPosition.x - EndSpr->objPosition.x) < 30) && abs(CharacterSpr->objPosition.y - EndSpr->objPosition.y) < 30 && v_Enemies.empty())
	{
		resetLevel();
		CSceneManager::GetInstance()->switchScene(CSceneManager::END);
	}*/
}

void CLevel::resetLevel()
{
	if (!v_Enemies.empty())
	{
		for (auto it : v_Enemies)
		{
			delEnemy(it);
		}
		
	}
	addEnemy();
	DeleteSprite(CharacterSpr);
	addPlayer();
	nScore = 0;

}

void CLevel::delEnemy(std::shared_ptr<CEnemy>TobeDeleted)
{
	for (auto it = v_Enemies.begin(); it != v_Enemies.end(); it++)
	{
		if ((*it) == TobeDeleted)
		{
			v_Enemies.erase(it);
			DeleteSprite(TobeDeleted);
			break;
		}

	}
}

