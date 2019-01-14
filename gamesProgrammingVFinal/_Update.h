#pragma once
//_Update.h
#ifndef UPDATE_H
#define UPDATE_H
#include"SDL.h"
#include<iostream>
#include "Sprite.h"
#include "Render.h"
#include "SDL_mixer.h"
extern SDL_Renderer *renderer;
extern std::vector<std::unique_ptr<Sprite>> spriteList;
extern std::vector<std::unique_ptr<Sprite>> EnemyList;
extern std::vector<std::unique_ptr<Sprite>> WallList;
class _Update {
public:
	int const Map_X = 20;
	int const Map_Y = 19;
	int counter = 0;
	int counter1 = 0;
	int counter2 = 0;
	int counter3 = 0;
	int timecounter = 5;
	int timecounter1 = 5;
	int timecounter2 = 5;
	int timecounter3= 5;
	void Present();
	int Animation(int Frame);
	void GhostExit0(int Map[MapY][MapX]);
	void GhostExit1(int Map[MapY][MapX]);
	void GhostExit2(int Map[MapY][MapX]);
	void GhostExit3(int Map[MapY][MapX]);
	void GhostMove(int Map[MapY][MapX],int Ghost);
	void GhostMove1(int Map[MapY][MapX], int Ghost);
	void GhostMove2(int Map[MapY][MapX], int Ghost);
	void GhostMove3(int Map[MapY][MapX], int Ghost);
	void WallCollision();
	void EnemyWallCollison();
	void EnemyWallCollisonResponse(Sprite& Ghost,Sprite& Wall);
	void WallcollisonResponse(Sprite* Player, Sprite& Wall);
	bool EnemyCollision(SDL_Texture* Pac,bool running);
	void DotCollision(Mix_Chunk *Pop);
	
	
};


#endif //_Update.h