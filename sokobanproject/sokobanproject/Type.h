#pragma once

typedef enum Direction
{
	DIR_LEFT,
	DIR_RIGHT,
	DIR_UP,
	DIR_DOWN
}DIR;

typedef struct
{
	int32_t s_boxX;
	int32_t s_boxY;
}Box;

typedef enum KeyCode
{
	KEYCODE_W = 'W',
	KEYCODE_A = 'A',
	KEYCODE_S = 'S',
	KEYCODE_D = 'D',
}EKeyCode;

typedef enum StageLevel
{
	STAGE_01 = 1,
	STAGE_MAX
}EStageLevel;