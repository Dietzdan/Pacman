#pragma once
//PInput.h

#ifndef PINPUT_H
#define PINPUT_H
#include"SDL.h"
#include"Sprite.h"
#include "_Update.h"
#include <iostream>
extern SDL_Renderer *renderer;
extern SDL_Window *window;
extern bool running;
extern std::vector<std::unique_ptr<Sprite>> spriteList;

class PInput {
public:
	bool Input();
	

};





#endif // PInput.h