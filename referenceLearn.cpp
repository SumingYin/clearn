#include <iostream>
#include <string>
using namespace std;
struct free_throws
{
    string name;
    int made;
    int attempts;
    float percent;
};

const free_throws &
clone(free_throws &ft);
const free_throws &clone(free_throws &ft)
{
    free_throws *pt = new free_throws; // this can work to use new ,different from the book;
    // free_throws *pt; // same as the book but doesn't work,this situation can't pass the compiler,it causes segmentation fault (core dumped),we can't assign value to address that we dont know.
    *pt = ft; // primer c++ page 268 says that it hides the use of "new" action; use breakpoint to see what happened,I think something wrong in the book;
    (*pt).name = "Mike";
    return *pt;
}

int main()
{
    free_throws three = {"Minnie Max",7,9};
    const free_throws & jolly = clone(three);
    cout << jolly.name << endl;
    cout << "jolly address's :" << &jolly << endl;
    cout << "three address's :" << &three << endl;
    cout << "different address" << endl; // this means you can create new value in heap but not stack.
    return 0;
}