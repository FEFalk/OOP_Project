#pragma once
#include "Panel.h"
#include <string>
class Window:public Panel
{
public:
public:
	Window();
	Window(int locX, int locY, int width, int height, int size);
	~Window();
	void OnLoaded(void);
	void SetNewColor(int r, int g, int b);
	void OnPaint();

protected:
	Container *window;
	Color color;
	int size;
	std::string titelString;
};

