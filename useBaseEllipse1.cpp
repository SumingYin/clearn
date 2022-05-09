// useBaseEllipse1.cpp -- some verification of abstract class
// compile with BaseEllipseABC.cpp

#include "BaseEllipseABC.h"
#include <iostream>

using namespace std;
int main()
{
	double x = 10;
	double y = 8;
	double a = 3;
	double b = 4;
	double r = 5;


	// generate class object
	Ellipse oval(x,y,a,b);
	Circle cir(x,y,r);
	// call some functions
	cir.move(0,0); // because cir redefine the virtual function of ABC,so it can use it,but below line don't do like circle do;although,ABC class already define the move function,we can't direct to use it,maybe we can use it like "BaseEllipseABC::move(nx,ny);".
	oval.move(0,0); 
	cout << oval << endl;
	cout << cir << endl;
	cout << " Ellipses area: " << oval.getArea() << endl;
	cout << "   Circle area: " << cir.getArea() << endl;
	return 0;
}



