#include "StdAfx.h"
#include "TextLabel.h"
#include "Graphix.h"

TextLabel::TextLabel(void)
{
}
TextLabel::TextLabel(int locX, int locY, int width, int height):ControlBase(locX, locY, width, height)
{

}

TextLabel::~TextLabel(void)
{
}

void TextLabel::OnLoaded(void)
{
	labelString.clear();
	labelString.append("HejHej");
	color = Color(255, 0, 0);
}
void TextLabel::OnPaint()
{
	SetColor(color.r, color.g, color.b);

	DrawString(labelString, X, Y);
}	
void TextLabel::SetNewColor(int r, int g, int b)
{
	color.r = r;
	color.g = g;
	color.b = b;

}
Color TextLabel::GetColor()
{
	return color;
}
void TextLabel::changeText(string string)
{
	labelString.clear();
	labelString.append(string);

}