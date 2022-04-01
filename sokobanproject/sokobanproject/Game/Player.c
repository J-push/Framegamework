#include "Player.h"
#include "stdafx.h"

void MovePlayer(DIR* dir)
{
	Player* player;
	switch (*dir)
	{
	case DIR_LEFT:
		player->s_playerX--;
	case DIR_RIGHT:
		player->s_playerX++;
	case DIR_UP:
		player->s_playerY--;
	case DIR_DOWN:
		player->s_playerY++;
	}
}
