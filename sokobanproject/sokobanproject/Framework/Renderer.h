#pragma once

#include <stdbool.h>

/// <summary>
///  렌더러를 초기화한다.
/// </summary>
/// <returns>초기화 성공이면 true, 아니면 fasle</returns>
bool InitializeRenderer();

/// 맵을 그린다.
void RenderMap();

void SetMessage(const char* message);