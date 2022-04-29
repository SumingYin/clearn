// usestock0.cpp -- the client program
// compile with classLearnstock00.cpp
#include <iostream>
#include "classLearnstock00.h"

int method(int x,int y)
{
    return (int)x / y * 2;
}
int main()
{
    Stock fluffy_the_cat;
    fluffy_the_cat.acquire("NanoSmart",20,12.5);
    // fluffy_the_cat.show();
    // fluffy_the_cat.buy(15,18.125);
    // fluffy_the_cat.show();
    // fluffy_the_cat.sell(400,20.00);
    // fluffy_the_cat.show();
    // fluffy_the_cat.buy(300000,40.125);
    // fluffy_the_cat.show();
    // fluffy_the_cat.sell(300000,0.125);
    // fluffy_the_cat.show();
    Stock s;
    const Stock & as = s;
    
    s.acquire("nothing",25,12.5);
    const Stock & aref = s.topval(fluffy_the_cat);
    // as.shares = 30; // you can't access the private member 
    // const Stock & aaref = s.topval(fluffy_the_cat);
    const TestdifclaInOtherClass t ;
    int top = s.topInt(s,t);
    
    return 0;

}