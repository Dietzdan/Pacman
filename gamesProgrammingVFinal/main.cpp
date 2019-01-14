#include <iostream>
#include "SDL.h"
#include <chrono> 
#include <memory>
#include <fstream>
#include "Render.h"
#include "Sprite.h"
#include "_Update.h"
#include "PInput.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include "GameState.h"

#define SHAPE_SIZE 100

//GLOBAL VARIABLES 
SDL_Window *window;
SDL_Renderer *renderer;
std::vector<std::unique_ptr<Sprite>> spriteList;
std::vector<std::unique_ptr<Sprite>> EnemyList;
std::vector<std::unique_ptr<Sprite>> DotList;
std::vector<std::unique_ptr<Sprite>> WallList;
const int Map_X = 20;
const int Map_Y = 19;
int Mapdata[Map_Y][Map_X];

bool running = false;




int main(int argc, char* argv[])
{	

	Render r;
	SDL_CreateWindowAndRenderer(640,800 , SDL_WINDOW_RESIZABLE, &window, &renderer);
	SDL_SetWindowTitle(window, "Daniel Dietzman DIE15561178 Games Programming");
	SDL_Surface *image = IMG_Load("assets\\pacman.png");
	
	if (TTF_Init() == -1)
	{
		std::cout << "probelm loading TTF" << std::endl;

	}
	else
	{
		std::cout << "TTF ok" << std::endl;
	}
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 1, 4096) == -1) {
		SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION,
			"SDL_mixer init error: %s\n   PERHAPS NO HEADPHONES/SPEAKERS CONNECTED\n", Mix_GetError());
		return 1;
	}
	SDL_Log("SDL_mixer initialised OK!\n");
	
	if (image == NULL) {
		std::cout << "cant find the image" << std::endl;

	}
	else
	{
		std::cout << "Image loaded" << std::endl;
	}
	SDL_Texture *text = SDL_CreateTextureFromSurface(renderer, image);
	if (text == NULL)
	{
		std::cout << "texture not loaded" << std::endl;
		
	}
	else
	{
		std::cout << "texture loaded" << std::endl;
	}
	
	// calling in the textfile to make a map
	std::ifstream File ("assets//map.txt");
	int Mapdata[Map_Y][Map_X];
	for (int y = 0; y < Map_Y; y++)
	{
		for (int x = 0; x < Map_X; x++)
		{
			File >> Mapdata[y][x];
			
		}
	}

	
	
	SDL_Surface *Tile = IMG_Load("assets\\Wall.png");
	if (Tile == NULL) {
		std::cout << "cant find the image" << std::endl;
	}
	else
	{
		std::cout << "Image loaded" << std::endl;
	}

	SDL_Texture *Tiletxt = SDL_CreateTextureFromSurface(renderer, Tile);
	if (Tiletxt == NULL)
	{
		std::cout << "texture not loaded" << std::endl;

	}
	else
	{
		std::cout << "texture loaded" << std::endl;
	}
	SDL_Surface *Dot = IMG_Load("assets\\Dot.png");
	if (Dot == NULL) {
		std::cout << "cant find the image" << std::endl;
	}
	else
	{
		std::cout << "Image loaded" << std::endl;
	}
	SDL_Texture *Dottxt = SDL_CreateTextureFromSurface(renderer, Dot);
	if (Dottxt == NULL) {
		std::cout << "Texture not loaded" << std::endl;
	}
	else
	{
		std::cout << "Texture Loaded" << std::endl;
	}

	Mix_Music *Background;
	Mix_Chunk *Pickup;

	Background = Mix_LoadMUS("assets\\backgroundmusic.ogg");
	if (Background == NULL)
	{
		std::cout << "Background Music not loaded" << std::endl;
	}
	else
	{
		std::cout << "Background music loaded" << std::endl;
	}

	Pickup = Mix_LoadWAV("assets\\pop.ogg");
	if (Pickup == NULL)
	{
		std::cout << "Pickup not loaded" << std::endl;
	}
	else
	{
		std::cout << "Pickup loaded" << std::endl;
	}
	TTF_Font* Fonts = TTF_OpenFont("assets\\hack.ttf", 24);
	if (Fonts == NULL)
	{
		std::cout << "Font not loaded" << std::endl;
	}
	else
	{
		std::cout << "Font loaded" << std::endl;
	}


	_Update up;
	PInput in;
	//population hero
	spriteList.push_back(std::unique_ptr<Sprite>(new Sprite(420,65,27,27)));
	//populating enemies
	EnemyList.push_back(std::unique_ptr<Sprite>(new Sprite(100, 300, 26, 26)));
	EnemyList.push_back(std::unique_ptr<Sprite>(new Sprite(100, 300, 26, 26)));
	EnemyList.push_back(std::unique_ptr<Sprite>(new Sprite(100, 300, 26, 26)));
	EnemyList.push_back(std::unique_ptr<Sprite>(new Sprite(100, 300, 26, 26)));
	
	for(int y = 0;y<19;y++)
	{
		for (int x = 0; x < 20; x++)
		{
			if (Mapdata[y][x] == 0)
			{
				DotList.push_back(std::unique_ptr<Sprite>(new Sprite(100, 300, 10, 10)));
			}
			if (Mapdata[y][x] == 1)
			{
				WallList.push_back(std::unique_ptr<Sprite>(new Sprite(100, 300, 10, 10)));
			}
		}
		
	}
	
	
	int Frame = 0;
	bool Any_collision;
	Sprite* Player = spriteList.at(0).get();

	GameState Game;
	int i = Game.ShowMenu(text, Fonts);
	if (i == 0)
	{
		running = false;
		SDL_Quit();
	}
	else
	{
		running = true;
	}
	Mix_PlayMusic(Background, -1);
	//bool running = true;
	while (running == true)
	{
		std::chrono::high_resolution_clock::time_point t1;
		t1 = std::chrono::high_resolution_clock::now();
		//old render function usinf sprite obj reference
		//r.rendererscreen(text, Spr);

		//rendering the map to screen
		r.rendermap(Mapdata, Tiletxt, Dottxt);

		//new render using sprite list 
		r.renderscreen(text);
		r.renderEnemy(text);
		r.renderScore(Fonts);
		//r.renderDots(Dottxt);
		up.Present();
		//up.ChangeVelocity(Spr);
		Frame = up.Animation(Frame);
		running = in.Input();
		running = up.EnemyCollision(text,running);
		up.DotCollision(Pickup);
		up.WallCollision();
		up.EnemyWallCollison();
		up.GhostExit0(Mapdata);
		up.GhostExit1(Mapdata);
		up.GhostExit2(Mapdata);
		up.GhostExit3(Mapdata);
		//time delay so i can tell how much time im actually using can be deleted
		//SDL_Delay(1);
		std::chrono::high_resolution_clock::time_point t2;
		t2 = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
		std::cout << "It took me " << time_span.count() << " seconds." << std::endl;
		if (Player->Score == 176)
		{
			running = r.Complete();
		}
		Frame++;
		
	}
		
	if (running == false)
	{
		SDL_Quit();
	}
	
	
	
	 return 0;


}
