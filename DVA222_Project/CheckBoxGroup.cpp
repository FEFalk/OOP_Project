#include "stdafx.h"
#include "CheckBoxGroup.h"

CheckBoxGroup::CheckBoxGroup()
{
}

CheckBoxGroup::CheckBoxGroup(int locX, int locY, int width, int height)
	: Container(locX, locY, width, height, 0)
{

}


CheckBoxGroup::~CheckBoxGroup()
{
}

void CheckBoxGroup::OnLoaded()
{
	title.append("I am a CheckBoxGroup!");
}

void CheckBoxGroup::OnPaint()
{
	Container::OnPaint();

	SetColor(0, 0, 255);
	DrawRectangle(position.X, position.Y, Width, Height, SortOrder);
	SetColor(0, 255, 0);
	DrawString(title, position.X+10, position.Y+10, SortOrder);
}

void CheckBoxGroup::SetTitle(string newTitle)
{
	title = newTitle;
}

string CheckBoxGroup::GetTitle()
{
	return title;
}

void CheckBoxGroup::SetBorder(int newWidth, int newHeight)
{
	Width = newWidth;
	Height = newHeight;
}

Rect CheckBoxGroup::GetBorder()
{
	return Rect(position.X, position.Y, Width, Height);
}