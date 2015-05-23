
#include "stdafx.h"
#include "Window.h"

Window::Window()
{
	hit = pressed = false;
}
Window::Window(int locX, int locY, int width, int height, int order)
	: Panel(locX, locY, width, height, order)
{
	hit = pressed = false;
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

void Window::OnResize(int width, int height)
{
	/*resize(width, height);*/
}

void Window::OnMouseMove(int button, int x, int y)
{
	Container::OnMouseMove(button, x, y);
	if (x>position.X && x < position.X + Width && y>position.Y && y < position.Y + Height)
		hit = true;
	else
		hit = false;
	if (pressed)
	{
		position.X = x;
		position.Y = y;

		for (int i = 0; i < controls.size(); i++)
		{
			controls[i]->SetPosition(controls[i]->GetOffset().X + position.X, controls[i]->GetOffset().Y + position.Y);
		}
	}
}

void Window::OnMouseDown(int button, int x, int y)
{
	Container::OnMouseDown(button, x, y);
	if (hit && button == MOUSE_LEFT)
		pressed = true;
	else
		pressed = false;
}

void Window::OnMouseUp(int button, int x, int y)
{
	Container::OnMouseUp(button, x, y);
	if (pressed)
		pressed = false;
}