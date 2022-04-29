// usestock2.cpp -- using the Stock class
// compile with classLearnstock00.cpp

#include <iostream>
#include "classLearnstock00.h"

const int STKS = 4;
int main()
{
    // create an array of initialized objects
    Stock stocks[STKS] = {
        Stock("NanoSmart",12,20.0),
        Stock("Boffo Objects",200,12.0),
        Stock("Monolithic Obelisks",130,3.25),
        Stock("Fleep Enterprises",60,6.50)
    };
    std::cout << "Stock holdings:\n";
    int st;
    const Stock * top = &stocks[0];
    for(st=0;st < STKS;st++ )
    {   
        top  = &top->topval(stocks[st]);
    }
    // now top points to the most valuable holding
    std::cout << "\n Most valuable holding:\n";
    top->show();
    return 0;

}