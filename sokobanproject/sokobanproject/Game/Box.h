#pragma once

typedef struct
{
	int32_t s_boxX;
	int32_t s_boxY;
}Box;

void MoveBox(Box* box, DIR dir);