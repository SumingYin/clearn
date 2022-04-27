#include "ABC.h"

void A::f1()
{
    return;
}

void B::f2(){
    f1(); // func f2 can visit A::f1()
    // can't visit i1
    j1;// func f2 can visit A::j1
    return ;
}
void C::f3()
{   j2; // can visit j2
    // can't visit j1
    f1();
    f2();
    
}
void main()
{
    B b;
    // object b can't visit j1
    b.f1();
    C c;
    c.f2(); // object c can visit B::f2(), A::f1()
    c.f1();

}