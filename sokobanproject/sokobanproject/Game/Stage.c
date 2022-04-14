#include "stdafx.h"
#include "Stage.h"
#include "Framework/Renderer.h"
#include "Framework/Timer.h"
#include "Framework/Input.h"

static int stageNum = STAGE_01;
static char s_map[MAP_SIZE][MAP_SIZE];
static int32_t s_goalCount = 0; // 목표 개수
static int32_t s_boxInTheGoalCount = 0; // 현재 넣은 개수
static int32_t s_playerX = 0;
static int32_t s_playerY = 0;

typedef struct
{
	int32_t s_boxX;
	int32_t s_boxY;
}Box;

static Box box;

typedef struct
{
	int32_t s_goalX;
	int32_t s_goalY;
} Goal;

static Goal goal[Max_goalCount];

bool GoalPosition(int posX, int posY)
{
	for (int i = 0; i < s_goalCount; i++)
	{
		if (posX == goal[i].s_goalX && posY == goal[i].s_goalY)
		{
			return true;
		}
	}
	return false;
}

bool BoxInTheGoal(int posX, int posY)
{
	if (s_map[posX][posY] == 'O')
	{
		s_boxInTheGoalCount += 1;
		return true;
	}
	return false;
}

bool canBoxMove(Box box, EKeyCode keyCode)
{
	int s_NboxX = box.s_boxX;
	int s_NboxY = box.s_boxY;

	if (keyCode == 'W')
	{
		s_NboxX--;
	}

	else if (keyCode == 'A')
	{
		s_NboxY--;
	}

	else if (keyCode == 'S')
	{
		s_NboxX++;
	}

	else if (keyCode == 'D')
	{
		s_NboxY++;
	}

	switch (s_map[s_NboxX][s_NboxY])
	{
	case '#':
		return false;

	case 'a':
		return false;

	case '@':
		return false;

	default:
		return true;
	}
}

void BoxMove(Box box, EKeyCode keyCode)
{
	int s_NboxX = box.s_boxX;
	int s_NboxY = box.s_boxY;

	if (keyCode == 'W')
	{
		s_NboxX--;
	}

	else if (keyCode == 'A')
	{
		s_NboxY--;
	}

	else if (keyCode == 'S')
	{
		s_NboxX++;
	}

	else if (keyCode == 'D')
	{
		s_NboxY++;
	}

	if (BoxInTheGoal(s_NboxX, s_NboxY))
	{
		s_map[s_NboxX][s_NboxY] = '@';
	}
	else
	{
		s_map[s_NboxX][s_NboxY] = 'a';
	}
}

bool canPlayerMove(int posX, int posY, EKeyCode keyCode)
{
	switch (s_map[posX][posY])
	{
	case '#':
		return false;

	case 'a':
		box.s_boxX = posX;
		box.s_boxY = posY;
		if (canBoxMove(box, keyCode))
		{
			BoxMove(box, keyCode);
			return true;
		}
		else
		{
			return false;
		}
	case '@':
		box.s_boxX = posX;
		box.s_boxY = posY;
		if (canBoxMove(box, keyCode))
		{
			BoxMove(box, keyCode);
			s_boxInTheGoalCount--;
			return true;
		}
		else
		{
			return false;
		}
	default:
		return true;
	}
}

void PlayerMove()
{
	int s_NPlayerX = s_playerX;
	int s_NPlayerY = s_playerY;

	if (GetButtonDown(KEYCODE_W))
	{
		s_NPlayerX--;
		if (canPlayerMove(s_playerX - 1, s_playerY, KEYCODE_W))
		{
			if (GoalPosition(s_playerX, s_playerY))
			{
				s_map[s_playerX][s_playerY] = 'O';
			}
			else
			{
				s_map[s_playerX][s_playerY] = ' ';
			}
			s_map[--s_playerX][s_playerY] = 'P';
		}
	}
	else if (GetButtonDown(KEYCODE_A))
	{
		s_NPlayerY--;
		if (canPlayerMove(s_playerX, s_playerY - 1, KEYCODE_A))
		{
			if (GoalPosition(s_playerX, s_playerY))
			{
				s_map[s_playerX][s_playerY] = 'O';
			}
			else
			{
				s_map[s_playerX][s_playerY] = ' ';
			}
			s_map[s_playerX][--s_playerY] = 'P';
		}
	}
	else if (GetButtonDown(KEYCODE_S))
	{
		s_NPlayerX++;
		if (canPlayerMove(s_playerX + 1, s_playerY, KEYCODE_S))
		{
			if (GoalPosition(s_playerX, s_playerY))
			{
				s_map[s_playerX][s_playerY] = 'O';
			}
			else
			{
				s_map[s_playerX][s_playerY] = ' ';
			}
			s_map[++s_playerX][s_playerY] = 'P';
		}
	}
	else if (GetButtonDown(KEYCODE_D))
	{
		s_NPlayerY++;
		if (canPlayerMove(s_playerX, s_playerY + 1, KEYCODE_D))
		{
			if (GoalPosition(s_playerX, s_playerY))
			{
				s_map[s_playerX][s_playerY] = 'O';
			}
			else
			{
				s_map[s_playerX][s_playerY] = ' ';
			}
			s_map[s_playerX][++s_playerY] = 'P';
		}
	}
}

char parseMapType(size_t i, size_t j, char mapType)
{
	switch (mapType)
	{
	case '\n':
		return false;

	case 'P':
		s_playerX = (int)i;
		s_playerY = (int)j;
		s_map[i][j] = mapType;
		return true;

	case 'O':
		goal[s_goalCount].s_goalX = (int)i;
		goal[s_goalCount].s_goalY = (int)j;

		s_goalCount++;
		s_map[i][j] = mapType;
		return true;

	default:
		s_map[i][j] = mapType;
		return true;
	}
}

void clearStage()
{
	memset(s_map, ' ', sizeof(s_map));
	for (size_t i = 0; i < MAP_SIZE; ++i)
	{
		s_map[i][MAP_SIZE - 1] = '\0';
	}
	s_goalCount = 0;
	s_boxInTheGoalCount = 0;
	s_playerX = 0;
	s_playerY = 0;
}

void LoadStage(EStageLevel level)
{
	assert(STAGE_01 <= level && level < STAGE_MAX);

	static char path[MAX_PATH] = { 0 };

	sprintf_s(path, sizeof(path), "Stage/Stage%02d.txt", stageNum);
	FILE* fp = NULL;
	fopen_s(&fp, path, "r");
	assert(fp != NULL);

	clearStage();

	for (size_t i = 3; i < MAP_SIZE; ++i)
	{
		for (size_t j = 0; j < MAP_SIZE; ++j)
		{
			char ch = fgetc(fp);

			if (false == parseMapType(i, j, ch))
			{
				break;
			}
		}
		if (feof(fp))
		{
			break;
		}
	}
	fclose(fp);
}

bool StageOver()
{
	if (s_boxInTheGoalCount == s_goalCount)
	{
		stageNum++;
		if (stageNum < 4)
		{
			LoadStage(STAGE_01);
			return true;
		}
		else
		{
			clearStage();
			sprintf_s(s_map[0], sizeof(s_map[0]), "게임 클리어!");
			return true;
		}
	}
	return false;
}

void UpdateStage()
{
	PlayerMove();
	if (!StageOver())
	{
		sprintf_s(s_map[0], sizeof(s_map[0]), "-> Stage %d", stageNum);
		sprintf_s(s_map[1], sizeof(s_map[1]), "-> 개수 : %d", s_boxInTheGoalCount);
	}
	if (GetButtonDown(KEYCODE_R))
	{
		LoadStage(STAGE_01);
		sprintf_s(s_map[0], sizeof(s_map[0]), "-> Stage %d", stageNum);
		sprintf_s(s_map[1], sizeof(s_map[1]), "-> 개수 : %d", s_boxInTheGoalCount);
	}
}

const char** GetMap()
{
	return (char**)s_map;
}
