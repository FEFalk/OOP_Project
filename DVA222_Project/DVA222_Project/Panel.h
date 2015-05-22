#pragma once
#include "ControlBase.h"
#include "Graphix.h"
#include "Struct.h"
#include "Container.h"

class Panel:public Container
{
public:
	Panel();
	Panel(int locX, int locY, int width, int height, int size);
	~Panel();
	void OnLoaded(void);
	void SetNewColor(int r, int g, int b);
	void OnPaint();

protected:
	Container *panel;
	Color color;
	int size;
};

