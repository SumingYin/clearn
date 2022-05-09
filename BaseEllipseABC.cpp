// BaseEllipse.cpp -- define methods of Base EllipseABC,Ellipse,Circle
#include "BaseEllipseABC.h"
#include "math.h"

BaseEllipseABC::BaseEllipseABC(double x1,double y1)
{
	x = x1;
	y = y1;
}
	  
// in hearder .h file "move" function is defined as pure virtual function 
// here,we can define its concrete content funtion to see what happened.
void BaseEllipseABC::move(double nx,double ny)
{
	x = nx;
	y = ny;
}
// friend function to output center position
ostream & operator<<(ostream & os,BaseEllipseABC & bea)
{
	os << "(x,y) = " << "("<< bea.x << "," << bea.y << ")" <<"\n" ;
	return os;
}



// Ellipse's constructor use
Ellipse::Ellipse(double x1,double y1,double a1,double b1):BaseEllipseABC(x1,y1),a(a1),b(b1){};

// double getArea() is also pure virtual function,we can do not define this function.

double Ellipse::getArea() const
{
	return a * b * M_PI;
}
// if we want to use the ABC's move function,we should first announce it as virtual function and here define it in this way,Let me try it.
void Ellipse::move(double nx,double ny)
{
	BaseEllipseABC::move(nx,ny);
}

// Circle's constructor use
Circle::Circle(double x1,double y1,double r1):BaseEllipseABC(x1,y1),r(r1){}
double Circle::getArea() const
{
	return r * r * M_PI;
}

// virtual function redefined 
void Circle::move(double nx,double ny)
{
//	x = nx + 1;// x is ABC's private member,we can't use these like this.
//	y = ny + 1;
//	1.the first way to solve this is that:decalre x and y as "protected" member;
//	2.the second way to solve this is that:use the ABC class,define some function to return private member reference,so we can access its value and change it.But this way it can also change in public scope,not very good.
//	here we try to use the first way.
	x = nx + 1;
	y = ny + 1;
}	


