#include "stdafx.h"
#include "Input.h"

static bool s_currentKeyStates[256] = { false };
static bool s_prevKeyStates[256] = { false };

bool isKeyDown(int32_t keyCode)
{
	// 1001 1001
	// 1000 1000 &
	// 1000 1000
	if (0x8000 & GetAsyncKeyState(keyCode))
	// & 연산자
	{
		return true;
	}
	else
	{
		return false;
	}
}


void UpdateInput()
{
	memcpy(s_prevKeyStates, s_currentKeyStates, sizeof(s_prevKeyStates));

	for (int32_t keyCode = 0; keyCode < 256; ++keyCode)
	{
		if (isKeyDown(keyCode))
		{
			s_currentKeyStates[keyCode] = true;
		}
		else
		{
			s_currentKeyStates[keyCode] = false;
		}
		// 현재 키의 상태 값을 반환한다.
		// 0x8000 => 0b 1000 0000 0000 0000 -> 눌린 상태 
		// 0x8001 => 0b 1000 0000 0000 0001 -> 계속 눌린 상태
		// 0x0001 => 사이엔 눌렀는데 지금은 떼여있다.
		// 0x0000 => 아예 안 눌림
		// 1. 현재 키가 눌렀는지 => MSB(Most Significant Bit)가 set(1)
		// 2. 현재 키가 떼졌는지 => MSB(Most Significant Bit)가 MSB가 0 set
		// 3. GetAsyncKeytState() ---- GetAsyncKeyState()
		//						  ↑ 요 사이에 눌렸는지 => LSB set 
	}
}

bool GetButtonDown(EKeyCode keyCode)
{
	if (false == s_prevKeyStates[keyCode] && s_currentKeyStates[keyCode])
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool GetButtonUp(EKeyCode keyCode)
{
	if (s_prevKeyStates[keyCode] && false == s_currentKeyStates[keyCode])
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool GetButton(EKeyCode keyCode)
{
	if (s_prevKeyStates[keyCode] && s_currentKeyStates[keyCode])
	{
		return true;
	}
	else
	{
		return false;
	}
}