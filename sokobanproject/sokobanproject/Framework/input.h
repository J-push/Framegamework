#pragma once
#include <stdbool.h>

typedef enum KeyCode
{
	W = 'w',
	A = 'a',
	S = 's',
	D = 'd',
}EKeyCode;

void UpdateInput();

bool GetButtonDown(EKeyCode keyCode);

bool GetButtonUp(EKeyCode keyCode);

bool GetButton(EKeyCode keyCode);