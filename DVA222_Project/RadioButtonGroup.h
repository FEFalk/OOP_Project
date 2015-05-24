#pragma once
#include "Container.h"
#include "MyRadioButton.h"
class RadioButtonGroup :
	public Container
{
public:
	RadioButtonGroup();
	RadioButtonGroup(int locX, int locY, int width, int height);
	~RadioButtonGroup();
	void OnLoaded(void);
	void OnPaint();
	void OnMouseDown(int button, int x, int y);
	void OnMouseMove(int button, int x, int y);

	void SetTitle(string newTitle);
	string GetTitle();

	Rect GetBorder();
	void SetBorder(int newWidth, int newHeight);

private:
	string title;
	int currentButton;
};

