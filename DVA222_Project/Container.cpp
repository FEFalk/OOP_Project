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
		controls[i]->OnPaint();
	}
}

void Container::AddControl(ControlBase &newControl)
{
	controls.push_back(&newControl);
	newControl.SetPosition(newControl.GetPosition().Y + position.Y, newControl.GetPosition().X + position.X);
	//Sätt sort order lite framför "filled-rectangle"
	newControl.SetSortOrder(0);

}