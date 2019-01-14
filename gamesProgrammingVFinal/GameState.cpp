#include "GameState.h"

int GameState::ShowMenu(SDL_Texture * text, TTF_Font * Font)
{
	SDL_Color color1 = {255,255,255};
	SDL_Color color2 = { 255,255,0 };
	MenuSurface[0] = TTF_RenderText_Solid(Font, Labels[0], color2);
	MenuSurface[1] = TTF_RenderText_Solid(Font, Labels[1], color2);
	MenuSurface[2] = TTF_RenderText_Solid(Font, Labels[2], color2);
	MenuSurface[3] = TTF_RenderText_Solid(Font, Labels[3], color2);
	
	MenuText[0] = SDL_CreateTextureFromSurface(renderer, MenuSurface[0]);
	MenuText[1]= SDL_CreateTextureFromSurface(renderer, MenuSurface[1]);
	MenuText[2] = SDL_CreateTextureFromSurface(renderer, MenuSurface[2]);
	MenuText[3] = SDL_CreateTextureFromSurface(renderer, MenuSurface[3]);

	SDL_Rect PacSrc;
	PacSrc.x = 540;
	PacSrc.y = 170;
	PacSrc.h = 165;
	PacSrc.w = 165;

	SDL_Rect PacDst;
	PacDst.x = 270;
	PacDst.y = 220;
	PacDst.h = 100;
	PacDst.w = 100;

	SDL_Rect MenuPos;
	MenuPos.x = 190;
	MenuPos.y = 350;
	MenuPos.h = 50;
	MenuPos.w = 250;
	
	SDL_Rect MenuPos2;
	MenuPos2.x = 190;
	MenuPos2.y = 450;
	MenuPos2.h = 50;
	MenuPos2.w = 250;
	
	SDL_Rect MenuPos3;
	MenuPos3.x = 190;
	MenuPos3.y = 150;
	MenuPos3.h = 50;
	MenuPos3.w = 250;

	SDL_Rect MenuPos4;
	MenuPos4.x = 190;
	MenuPos4.y = 550;
	MenuPos4.h = 50;
	MenuPos4.w = 300;
	_Update up;
	

	SDL_Event event;
	while (1)
	{
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, MenuText[0], NULL, &MenuPos);
		SDL_RenderCopy(renderer, MenuText[1], NULL, &MenuPos2);
		SDL_RenderCopy(renderer, MenuText[2], NULL, &MenuPos3);
		SDL_RenderCopy(renderer, MenuText[3], NULL, &MenuPos4);
		SDL_RenderCopy(renderer, text, &PacSrc, &PacDst);
		SDL_RenderPresent(renderer);
		
		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT)
			{
				SDL_DestroyWindow(window);
				SDL_DestroyRenderer(renderer);
				SDL_Quit();
				return 0;
			}
			if (event.type == SDL_MOUSEMOTION)
			{
			}
			if (event.type == SDL_KEYDOWN)
			{

				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					SDL_DestroyWindow(window);
					SDL_DestroyRenderer(renderer);
					SDL_Quit();
					return 0;
					break;
				case SDLK_RETURN:
					return 1;
					break;
				}

			}
		}
	
	}
	return 0;
}
