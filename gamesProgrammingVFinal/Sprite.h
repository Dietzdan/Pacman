#pragma once
//sprite.h
#include "SDL.h"
#include <vector>
#include<iostream>
#include <memory>
#include <fstream>
#ifndef SPRITE_H
#define SPRITE_H



class Sprite
{
public:
	

	Sprite(float x, float y, float h, float w);
	Sprite();
	~Sprite();
	SDL_Rect Rect;
	SDL_Rect Source;
	std::vector<std::vector<float> > Postions;
	void fillPos(Sprite& spr);
	void FillPostions();
	double Angle;
	int Score;
	SDL_RendererFlip flip;
	float Speed = 4;
	SDL_Rect Wall;
};



#endif //sprite.h
