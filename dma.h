// dma.h -- inheritance and dynamic memory allocation
#ifndef DMA_H_
#define DMA_H_
#include <iostream>


// Base Class Using DMA
class baseDMA
{
private:
	char * label;// base class will use new function to allocate memory
	int rating;
public:
	baseDMA(const char * l = "null",int r = 0);
	baseDMA(const baseDMA & rs);// copy constructor
	virtual ~baseDMA();
	baseDMA & operator=(const baseDMA & rs); // assignment operator
	friend std::ostream & operator<<(std::ostream & os,const baseDMA & rs); // friend function to use cout
};

// derived class without DMA
// no destructor needed
// uses implicit copy constructor
// uses implicit assignment operator
class lacksDMA:public baseDMA // here,it doesn't use new to allocate memory to itself.
{
private:
	enum { COL_LEN = 40};
	char color [COL_LEN];
public:
	lacksDMA(const char * c = "blank",const char * l = "null",int r = 0);
	lacksDMA(const char * c,const baseDMA & rs);// note that:use baseDMA type to initialize baseDMA private data member
	friend std::ostream & operator<<(std::ostream & os ,const lacksDMA & rs);
};

// derived class with DMA,constructor should use new to allocate memory for itself
// it should redefine 1.copy constructor,2.destructor and 3.assignement operator

class hasDMA:public baseDMA
{
private:
	char * style;
public:
	hasDMA(const char * s = "none",const char * l = "null",int r = 0);
	hasDMA(const char * s,const baseDMA & rs);
	hasDMA(const hasDMA & hs); // copy constructor
	~hasDMA(); // should redefine destrutor
	hasDMA & operator=(const hasDMA & rs);
	friend std::ostream & operator<<(std::ostream & os,const hasDMA & rs);
};






#endif

