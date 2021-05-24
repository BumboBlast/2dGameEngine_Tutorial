#ifndef COMPONENT_H
#define COMPONENT_H
#pragma once

#include "StandardForward.h"
#include "ECS.h"



class PositionComponent : public Component {

public:

	int x() { return xpos; }
	int y() { return ypos; }

	/* initializes xpos and ypos */
	void init() override
	{
		xpos = 0;
		ypos = 0;
	}

	void update() override
	{
		xpos++;
		ypos++;
	}

	void setPos(int x, int y)
	{
		xpos = x;
		ypos = y;
	}



private:
	int xpos;
	int ypos;
};
















#endif
