#pragma once

#include <stdbool.h>

/// <summary>
///  �������� �ʱ�ȭ�Ѵ�.
/// </summary>
/// <returns>�ʱ�ȭ �����̸� true, �ƴϸ� fasle</returns>
bool InitializeRenderer();

/// ���� �׸���.
void RenderMap();

void SetMessage(const char* message);