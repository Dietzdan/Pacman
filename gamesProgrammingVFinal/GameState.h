#pragma once
//GameState.h
#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <vector>
#include <iostream>
#include "SDL.h"
#include "SDL_ttf.h"
#include "Render.h"
#include"_Update.h"
const int Menus = 4;
extern SDL_Renderer *renderer;
extern SDL_Window *window;
extern bool running;
//Menu class
class GameState 
{
public:

	int ShowMenu(SDL_Texture *text, TTF_Font* Font);
	
	const char* Labels[Menus] = { "Press Enter to Play", "Press Esc to Exit","PacMan","Control PacMan with the ArrowKeys"};
	SDL_Surface* MenuSurface[Menus];
	SDL_Texture* MenuText[Menus];
	bool SelectedMenu[Menus] = { 0,0 };
	int mouseX;
	int mouseY;
};

#endif // GameState.h