#include "stdafx.h"
#include "RadioButtonGroup.h"


RadioButtonGroup::RadioButtonGroup()
{
}

RadioButtonGroup::RadioButtonGroup(int locX, int locY, int width, int height)
	: Container(locX, locY, width, height, 0)
{
	
}


RadioButtonGroup::~RadioButtonGroup()
{
}

void RadioButtonGroup::OnLoaded()
{
	currentButton = 0;
	title.append("I am a RadioButtonGroup!");
}

void RadioButtonGroup::OnPaint()
{

	for (int i = 0; i < controls.size(); i++)
	{
		controls[i]->SetPosition(controls[i]->GetOffset().X + position.X, controls[i]->GetOffset().Y + position.Y);
	}

	Container::OnPaint();

	SetColor(255, 0, 255);
	DrawRectangle(position.X, position.Y, Width, Height, SortOrder);
	SetColor(255, 255, 0);
	DrawString(title, position.X + 10, position.Y + 10, SortOrder); 
}

void RadioButtonGroup::SetTitle(string newTitle)
{
	title = newTitle;
}

string RadioButtonGroup::GetTitle()
{
	return title;
}

void RadioButtonGroup::SetBorder(int newWidth, int newHeight)
{
	Width = newWidth;
	Height = newHeight;
}

Rect RadioButtonGroup::GetBorder()
{
	return Rect(position.X, position.Y, Width, Height);
}

void RadioButtonGroup::OnMouseMove(int button, int x, int y)
{
	for (int i = 0; i < controls.size(); i++)
	{
		controls[i]->OnMouseMove(button, x, y);
		if (static_cast<MyRadioButton *>(controls[i])->hit == true)
		{
			currentButton = i;
			break;
		}
		else
			currentButton = -1;
	}
}

void RadioButtonGroup::OnMouseDown(int button, int x, int y)
{
	if (currentButton < controls.size() && currentButton >= 0)
	{
		controls[currentButton]->OnMouseDown(button, x, y);
		if (static_cast<MyRadioButton *>(controls[currentButton])->pressed == true)
		{
			for (int i = 0; i < controls.size(); i++)
			{
				if (i==currentButton)
				{
					continue;
				}
				static_cast<MyRadioButton *>(controls[i])->pressed = false;
			}
		}
	}
}