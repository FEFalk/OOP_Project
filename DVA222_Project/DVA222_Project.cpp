// DVA222_Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Graphix.h"
#include "glut.h"
#include "MyButton.h"
#include "Container.h"
#include "Panel.h"
#include "Window.h"
#include "MyRadioButton.h"
#include "CheckBoxButton.h"

using namespace std;


int _tmain(int argc, char** argv)
{
    //A new object of Button type is create and passed to the InitOGL function. 
    //From that point the control is handed over to the OpenGL window and stays there until the user closes the Window.
    //This means after calling the InitOGL function no further lines of code in the main function are executed until we close the Window.
    //------------------------------------------------------------------------------------------------------------------------------------

    ControlBase* button = new MyButton(10,10,190,60);
	ControlBase* panel = new Panel(200, 200, 190, 60, 0);
	ControlBase* container = new Container(100, 100, 190, 60, 0);
	ControlBase* window = new Window(100, 100, 700, 400, 0.0f);
	ControlBase* radioButton = new MyRadioButton(50, 200);
	ControlBase* checkBoxButton = new CheckBoxButton(50, 300);

	static_cast<Panel *>(panel)->SetBackgroundColor(0, 255, 255);

	static_cast<Window *>(window)->AddControl(*panel);
	static_cast<Window *>(window)->AddControl(*button);
	static_cast<Window *>(window)->AddControl(*radioButton);
	static_cast<Window *>(window)->AddControl(*checkBoxButton);

	InitOGL(argc, argv, window);

    delete button;
	return 0;
}
