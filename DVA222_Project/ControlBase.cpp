#include "StdAfx.h"
#include "ControlBase.h"

//===================================
//
//  C A N ' T   T O U C H   T H I S
//
//===================================

ControlBase::ControlBase()
{			 	
}

ControlBase::ControlBase(int x, int y, int w, int h, float z)
{
    position.X = x;
    position.Y = y;
	Offset.X = x;
	Offset.Y = y;
    Width = w;
    Height = h;
	SortOrder = z;
}
ControlBase::~ControlBase(void)
{
}

void ControlBase::OnLoaded(void)
{

}

void ControlBase::OnPaint(void)
{
	
}


void ControlBase::OnKeyboard(unsigned char key, int x, int y)
{
}

void ControlBase::OnMouseUp(int button, int x, int y)
{	
}

void ControlBase::OnMouseDown(int button, int x, int y)
{	
}

void ControlBase::OnMouseMove(int button, int x, int y)
{	
}

void ControlBase::OnResize(int width, int height)
{
}

Point ControlBase::GetOffset()
{
	return Offset;
}

void ControlBase::SetOffset(int x, int y)
{
	Offset.X = x;
	Offset.Y = y;
}

Point ControlBase::GetPosition()
{
	return position;
}

void ControlBase::SetPosition(int x, int y)
{
	position.X = x;
	position.Y = y;
}

void ControlBase::SetSortOrder(float newSortOrder)
{
	SortOrder = newSortOrder;
}
