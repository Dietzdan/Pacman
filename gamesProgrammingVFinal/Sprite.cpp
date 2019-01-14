#include "Sprite.h"

Sprite::Sprite(float x, float y, float h, float w)
{
	//have sprite postions on call the constructor  
	Rect.x = x;
	Rect.y = y;
	Rect.h = h;
	Rect.w = w;

	
	Source.x =540;
	Source.y = 170 ;
	Source.h = 165 ;
	Source.w =165 ;
	//setting angle and flip for later
	Angle = 0;
	flip = SDL_FLIP_NONE;
	Score = 0;
}

Sprite::Sprite()
{

}

Sprite::~Sprite()
{

}









