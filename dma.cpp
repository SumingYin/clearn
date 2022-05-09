// dma.cpp -- dma class methods
#include "dma.h"
#include <cstring>

// baseDMA methods

baseDMA::baseDMA(const char * l,int r)
{
	label = new char[std::strlen(l) + 1];
	std::strcpy(label,l);
	rating =r;
}

baseDMA::baseDMA(const baseDMA & rs)
{
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label,rs.label);
	rating = rs.rating;
}


// because base class use new to allocate memory,we should define the deconstrutor function
baseDMA::~baseDMA()
{
	delete [] label; // free memory of label
}

baseDMA & baseDMA::operator=(const baseDMA & rs)
{
	if(this == &rs)
		return *this;
	delete [] label; // free old memory
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label,rs.label);
	rating = rs.rating;
	return *this;


}

std::ostream & operator << (std::ostream & os,const baseDMA & rs)
{
	os << "Label: " << rs.label << std::endl;
	os << "Rating: " << rs.rating << std::endl;
	return os;
}

// here,lacksDMA class,not use new method in its constructor

lacksDMA::lacksDMA(const char * c,const char * l,int r):baseDMA(l,r)
{
	std::strncpy(color,c,39);
	color[39] ='\n';
}

lacksDMA::lacksDMA(const char * c,const baseDMA & rs):baseDMA(rs)
{
	std::strncpy(color,c,COL_LEN - 1);
	color[COL_LEN - 1] = '\0';

}

std::ostream & operator<<(std::ostream & os,const lacksDMA &rs)
{
	os << (const baseDMA & ) rs; // here,convertion to baseDMA type
	os << "Color: " << rs.color << std::endl;
	return os;
}

// here,hasDMA class use new to allocate memory for itself,
// we should redefine copy constructor,destructor and assignment operator

hasDMA::hasDMA(const char * s,const char * l,int r):baseDMA(l,r)
{
	style = new char[std::strlen(s)  + 1];
	std::strcpy(style,s);
}

hasDMA::hasDMA(const char * s,const baseDMA & rs):baseDMA(rs) 
{
	style = new char[std::strlen(s) + 1];
	std::strcpy(style,s);
}

hasDMA::hasDMA(const hasDMA & hs):baseDMA(hs) // note that:"hs" not "rs",copy construtor// invoke base class copy constructor
{
	style = new char[std::strlen(hs.style) + 1];
	std::strcpy(style,hs.style);
}

hasDMA::~hasDMA() // should redefine because it uses new in constructor
{
	delete [] style;
}

hasDMA & hasDMA::operator=(const hasDMA & hs) // should redefine assignment operator
{
	if(this == &hs)
		return *this;
	baseDMA::operator=(hs); // copy base portion 
	delete [] style;
	style = new char[std::strlen(hs.style) + 1];
	std::strcpy(style,hs.style);
	return *this;
}

std::ostream & operator<<(std::ostream & os,const hasDMA & rs)
{
	os << (const baseDMA & ) rs;// convertion
	os << "Style: " << rs.style << std::endl;
	return os;
}





