#include "StdAfx.h"
#include "TextLabel.h"
#include "Graphix.h"

TextLabel::TextLabel(void)
{
	labelString.append("HejHej");
	color = Color(0, 0, 10);
}
TextLabel::TextLabel(int locX, int locY, int width, int height)
	:ControlBase(locX, locY, width, height, 0)
{
	labelString.append("HejHej");
	color = Color(50, 255, 255);
}

TextLabel::~TextLabel(void)
{
}

void TextLabel::OnLoaded(void)
{

}
void TextLabel::OnPaint()
{
	SetColor(color.r, color.g, color.b);

	DrawString(labelString, position.X, position.Y, SortOrder);
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
void TextLabel::ChangeText(string string)
{
	labelString.clear();
	labelString.assign(string);

}