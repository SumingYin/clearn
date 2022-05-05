// randwalk.cpp -- using the Vector class
// compile with the vect.cpp file 
#include <iostream>
#include <cstdlib> // rand(),srand() prototypes
#include <ctime> // time() prototypes
#include "vector.h"


int main()
{   

    // test about cin
    char temp [5];
    std::cin.get(temp,5);
    std::cout << "temp :" << temp << std::endl;
    char c = std::cin.get();
    
    while( c!='\n')
    {
        std::cout << c << std::endl;
        c = std::cin.get();
    }
        


    using namespace std;
    using VECTOR::Vector;
    srand(time(0)); // seed random number generator
    double direction;
    Vector step;
    Vector result(0.0,0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    cout << "Enter target distance (q to quit): ";
    while (cin >> target)
    {
        cout << "Enter step  length :";
        if(!(cin >> dstep))
            break;

        while(result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep,direction,Vector::POL);
            result = result + step;
            steps++;
        }

        cout << "After " << steps << " steps ,th e subject " 
                "has the following location:\n";
        cout << result << endl;
        result.polar_mode();
        cout << " or \n" << result <<endl;
        cout << "Average outward distance per step = "
             << result.magval() / steps << endl;
        steps = 0 ;
        result.reset(0.0,0.0);
        cout << "Enter target distance (q to quit): ";




    }
    cout << "Byte !\n";
    cin.clear();
    while(cin.get()!='\n')
        continue;
    return 0;

}