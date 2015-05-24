#pragma once
#include "controlbase.h"
#include <string>
#include "Graphix.h"
#include "Struct.h"
class TextLabel:public ControlBase
{
public:
	TextLabel(void);
	TextLabel(int locX, int locY, int width, int height);
	~TextLabel(void);
	void OnLoaded();
	void OnPaint();	
	void SetNewColor(int r, int g, int b);	
	Color GetColor();
	void ChangeText(string);

protected:
	std::string labelString;
	Color color;
};

