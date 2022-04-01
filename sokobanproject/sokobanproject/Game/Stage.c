#include "stdafx.h"
#include "Stage.h"
#include "Player.h"
#include "Framework/Input.h"

static char s_map[MAP_SIZE][MAP_SIZE];
static int32_t s_goalCount = 0; // 목표 갯수
static int32_t s_boxOnGoalCount = 0; // 현재 맞는 개수 
static int32_t s_playerX = 0;
static int32_t s_playerY = 0;

bool parseMapType(int i, int j, char mapType)
{
	switch (mapType)
	{
	/*case 'P':
		
		break;
	case ' ':

	default:
		assert(false);
		break;*/
	}
	//반환은 행에 다다랐을 떄
}

void clearStage()
{
	memset(s_map, ' ', sizeof(s_map));
	for (size_t i = 0; i < MAP_SIZE; ++i)
	{
		s_map[i][MAP_SIZE - 1] = '\0';
	}
	s_goalCount = 0;
	s_boxOnGoalCount = 0;
	s_playerX = 0;
	s_playerY = 0;
}

void LoadStage(EStageLevel level)
{
	assert(STAGE_01 <= level && level < STAGE_MAX);

	static char path[MAX_PATH] = { 0 };

	sprintf_s(path, sizeof(path), "Stage/Stage%02d.txt", (int32_t)level);
	FILE* fp = NULL;
	fopen_s(&fp, path, "r");
	assert(fp != NULL);

	clearStage();

	for (size_t i = 0; i < MAP_SIZE; ++i)
	{
		for (size_t j = 0; j < MAP_SIZE; ++j)
		{
			char ch = fgetc(fp);

			if (false == parseMapType(i, j ,ch))
				//i = linenumber, charactercount , ch
			{
				break;
			}
			/*if (ch == '\n')
			{
				break;
			}

			s_map[i][j] = ch;*/
		}
		if (feof(fp))
		{
			break;
		}
	}
	fclose(fp);
}

void UpstateStage()
{
	// 입력에 대해서 처리를 함
	if (GetButton(KEYCODE_W))
	{
		MovePlayer(DIR_UP);
		{
			int x = 0;
			int y = 0;
			if (false == isValid(x, y))
			{
				return;
			}
			EMapType mapType = GetMapType(x, y - 1);

			switch (mapType)
			{
			case MAPTYPE_WALL:
				return;
			case MAPTYPE_BOX:
				MoveBox(DIR_UP);
				break;
			}
		}
	}
	// 게임이 클리어 됐는지도 파악함
	if (IsClearStage())
	{

	}
}


const char** GetMap()
{
	return s_map; 
}