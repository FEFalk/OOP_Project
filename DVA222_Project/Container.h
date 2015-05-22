#pragma once
#include "Graphix.h"
#include <vector>

class Container:public ControlBase
{
public:
	Container();
	Container(int locX, int locY, int width, int height, float order);
	~Container();
	virtual void OnLoaded(void);
	virtual void OnPaint();
	
	void AddControl(ControlBase  &control);

protected:
	vector <ControlBase *> controls;
};

