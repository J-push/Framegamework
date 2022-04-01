#include "stdafx.h"
#include "Box.h"
#include "Player.h"

bool CanMove(Box* box, DIR dir)
{

}

void MoveBox(Box* box, DIR dir)
{
	switch (dir)
	{
	case DIR_LEFT:
		if (CanMove(box, dir))
		{
			--box->s_boxX;
		}
		break;
	case DIR_RIGHT:
		if (CanMove(box, dir))
		{
			++box->s_boxX;
		}
		break;
	case DIR_UP:
		if (CanMove(box, dir))
		{
			--box->s_boxY;
		}
		break;
	case DIR_DOWN:
		if (CanMove(box, dir))
		{
			++box->s_boxY;
		}
		break;
	}
}
