#pragma once
#include "Graphix.h"
#include "Struct.h"
#include "Container.h"

class Panel:public Container
{
public:
	Panel();
	Panel(int locX, int locY, int width, int height, float order);
	~Panel();
	virtual void OnLoaded(void);
	void SetBackgroundColor(int r, int g, int b);
	virtual void OnPaint();

protected:
	Container *panel;
	Color bgColor; 
};

