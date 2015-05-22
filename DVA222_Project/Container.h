#pragma once
#include "ControlBase.h"
#include "Struct.h"
#include "Graphix.h"
class Container:public ControlBase
{
public:
	Container();
	Container(int locX, int locY, int width, int height, int size);
	~Container();
	void OnLoaded(void);
	void SetNewColor(int r, int g, int b);
	void OnPaint();
	
protected:
	ControlBase *container;
	Color color;
	int size;
};

