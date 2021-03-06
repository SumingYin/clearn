// string1.cpp -- String class methods
#include <cstring>
#include "string1.h"
using std::cin;
using std::cout;

// initializing static class member
int String::num_strings = 0; // must be like this

// static method
int String::HowMany()
{
    return num_strings;
}

//class methods
String::String(const char * s)
{   
    std::cout << "from String(const char *s )temp num_strings val : " << num_strings << std::endl;
    len = std::strlen(s);
    str = new char(len+1);
    std::strcpy(str,s);
    num_strings++;
}

String::String()
{
    len = 4;
    str =new char[1];
    str[0] = '\0';
    num_strings++;
    std::cout << "from String() and temp num_strings val : " << num_strings << std::endl;
}

String::String(const String & st) // copy constructor
{   
    num_strings++;
    std::cout << "from String(const String & st) and temp num_strings val : " << num_strings << std::endl;
    len = st.len;
    str = new char [len + 1];
    std::strcpy(str,st.str);
}


String::~String()
{

}

// overloaded operator methods
// assign a String to a String
String & String::operator=(const String & st)
{
    if(this == &st)
        return *this;
    delete [] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str,st.str);
    return *this;
}

// assign a C string to a String
String & String::operator=(const char *s)
{
    delete [] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str,s);
    return *this;
}

// read-write char access for non-const String
char & String::operator[](int i)
{
    return str[i];
}

// read-only char access for const String
const char & String::operator[](int i) const
{
    return str[i];
}

// overloaded operator friends,don't need to add friend before the function
bool operator<(const String&st1,const String & st2)
{
    return (std::strcmp(st1.str,st2.str));
}

bool operator>(const String&st1,const String & st2)
{
    return st2 < st1;
}

bool operator==(const String&st1,const String & st2)
{
    return (std::strcmp(st1.str,st2.str)==0);
}

// simple String output
ostream & operator << (ostream & os,const  String & st)
{
    os << st.str;
    return os;
}

istream & operator>>(istream & is,  String & st)
{   
    char temp[String::CINLIM];
    is.get(temp,String::CINLIM);
    if(is)
        st = temp;
    while(is && is.get()!='\n')
        continue;
    
    return is;
}






