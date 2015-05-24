#pragma once
#include "Panel.h"
#include "Graphix.h"
#include "Struct.h"
#include <string>
#include "MyButton.h"

class Window:public Panel
{
public:
	Window();
	Window(int locX, int locY, int width, int height, int order);
	~Window();

	void OnLoaded(void);
	void OnPaint();
	void OnMouseMove(int button, int x, int y);
	void OnMouseDown(int button, int x, int y);
	void OnMouseUp(int button, int x, int y);

	void SetBackgroundColor(int r, int g, int b);
	void SetBorderColor(int r, int g, int b);
	void SetTitleColor(int r, int g, int b);
	Color GetBorderColor();
	Color GetTitleColor();

	void OnResize(int width, int height);

protected:
	bool hit, pressed, prevPressed;
	float offset;
	Color borderColor;
	Color titleColor;
	std::string titelString;
	MyButton *resizeButton;
};

