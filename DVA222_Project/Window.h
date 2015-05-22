#pragma once
#include "Panel.h"
#include "Graphix.h"
#include "Struct.h"
#include <string>
class Window:public Panel
{
public:
	Window();
	Window(int locX, int locY, int width, int height);
	~Window();
	void OnLoaded(void);
	void SetNewColor(int r, int g, int b);
	Color GetColor();
	void OnResize(int width, int height);

	void OnMouseMove(int button, int x, int y);
	void OnMouseDown(int button, int x, int y);
	void OnMouseUp(int button, int x, int y);

	void OnPaint();

protected:
	bool hit, pressed, checked;
	Color color;
	std::string titelString;
};
