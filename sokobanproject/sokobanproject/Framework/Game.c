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
	// 0.5�� �������� Ư�� �޽����� �����̱�
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
	// Game Loop => �÷��̾�κ����� �Է��� �ϵ����� �и���Ų��.
	// Game Loop�� ��ü�� Frame�̶� �Ѵ�.
	while (true)
	{
		// ������ ���� ----- ���� ������ ����
		// dt
		UpdateTimer();
		// �Է� ó��
		processInput();
		// ������Ʈ
		update();
		// ������
		render();
	}


	return 0;
}