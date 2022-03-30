#include "stdafx.h"
#include "Renderer.h"

#define MAP_SIZE 24

// fearing (페어링) 을 방지하기위해 더블버퍼링을 쓴다. 버퍼를 두개 씀.

static char s_map[MAP_SIZE][MAP_SIZE] = {
	"***********",
	"* Sokoban *",
	"***********"
};
static HANDLE s_consoleHandle;

bool InitializeRenderer()
{
	s_consoleHandle = GetStdHandle
	(STD_OUTPUT_HANDLE);

	if (INVALID_HANDLE_VALUE == s_consoleHandle)
	{
		return false;
	}

	/*CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = false;

	if (false == SetConsoleCursorInfo
		(s_consoleHandle, &info))
	{
		return false;
	}*/

	return true;
}

void RenderMap()
{
	const static COORD initialPos = { 0,0 };
	const static CONSOLE_CURSOR_INFO info = { 100, false };

	SetConsoleCursorPosition(s_consoleHandle, initialPos);

	SetConsoleCursorInfo(s_consoleHandle, &info);

	for (int i = 0; i < MAP_SIZE; ++i)
	{
		puts(s_map[i]);
	}
}
