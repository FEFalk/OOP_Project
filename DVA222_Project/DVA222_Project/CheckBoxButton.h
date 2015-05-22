#pragma once
#include "mybutton.h"
class CheckBoxButton :
	public MyButton
{
public:
	CheckBoxButton();
	CheckBoxButton(int locX, int locY);

	void OnLoaded();
	void OnPaint();
	void OnMouseDown(int button, int x, int y);
	void OnMouseMove(int button, int x, int y);
	void OnMouseUp(int button, int x, int y);

private:
	bool checked;
};

