#include <stdio.h>
#include <iostream>


typedef void (*afunction)(double,int*);
typedef void (*bfunction)(int);
typedef bfunction (*cfunction)(int,afunction); // cfunction is pointer with parameters int and pointer of afunction,return bfunction pointer.



void bcase(int n)
{
	printf("bcasefunction:number is %d\n",n);
}


void acase(double n,int * n1)
{
	printf("acasefunction:double number is %f,int pointer number is %d\n",n,*n1);
}


bfunction ccase(int n1,afunction af) // a cfunction case 
{	
	// use afunction to do something,afunction has two parameters double n and int * n1;
	// here we create temp double value to show the  process
	double apar = 0.9;
	(*af)(apar,&n1); // this will print acasefunction's words first
		
	printf("this is ccase function to show return function pointer\n");
	return &bcase;
}

// website version to implement this situation

typedef int (*ptr)(int *);
typedef ptr(*pm)();


int fun1(int *y)
{
	printf("geeks!!\n");
	return *y + 10;
}
// fun() is a function with
// return type ptr
ptr fun()
{
	printf("HELLO\n");

	// or return fun1
	// or in (*pt)(int *) = fun1;
	// return pt
	return &fun1;
}
int main()
{
	int a = 10;
	pm u = fun;
	/*
	 * Above line assigns 'u' which is a type 'pm' to an array of size 1 which has functin pointers as its elements and these function pointers in turn return other function pointer which
	 * points to other functions.Now this 'p' array contains a function pointer 'u' which points to fun() and pointer which points to fun1().
	 */

	int (*(*p[1])())(int*) = {u};
	printf("%d\n",(*p[0]())(&a));
	// the verson of mine
	cfunction csimulation = ccase;

	printf("%d",csimulation);
	// announce a ccopy value to point the function created,note that the anouncement of ccopy,we should not announce it to "void (*ccopy(int,afunction))(int) = csimulation;",this is wrong.
	void (*(*ccopy)(int,afunction))(int) = csimulation; // let me see wether this will work ?Yes,it works!
	ccopy(31,&acase)(52);
	void (*(*b[1])(int,afunction))(int) = {csimulation}; // anouncement b to represent cfuntion value,you can use the cfuntion to define a cfuntion value,here is simulate previous function and seccessed
	(*b[0])(1,&acase)(2);

	return 0;

}




