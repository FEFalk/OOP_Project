
#include "stdafx.h"
#include "Window.h"

Window::Window()
{
	Window::Window(0, 0, 100, 100, 0);
}
Window::Window(int locX, int locY, int width, int height, int order)
	: Panel(locX, locY, width, height, order)
{
	hit = pressed = false;
	resizeButton = new MyButton(locX + width - 15, locY + 5, 10, 10);
	resizeButton->SetOffset(width -15, 5);
	resizeButton->SetSortOrder(SortOrder + 0.1);
}


Window::~Window()
{
}

void Window::OnLoaded(void)
{
	Panel::OnLoaded();
	borderColor = Color(0, 0, 255);
	titleColor = Color(0, 255, 0);
	titelString.clear();
	titelString.append("Window I am!");
}
void Window::OnPaint()
{
	SetColor(borderColor.r, borderColor.g, borderColor.b);
	FillRectangle(position.X-5, position.Y-5, Width + 10, Height + 10, SortOrder-0.1);

	Panel::OnPaint();

	SetColor(titleColor.r, titleColor.g, titleColor.b);
	DrawString(titelString, position.X + 5, position.Y + 10, SortOrder+0.02);

	SetColor(255, 255, 255);
	DrawRectangle(resizeButton->GetPosition().X, resizeButton->GetPosition().Y, 10, 10, resizeButton->GetSortOrder()+0.1);
	//resize(500, 500);
}

void Window::SetBorderColor(int r, int g, int b)
{
	borderColor.r = r;
	borderColor.g = g;
	borderColor.b = b;
}

void Window::SetTitleColor(int r, int g, int b)
{
	titleColor.r = r;
	titleColor.g = g;
	titleColor.b = b;
}

Color Window::GetTitleColor()
{
	return titleColor;
}

Color Window::GetBorderColor()
{
	return borderColor;
}

void Window::OnMouseMove(int button, int x, int y)
{
	Container::OnMouseMove(button, x, y);
	resizeButton->OnMouseMove(button, x, y);
	if (x > position.X - 5 && x < position.X + 5 + Width && y>position.Y - 5 && y < position.Y + 30)
	{
		hit = true;
	}
	else
		hit = false;
	if (pressed)
	{
		if (!prevPressed)
			offset = x - position.X;
		position.X = x-offset;
		position.Y = y;
		resizeButton->SetPosition(resizeButton->GetOffset().X + position.X, resizeButton->GetOffset().Y + position.Y);

		prevPressed = true;
	}
	else
		prevPressed = false;
}

void Window::OnMouseDown(int button, int x, int y)
{
	Container::OnMouseDown(button, x, y);
	resizeButton->OnMouseDown(button, x, y);
	if (resizeButton->pressed == true)
	{
		resize(Width / 2, Height / 2);
		resizeButton->SetOffset(resizeButton->GetOffset().X / 2, resizeButton->GetOffset().Y / 2);

	}

	if (hit && button == MOUSE_LEFT)
		pressed = true;
	else
		pressed = false;
}

void Window::OnMouseUp(int button, int x, int y)
{
	Container::OnMouseUp(button, x, y);
	resizeButton->OnMouseUp(button, x, y);

	if (pressed)
		pressed = false;
}

void Window::OnResize(int width, int height)
{
	for (int i = 0; i < controls.size(); i++)
	{
		controls[i]->OnResize(0, 0);
	}
}