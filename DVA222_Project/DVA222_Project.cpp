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
#include "CheckBoxGroup.h"
#include "RadioButtonGroup.h"
#include "ImageBox.h"

using namespace std;


int _tmain(int argc, char** argv)
{
    //A new object of Button type is create and passed to the InitOGL function. 
    //From that point the control is handed over to the OpenGL window and stays there until the user closes the Window.
    //This means after calling the InitOGL function no further lines of code in the main function are executed until we close the Window.
    //------------------------------------------------------------------------------------------------------------------------------------

    ControlBase* button = new MyButton(20,20,190,60);
	ControlBase* panel = new Panel(500, 100, 190, 60, 0);
	ControlBase* panel2 = new Panel(400, 120, 190, 60, 0.1);
	ControlBase* window = new Window(30, 30, 700, 400, 0.0f);
	ControlBase* label = new TextLabel(10, 22, 50, 20);
	ControlBase* image = new ImageBox(225, 20, 180, 115);

	ControlBase* checkBoxGroup = new CheckBoxGroup(50, 200, 250, 150);
	ControlBase** checkBoxButtons = new ControlBase *[3];
	ControlBase* radioButtonGroup = new RadioButtonGroup(400, 200, 250, 150);
	ControlBase** radioButtons = new ControlBase *[3];

	for (int i = 0; i < 3; i++)
	{
		checkBoxButtons[i] = new CheckBoxButton(10, i * 40 + 20);
		static_cast<CheckBoxGroup *>(checkBoxGroup)->AddControl(*checkBoxButtons[i]);
		radioButtons[i] = new MyRadioButton(20, i * 40 + 35, 7);
		static_cast<RadioButtonGroup *>(radioButtonGroup)->AddControl(*radioButtons[i]);
	}

	static_cast<TextLabel *>(label)->ChangeText("This is a string inside a panel!");
	static_cast<Panel *>(panel)->AddControl(*label);
	static_cast<Panel *>(panel)->SetBackgroundColor(150, 0, 0);
	static_cast<Panel *>(panel2)->SetBackgroundColor(0, 0, 150);

	static_cast<Panel *>(window)->SetBackgroundColor(100, 100, 100);
	static_cast<Window *>(window)->AddControl(*panel);
	static_cast<Window *>(window)->AddControl(*panel2);
	static_cast<Window *>(window)->AddControl(*button);
	static_cast<Window *>(window)->AddControl(*image);
	static_cast<Window *>(window)->AddControl(*radioButtonGroup);
	static_cast<Window *>(window)->AddControl(*checkBoxGroup);

	InitOGL(argc, argv, window);

    delete button;
	return 0;
}
