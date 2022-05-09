// BaseEllipseABC.h -- abstract class to verify some function
#include <iostream>
using std::ostream;
class BaseEllipseABC
{
protected:// here,when I first define x and y,they are private.But it should be shared within sons class 
	double x; 
	double y; // (x,y) means its center point

public:

	BaseEllipseABC(double x1 = 0.0,double y1 =0.0);
        virtual	~BaseEllipseABC(){}

	/*
	 *
	 *Here,I need some explanation to function move.
	 What I want the effect is:first, When we don't define the function "move",we should use the default one;
	 second,when we redefine this function we should use what we define.
	 * */
	virtual void move(double nx,double ny) = 0; // "=0" means pure virtual function

	virtual double getArea() const= 0; // Ellipse and circle should have different way to calculate area
	friend ostream & operator<<(ostream & os, BaseEllipseABC & bea);
};

class Ellipse:public BaseEllipseABC
{
private:// oval:tuoyuan
	double a;
	double b;
public:
	Ellipse(double x1=0.0,double y1=0.0,double a1=0.0,double b1=0.0);
	virtual ~Ellipse(){}
	// here,with function "move",we want to use the default Base defined function move
	// getArea function we should define depend on concrete graph
	virtual double getArea() const ;
	virtual void move(double nx,double ny);
};

class Circle:public BaseEllipseABC
{

private:
	double r;
public:

	Circle(double x1=0.0,double y1=0.0,double r1=0.0);
	virtual void move(double nx,double ny);
	virtual double getArea() const;
};










