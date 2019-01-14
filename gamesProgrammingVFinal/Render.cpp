#include "Render.h"
#include <iostream>






bool Render::GameOver()
{
	bool running;
	SDL_Color color = { 255,255,0 };
	TTF_Font* Font = TTF_OpenFont("assets\\hack.ttf", 48);
	SDL_Surface* Surface = TTF_RenderText_Solid(Font, "GameOver", color);
	SDL_Texture* Text = SDL_CreateTextureFromSurface(renderer, Surface);
	
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, Text, NULL, NULL);
	SDL_RenderPresent(renderer);
	SDL_Delay(300);
	running = false;
	return running;
	
}

bool Render::Complete()
{
	bool running;
	SDL_Color color = { 255,255,0 };
	TTF_Font* Font = TTF_OpenFont("assets\\hack.ttf", 48);
	SDL_Surface* Surface = TTF_RenderText_Solid(Font, "You Win", color);
	SDL_Texture* Text = SDL_CreateTextureFromSurface(renderer, Surface);

	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, Text, NULL, NULL);
	SDL_RenderPresent(renderer);
	SDL_Delay(300);
	running = false;
	return running;

}

void Render::rendererscreen(SDL_Texture *Text, Sprite Spr)
{
	
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, Text, NULL, &Spr.Rect);
		

}

void Render::renderScore(TTF_Font * Font)
{
	Sprite* Player = spriteList.at(0).get();
	std::string s = std::to_string(Player->Score);
	const char* score = s.c_str();
	const char*  Label = "Score";
	SDL_Color color = { 255, 255, 255 };
	SDL_Surface* ScoreLabel = TTF_RenderText_Solid(Font,Label,color);
	SDL_Surface* Scorenum = TTF_RenderText_Solid(Font, score, color);
	SDL_Texture* Labeltxt = SDL_CreateTextureFromSurface(renderer, ScoreLabel);
	SDL_Texture* Numtxt = SDL_CreateTextureFromSurface(renderer, Scorenum);
	SDL_Rect LabelRect;
	LabelRect.x = 2 * 32;
	LabelRect.y = 20*32;
	LabelRect.h = 20;
	LabelRect.w = 40;
	SDL_Rect NumRect;
	NumRect.x = 4 * 32;
	NumRect.y = 20*32;
	NumRect.h = 20;
	NumRect.w = 20;

	SDL_RenderCopy(renderer, Labeltxt, NULL, &LabelRect);
	SDL_RenderCopy(renderer, Numtxt, NULL, &NumRect);
}

void Render::renderscreen(SDL_Texture * Text)
{
	
	Sprite *Player = spriteList.at(0).get();
	
	
		//new render that allows for angles and flips
		SDL_RenderCopyEx(renderer, Text, &Player->Source, &Player->Rect, Player->Angle, NULL, Player->flip);
	
}

void Render::renderEnemy(SDL_Texture * Text)
{
	for (auto const& Sprite : EnemyList)
	{

		SDL_RenderCopy(renderer, Text, &Sprite->Source, &Sprite->Rect);
	}
}

void Render::renderWall(SDL_Texture * Text, int x, int y, int counter)
{
	Sprite* Wall = WallList.at(counter).get();
	Wall->Rect.x = x * 32;
	Wall->Rect.y = y * 32;
	Wall->Rect.h = 31;
	Wall->Rect.w = 31;
	SDL_RenderCopy(renderer, Text, NULL, &Wall->Rect);
}
void Render::renderDots(SDL_Texture * Text,int x,int y,int counter)
{
	Sprite* Dot = DotList.at(counter).get();
	if (Dot != nullptr) 
	{
		Dot->Rect.x = x * 32;
		Dot->Rect.y = y * 32;
		Dot->Rect.y = Dot->Rect.y + 10;
		Dot->Rect.x = Dot->Rect.x + 10;
		SDL_RenderCopy(renderer, Text, NULL, &Dot->Rect);
	}
}

void Render::rendermap(int Map[MapY][MapX],SDL_Texture *Tiletxt,SDL_Texture *Dot)
{
	Sprite* Player = spriteList.at(0).get();
	Sprite* Inky = EnemyList.at(0).get();
	Sprite* Blinky = EnemyList.at(1).get();
	Sprite* Pinky = EnemyList.at(2).get();
	Sprite* Clyde = EnemyList.at(3).get();
	int dotcounter = 0;
	int wallcounter = 0;
	enum Tiles
	{
		OPEN, WALL,PLAYER,INKY,BLINKY,PINKY,CLYDE
	};
	for (int y = 0; y < MapY; y++)
	{
		for (int x = 0; x < MapX; x++)
		{
			if (Map[y][x] == OPEN && dotcounter<DotList.size())
			{
				
				renderDots(Dot, x, y, dotcounter);
				dotcounter++;
			}
			if (Map[y][x] == WALL)
			{
				renderWall(Tiletxt, x, y, wallcounter);
				wallcounter++;
			}
			if (Map[y][x] == PLAYER && Start == true)
			{
				Player->Rect.x = x * 32;
				Player->Rect.y = y * 32;
				
			}
			if (Map[y][x] == BLINKY && Start == true)
			{
				Blinky->Source.x = 0;
				Blinky->Source.y = 0;
				Blinky->Source.w = 135;
				Blinky->Rect.x = x * 32;
				Blinky->Rect.y = y * 32;
				
			}
			if (Map[y][x] == PINKY && Start == true)
			{
				Pinky->Source.x = 0;
				Pinky->Source.y = 170;
				Pinky->Source.w = 135;
				Pinky->Rect.x = x * 32;
				Pinky->Rect.y = y * 32;
				
				
			}
			if (Map[y][x] == INKY && Start == true)
			{
				Inky->Source.x = 0;
				Inky->Source.y = 340;
				Inky->Source.w = 135;
				Inky->Rect.x = x * 32;
				Inky->Rect.y = y * 32;
				
			}
			if (Map[y][x] == CLYDE && Start == true)
			{
				Clyde->Source.x = 0;
				Clyde->Source.y = 510;
				Clyde->Source.w = 135;
				Clyde->Rect.x = x * 32;
				Clyde->Rect.y = y * 32;
				Start = false;
				
			}
			
		}
	}
}



