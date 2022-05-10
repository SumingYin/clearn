// studentc.h -- defining a Student class using containment
#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <string>
#include <valarray>

class Student
{
private:
	typedef std::valarray<double> ArrayDb;
	std::string name ;
	ArrayDb scores;
	// private method for scores output
	std::ostream & arr_out(std::ostream & os)const;
public:
	Student():name("Null Student"),scores(){}
	explicit Student(const std::string & s):name(s),scores(){}// use string constructor"string(const char *) to initialize the private member data name
	explicit Student(int n):name("Nully"),scores(n){} // valarray<double> scores(n) means an array of n double elements
	// let me explain the "explicit Student(int n):name("Nully"),scores(n)" constuctor,here should use the explicit to demenstrate that we should not use "Student st = 50",because it will be misunderstood,st[0] = 50 and that's not correct.
	Student(const std::string & s,const ArrayDb & a):name(s),scores(a){}
	Student(const std::string & s,int n):name(s),scores(n){}
	Student(const char * str,const double * pd,int n):name(str),scores(pd,n){}// an array of n elements initialized to the first n elements of pd

	~Student(){};
	double Average() const;
	const std::string & Name() const;
	double & operator[](int i);// use return reference,we can change its value as left
	double operator[](int i) const;// get the ith value of scores
	// friend
	// input
	friend std::istream & operator >> (std::istream & is,Student & stu); // 1 word
	friend std::istream & getline   (std::istream & is,Student & stu); // 1 line
	// output
	friend std::ostream & operator << (std::ostream & os,const Student & stu);
};


#endif
