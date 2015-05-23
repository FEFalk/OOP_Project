#pragma once
#include <string>
#include <stdlib.h>
#include "glut.h"
#include "Struct.h"

using namespace std;

//===================================
//
//  C A N ' T   T O U C H   T H I S
//
//===================================


//This is the Base class for all the controls that you develop. This is the Mother of all Controls

class ControlBase
{
public:
	ControlBase();
    ControlBase(int x, int y, int w, int h, float z);
	~ControlBase(void);

    //Event Handlers
	virtual void OnLoaded();
	virtual void OnPaint(void);		
	virtual void OnKeyboard(unsigned char key, int x, int y);	
	virtual void OnMouseDown(int button, int x, int y);
	virtual void OnMouseUp(int button, int x, int y);
	virtual void OnMouseMove(int button, int x, int y);
	virtual void OnResize(int width, int height);

	Point GetOffset();
	void SetOffset(int x, int y);
	Point GetPosition();
	void SetPosition(int x, int y);
	void SetSortOrder(float newSortOrder);

protected:
	Point Offset;
	Point position;
	float SortOrder;
	int Width;
	int Height;
	friend void resize(int w, int h);
};