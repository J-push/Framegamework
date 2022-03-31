#include "stdafx.h"
#include "Game.h"
#include "Renderer.h"
#include "Input.h"
#include "Timer.h"
#include "Game/Stage.h"


bool Initialize()
{
	if (false == InitializeRenderer())
	{
		return false;
	}

	InitializeTimer();

	LoadStage(STAGE_01);

	return true;
}


void processInput()
{
	UpdateInput();
}


void update()
{
	// 0.5초 간격으로 특정 메시지를 깜빡이기
	/*static float timer = 0.0f;
	static bool canShowMessage = false;
	
	timer += GetDeltaTime();

	if (timer > 0.5f)
	{
		timer = 0;
		canShowMessage = !canShowMessage;
	}

	if (canShowMessage)
	{
		SetMessage("Gap");
	}*/
	UpdateStage();
}

void render()
{
	RenderMap();
}

int32_t Run()
{
	// Game Loop => 플레이어로부터의 입력을 하드웨어와 분리시킨다.
	// Game Loop의 전체를 Frame이라 한다.
	while (true)
	{
		// 프레임 시작 ----- 다음 프레임 시작
		// dt
		UpdateTimer();
		// 입력 처리
		processInput();
		// 업데이트
		update();
		// 렌더링
		render();
	}


	return 0;
}