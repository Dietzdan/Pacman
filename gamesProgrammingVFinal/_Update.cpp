#include "_Update.h"

void _Update::Present()
{	
	SDL_RenderPresent(renderer);
	SDL_RenderClear(renderer);
}

int _Update::Animation(int Frame)
{
	Sprite* p1 = spriteList.at(0).get();
	
		if (Frame == 400)
		{
			p1->Source.y = 510;
		}
		if (Frame == 800)
		{
			p1->Source.y = 170;
			Frame = 0;
		}
	
	return Frame;
	
}

void _Update::GhostExit0(int Map[MapY][MapX])
{
	Sprite* Player = spriteList.at(0).get();
	Sprite* Ghost = EnemyList.at(0).get();
	int OrginalX = Ghost->Rect.x/32;
	int OrginalY = Ghost->Rect.y/32;
	int TopY = OrginalY - 1;
	int BottomY = OrginalY+1;
	int LeftX = OrginalX- 1;
	int RightX = OrginalX + 1;
	if (Player->Score > 15)
	{
		if (counter == 1000)
		{
			Ghost->Rect.x = RightX * 32;
		}
		if (counter == 2000)
		{
			Ghost->Rect.y = TopY * 32;
		}
		if (counter == 3000)
		{
			Ghost->Rect.y = TopY * 32;
		}
		if (counter > 4000)
		{
			GhostMove(Map, 0);
		}
		counter++;
	}
}

void _Update::GhostExit1(int Map[MapY][MapX])
{
	Sprite* Ghost = EnemyList.at(1).get();
	
	int OrginalX = Ghost->Rect.x / 32;
	int OrginalY = Ghost->Rect.y / 32;
	int TopY = OrginalY - 1;
	int BottomY = OrginalY + 1;
	int LeftX = OrginalX - 1;
	int RightX = OrginalX + 1;
	
	
	
		if (counter1 == 1000)
		{
			Ghost->Rect.y = TopY * 32;
		}
		if (counter1 == 2000)
		{
			Ghost->Rect.y = TopY * 32;
		}
		if (counter1 == 3000)
		{
			Ghost->Rect.x = RightX * 32;
		}
		if (counter1 > 4000)
		{
			GhostMove1(Map, 1);
		}
		counter1++;
	
	
	


}

void _Update::GhostExit2(int Map[MapY][MapX])
{
	Sprite* Player = spriteList.at(0).get();
	Sprite* Ghost = EnemyList.at(2).get();
	int OrginalX = Ghost->Rect.x / 32;
	int OrginalY = Ghost->Rect.y / 32;
	int TopY = OrginalY - 1;
	int BottomY = OrginalY + 1;
	int LeftX = OrginalX - 1;
	int RightX = OrginalX + 1;
	if (Player->Score > 40)
	{
		if (counter2 == 1000)
		{
			Ghost->Rect.x = LeftX * 32;
		}
		if (counter2 == 2000)
		{
			Ghost->Rect.y = TopY * 32;
		}
		if (counter2 == 3000)
		{
			Ghost->Rect.y = TopY * 32;
		}
		if (counter2 > 4000)
		{
			GhostMove2(Map, 2);
		}
		counter2++;
	}

}

void _Update::GhostExit3(int Map[MapY][MapX])
{
	Sprite* Player = spriteList.at(0).get();
	Sprite* Ghost = EnemyList.at(3).get();
	int OrginalX = Ghost->Rect.x / 32;
	int OrginalY = Ghost->Rect.y / 32;
	int TopY = OrginalY - 1;
	int BottomY = OrginalY + 1;
	int LeftX = OrginalX - 1;
	int RightX = OrginalX + 1;

	if (Player->Score > 60)
	{
		if (counter3 == 0)
		{
			Ghost->Rect.x = LeftX * 32;
		}
		if (counter3 == 1000)
		{
			Ghost->Rect.x = LeftX * 32;
		}
		if (counter3 == 2000)
		{
			Ghost->Rect.y = TopY * 32;
		}
		if (counter3 == 3000)
		{
			Ghost->Rect.y = TopY * 32;
		}
		if (counter3 > 4000)
		{
			GhostMove3(Map, 3);
		}
		counter3++;
	}
}

void _Update::GhostMove(int Map[MapY][MapX],int Ghost)
{
	std::vector<int> PostionsX;
	std::vector<int> PostionsY;
	Sprite* Enemy = EnemyList.at(Ghost).get();
	int OrginalX = Enemy->Rect.x / 32;
	int OrginalY = Enemy->Rect.y / 32;
	int TopY = OrginalY - 1;
	int BottomY = OrginalY + 1;
	int LeftX = OrginalX - 1;
	int RightX = OrginalX + 1;

	
	if (Map[OrginalY][OrginalX] == 0 || Map[OrginalY][OrginalX]==2)
	{
		if (Map[TopY][OrginalX] == 0)
		{
			PostionsX.push_back(OrginalX);
			PostionsY.push_back(TopY);
		}
		if (Map[BottomY][OrginalX] == 0)
		{
			PostionsX.push_back(OrginalX);
			PostionsY.push_back(BottomY);
		}
		if (Map[OrginalY][LeftX] == 0)
		{
			PostionsX.push_back(LeftX);
			PostionsY.push_back(OrginalY);
		}
		if (Map[OrginalY][RightX] == 0 || Map[OrginalY][RightX] == 4)
		{
			PostionsX.push_back(LeftX);
			PostionsY.push_back(OrginalY);
		}

		int Random = rand() % PostionsX.size();
		int PickedNum = Random;

		int NewX = PostionsX[PickedNum];
		int NewY = PostionsY[PickedNum];
		if (counter == 1000 * timecounter)
		{
			Enemy->Rect.x = (NewX * 32)+2;
			Enemy->Rect.y = (NewY * 32)+2;
			
			timecounter++;
		}
	}
	else
	{
		if (Map[OrginalY][OrginalX] == 1 && Map[BottomY][OrginalX] == 1)
		{
			
			Enemy->Rect.x = (OrginalX + 2) * 32;
			
		}
		
		
		
	}
	PostionsX.clear();
}

void _Update::GhostMove1(int Map[MapY][MapX], int Ghost)
{
	std::vector<int> PostionsX;
	std::vector<int> PostionsY;
	Sprite* Enemy1 = EnemyList.at(Ghost).get();
	int OrginalX = Enemy1->Rect.x / 32;
	int OrginalY = Enemy1->Rect.y / 32;
	int TopY = OrginalY - 1;
	int BottomY = OrginalY + 1;
	int LeftX = OrginalX - 1;
	int RightX = OrginalX + 1;
	

	if (Map[OrginalY][OrginalX] == 0 || Map[OrginalY][OrginalX] == 2)
	{
		if (Map[TopY][OrginalX] == 0)
		{
			PostionsX.push_back(OrginalX);
			PostionsY.push_back(TopY);
		}
		if (Map[BottomY][OrginalX] == 0)
		{
			PostionsX.push_back(OrginalX);
			PostionsY.push_back(BottomY);
		}
		if (Map[OrginalY][LeftX] == 0)
		{
			PostionsX.push_back(LeftX);
			PostionsY.push_back(OrginalY);
		}
		if (Map[OrginalY][RightX] == 0 || Map[OrginalY][RightX] == 4)
		{
			PostionsX.push_back(LeftX);
			PostionsY.push_back(OrginalY);
		}

		int Random = rand() % PostionsX.size();
		int PickedNum = Random;

		int NewX = PostionsX[PickedNum];
		int NewY = PostionsY[PickedNum];
		if (counter1 == 1000 * timecounter1)
		{
			Enemy1->Rect.x = (NewX * 32) + 2;
			Enemy1->Rect.y = (NewY * 32) + 2;

			timecounter1++;
		}
	}
	else
	{
		if (Map[OrginalY][OrginalX] == 1 && Map[BottomY][OrginalX] == 1)
		{
			
			Enemy1->Rect.x = (OrginalX + 2) * 32;

		}



	}
	PostionsX.clear();
}


void _Update::GhostMove2(int Map[MapY][MapX], int Ghost)
{
	std::vector<int> PostionsX;
	std::vector<int> PostionsY;
	Sprite* Enemy = EnemyList.at(Ghost).get();
	int OrginalX = Enemy->Rect.x / 32;
	int OrginalY = Enemy->Rect.y / 32;
	int TopY = OrginalY - 1;
	int BottomY = OrginalY + 1;
	int LeftX = OrginalX - 1;
	int RightX = OrginalX + 1;


	if (Map[OrginalY][OrginalX] == 0 || Map[OrginalY][OrginalX] == 2)
	{
		if (Map[TopY][OrginalX] == 0)
		{
			PostionsX.push_back(OrginalX);
			PostionsY.push_back(TopY);
		}
		if (Map[BottomY][OrginalX] == 0)
		{
			PostionsX.push_back(OrginalX);
			PostionsY.push_back(BottomY);
		}
		if (Map[OrginalY][LeftX] == 0)
		{
			PostionsX.push_back(LeftX);
			PostionsY.push_back(OrginalY);
		}
		if (Map[OrginalY][RightX] == 0 || Map[OrginalY][RightX] == 4)
		{
			PostionsX.push_back(LeftX);
			PostionsY.push_back(OrginalY);
		}

		int Random = rand() % PostionsX.size();
		int PickedNum = Random;

		int NewX = PostionsX[PickedNum];
		int NewY = PostionsY[PickedNum];
		if (counter2 == 1000 * timecounter2)
		{
			Enemy->Rect.x = (NewX * 32) + 2;
			Enemy->Rect.y = (NewY * 32) + 2;

			timecounter2++;
		}
	}
	else
	{
		if (Map[OrginalY][OrginalX] == 1 && Map[BottomY][OrginalX] == 1)
		{
			std::cout << Enemy->Rect.x / 32 << " " << Enemy->Rect.y / 32 << std::endl;
			Enemy->Rect.x = (OrginalX + 2) * 32;

		}



	}
	PostionsX.clear();

}

void _Update::GhostMove3(int Map[MapY][MapX], int Ghost)
{
	std::vector<int> PostionsX;
	std::vector<int> PostionsY;
	Sprite* Enemy = EnemyList.at(Ghost).get();
	int OrginalX = Enemy->Rect.x / 32;
	int OrginalY = Enemy->Rect.y / 32;
	int TopY = OrginalY - 1;
	int BottomY = OrginalY + 1;
	int LeftX = OrginalX - 1;
	int RightX = OrginalX + 1;


	if (Map[OrginalY][OrginalX] == 0 || Map[OrginalY][OrginalX] == 2)
	{
		if (Map[TopY][OrginalX] == 0)
		{
			PostionsX.push_back(OrginalX);
			PostionsY.push_back(TopY);
		}
		if (Map[BottomY][OrginalX] == 0)
		{
			PostionsX.push_back(OrginalX);
			PostionsY.push_back(BottomY);
		}
		if (Map[OrginalY][LeftX] == 0)
		{
			PostionsX.push_back(LeftX);
			PostionsY.push_back(OrginalY);
		}
		if (Map[OrginalY][RightX] == 0 || Map[OrginalY][RightX] == 4)
		{
			PostionsX.push_back(LeftX);
			PostionsY.push_back(OrginalY);
		}

		int Random = rand() % PostionsX.size();
		int PickedNum = Random;

		int NewX = PostionsX[PickedNum];
		int NewY = PostionsY[PickedNum];
		if (counter3 == 1000 * timecounter3)
		{
			Enemy->Rect.x = (NewX * 32) + 2;
			Enemy->Rect.y = (NewY * 32) + 2;

			timecounter3++;
		}
	}
	else
	{
		if (Map[OrginalY][OrginalX] == 1 && Map[BottomY][OrginalX] == 1)
		{
			std::cout << Enemy->Rect.x / 32 << " " << Enemy->Rect.y / 32 << std::endl;
			Enemy->Rect.x = (OrginalX + 2) * 32;

		}



	}
	PostionsX.clear();
}


void _Update::WallCollision()
{
	
	
	bool collison = false;
	Sprite* Player = spriteList.at(0).get();
	
	for (auto const& Wall : WallList)
	{	
		
		collison = SDL_HasIntersection(&Player->Rect, &Wall->Rect);
		if (collison == true)
		{
			WallcollisonResponse(Player,*Wall);
		}
	
	}
}

void _Update::EnemyWallCollison()
{
	bool collison = false;
	for (auto const& Ghost : EnemyList)
	{

		for (auto const& Wall : WallList)
		{

			collison = SDL_HasIntersection(&Ghost->Rect, &Wall->Rect);
			if (collison == true)
			{
				EnemyWallCollisonResponse(*Ghost, *Wall);
			}

		}
	}
}

void _Update::EnemyWallCollisonResponse(Sprite & Ghost, Sprite & Wall)
{
	int oldX;
	int oldY;
	int LeftP;
	int RightP;
	int TopP;
	int BottomP;
	int LeftW;
	int RightW;
	int TopW;
	int BottomW;
	//Plsyer sides
	LeftP = Ghost.Rect.x;
	RightP = Ghost.Rect.x + Ghost.Rect.w;
	TopP = Ghost.Rect.y;
	BottomP = Ghost.Rect.y + Ghost.Rect.h;
	//Player postions
	oldX = Ghost.Rect.x / 32;
	oldY = Ghost.Rect.y / 32;
	//Wall Sides
	LeftW = Wall.Rect.x;
	RightW = Wall.Rect.x + Wall.Rect.w;
	TopW = Wall.Rect.y;
	BottomW = Wall.Rect.y + Wall.Rect.h;

	if (LeftP < RightW && RightW - LeftP == 3)
	{

		oldX = oldX + 1;
		Ghost.Rect.x = oldX * 32;
	}
	if (RightP > LeftW && RightP - LeftW == 3)
	{

		Ghost.Rect.x = oldX * 32;
	}
	if (BottomP > TopW && BottomP - TopW == 3)
	{
		Ghost.Rect.y = oldY * 32;
	}
	if (TopP < BottomW && BottomW - TopP == 3)
	{
		oldY = oldY + 1;
		Ghost.Rect.y = oldY * 32;
	}
}

void _Update::WallcollisonResponse(Sprite* Player, Sprite& Wall)
{
	int oldX;
	int oldY;
	int LeftP;
	int RightP;
	int TopP;
	int BottomP;
	int LeftW;
	int RightW;
	int TopW;
	int BottomW;
	//Plsyer sides
	LeftP = Player->Rect.x;
	RightP = Player->Rect.x + Player->Rect.w;
	TopP = Player->Rect.y;
	BottomP = Player->Rect.y + Player->Rect.h;
	//Player postions
	oldX = Player->Rect.x / 32;
	oldY = Player->Rect.y / 32;
	//Wall Sides
	LeftW = Wall.Rect.x;
	RightW = Wall.Rect.x + Wall.Rect.w;
	TopW = Wall.Rect.y;
	BottomW = Wall.Rect.y + Wall.Rect.h;

	if (LeftP < RightW && RightW - LeftP == 3 )
	{
		
		oldX = oldX + 1;
		Player->Rect.x = oldX * 32;
	}
	if (RightP > LeftW && RightP-LeftW == 3)
	{
		
		Player->Rect.x = oldX * 32;
	}
	if (BottomP > TopW && BottomP - TopW == 3)
	{
		
		Player->Rect.y = oldY * 32;
	}
	if (TopP < BottomW && BottomW - TopP == 3)
	{
		oldY = oldY + 1;
		Player->Rect.y = oldY * 32;
	}
}
bool _Update::EnemyCollision(SDL_Texture* Pac,bool running)
{
	Render r;
	bool collison = false;
	
	Sprite* Player = spriteList.at(0).get();
	for (auto const& Sprite : EnemyList)
	{
		collison = SDL_HasIntersection(&Player->Rect, &Sprite->Rect);
		if (collison == true)
		{
			SDL_DestroyTexture(Pac);
			running = r.GameOver();
		}
	}
	return running;
}

void _Update::DotCollision(Mix_Chunk *Pop)
{
	bool collison = false;
	Sprite* Player = spriteList.at(0).get();
	Sprite* Dot;
	
	for (int x = 0;x<DotList.size();x++)
	{
		Dot = DotList.at(x).get();
		collison = SDL_HasIntersection(&Player->Rect, &Dot->Rect);
		if (collison == true)
		{
			Mix_PlayChannel(-1, Pop, 0);
			DotList.at(x).release();
			Player->Score++;
			std::cout << "Score:" << Player->Score << std::endl;
		}
	}

}





		

		


