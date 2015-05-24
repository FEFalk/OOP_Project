#pragma once
#include "MyButton.h"

class MyRadioButton : public MyButton
{
public:
	MyRadioButton();
	MyRadioButton(int locX, int locY, int radius);

	void OnLoaded();
	void OnPaint();
	void OnMouseDown(int button, int x, int y);
	void OnMouseMove(int button, int x, int y);
	void OnMouseUp(int button, int x, int y);


};

