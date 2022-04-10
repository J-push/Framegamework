#pragma once

typedef enum MapType
{
	MAPTYPE_WALL = '#',
	MAPTYPE_PLAYER = 'P',
	MAPTYPE_BOX = 'a',
	MAPTYPE_GOAL = 'O',
	MAPTYPE_BOX_ON_GOAL = '@',
	MAPTYPE_PATH = ' '
}EMapType;

typedef enum StageLevel
{
	STAGE_01 = 1,
	STAGE_MAX
}EStageLevel;

// 스테이지를 로딩한다.
void LoadStage(EStageLevel level);

// 스테이지를 업데이트한다.
void UpdateStage();

// 맵을 반환한다.
const char** GetMap();