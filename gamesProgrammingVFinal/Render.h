#pragma once
//Render.h
#ifndef RENDER_H
#define RENDER_H
#include "SDL.h"
#include <iostream>
#include <vector>
#include <memory>
#include<string>
#include "Sprite.h"
#include "SDL_ttf.h"
extern SDL_Renderer *renderer;
extern std::vector<std::unique_ptr<Sprite>> spriteList;
extern std::vector<std::unique_ptr<Sprite>> EnemyList;
extern std::vector<std::unique_ptr<Sprite>> DotList;
extern std::vector<std::unique_ptr<Sprite>> WallList;
const int MapX = 20;
const int MapY = 20;
class Render{
public:
	int i;
	int j;
	SDL_Rect Tile;
	bool Start = true;
	bool GameOver();
	bool Complete();
	void rendererscreen(SDL_Texture *Text, Sprite Spr);
	void renderScore(TTF_Font* Font);
	void renderscreen(SDL_Texture *Text);
	void renderEnemy(SDL_Texture *Text);
	void renderWall(SDL_Texture *Text, int x, int y, int counter);
	void renderDots(SDL_Texture * Text,int x, int y,int counter);

	void rendermap(int Map[MapY][MapX],SDL_Texture *Tiletxt, SDL_Texture *Dot);
private:
};


#endif // Render.h