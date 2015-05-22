
#ifndef STRUCTS_H
#define STRUCTS_H
struct Color
{
	int r;
	int g;
	int b;
	Color(){}
	Color(int r, int g, int b)
	{
		this->r=r;
		this->g=g;
		this->b=b;
	}
};

typedef struct _point
{
	_point()
	{
	}
	_point(double x, double y)
	{
		X = x;
		Y = y;
	}
	double X;
	double Y;
}Point;


#endif

