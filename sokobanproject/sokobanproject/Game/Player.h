#pragma once

typedef struct
{
	int32_t s_playerX;
	int32_t s_playerY;
}Player;

void MovePlayer(DIR* dir);
