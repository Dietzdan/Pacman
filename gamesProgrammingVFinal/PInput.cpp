#include "PInput.h"

bool PInput::Input()
{
	//pointer for p1 from sprite list 
	Sprite* p1 = spriteList.at(0).get();
	Sprite* Ghost = EnemyList.at(0).get();
	_Update up;
	running = true;
	float left;
	
	bool fullscreen = false;
	SDL_Event Works;
	
	
	

		while (SDL_PollEvent(&Works) != 0)
		{
			if (Works.type == SDL_QUIT)
			{
				SDL_DestroyWindow(window);
				SDL_DestroyRenderer(renderer);
				running = false;
			}
			if (Works.type == SDL_KEYDOWN)
			{

				switch (Works.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					SDL_DestroyWindow(window);
					SDL_DestroyRenderer(renderer);
					SDL_Quit();
					running = false;
					break;

				case SDLK_SPACE:
					SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
					break;
				case SDLK_LEFT:
					
					p1->Angle = 0;
					p1->flip = SDL_FLIP_HORIZONTAL;
					p1->Rect.x -= Ghost->Speed;

					break;
				case SDLK_RIGHT:
					p1->flip = SDL_FLIP_NONE;
					p1->Angle = 0;
					p1->Rect.x += Ghost->Speed;
					break;
				case SDLK_UP:
					p1->flip = SDL_FLIP_NONE;
					p1->Angle = 270;
					p1->Rect.y -= p1->Speed;
					break;
				case SDLK_DOWN:
					p1->flip = SDL_FLIP_NONE;
					p1->Angle = 85;
					p1->Rect.y += p1->Speed;
					break;

				}


			}

		}
	
	return running;
	
	
	
}
