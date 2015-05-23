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
	virtual void OnMouseUp(int button, int x, int y);
	virtual void OnMouseDown(int button, int x, int y);
	virtual void OnMouseMove(int button, int x, int y);

protected:
	vector <ControlBase *> controls;
};

