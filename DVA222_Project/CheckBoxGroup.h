#pragma once
#include "Container.h"
class CheckBoxGroup :
	public Container
{
public:
	CheckBoxGroup();
	CheckBoxGroup(int locX, int locY, int width, int height);
	~CheckBoxGroup();
	void OnLoaded(void);
	void OnPaint();

	void SetTitle(string newTitle);
	string GetTitle();
	
	Rect GetBorder();
	void SetBorder(int newWidth, int newHeight);

private:
	string title;

};

