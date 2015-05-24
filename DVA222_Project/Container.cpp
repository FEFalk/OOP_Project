#include "stdafx.h"
#include "Container.h"


Container::Container()
{
}
Container::Container(int locX, int locY, int width, int height, float order)
	: ControlBase(locX, locY, width, height, order)
{
}


Container::~Container()
{
}
void Container::OnLoaded(void)
{
	for (int i = 0; i < controls.size(); i++)
	{
		controls[i]->OnLoaded();
	}
}
void Container::OnPaint()
{
	for (int i = 0; i < controls.size(); i++)
	{
		controls[i]->SetPosition(controls[i]->GetOffset().X + position.X, controls[i]->GetOffset().Y + position.Y);
		controls[i]->OnPaint();
	}
}

void Container::AddControl(ControlBase &newControl)
{
	controls.push_back(&newControl);
	newControl.SetPosition(newControl.GetOffset().X + position.X, newControl.GetOffset().Y + position.Y);
	//Sätt sort order lite framför "filled-rectangle"
	newControl.SetSortOrder(newControl.GetSortOrder()+SortOrder+0.01);

}

void Container::OnMouseMove(int button, int x, int y)
{
	for (int i = 0; i < controls.size(); i++)
	{
		controls[i]->OnMouseMove(button, x, y);
	}
}

void Container::OnMouseDown(int button, int x, int y)
{
	for (int i = 0; i < controls.size(); i++)
	{
		controls[i]->OnMouseDown(button, x, y);
	}
}

void Container::OnMouseUp(int button, int x, int y)
{
	for (int i = 0; i < controls.size(); i++)
	{
		controls[i]->OnMouseUp(button, x, y);
	}
}

void Container::OnResize(int width, int height)
{
	ControlBase::OnResize(0, 0);
	for (int i = 0; i < controls.size(); i++)
	{
		controls[i]->OnResize(0, 0);
	}
}