#pragma once
#include "Graphix.h"
#include "Struct.h"
#include "Container.h"

class Panel:public Container
{
public:
	Panel();
	Panel(int locX, int locY, int width, int height);
	~Panel();
protected:
};

