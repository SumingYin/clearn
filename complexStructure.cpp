#include <iostream>
using namespace std;
enum colors
{
    red,orange,yellow,green,blue
};

struct person
{
    int arms;
    int legs;
    int head;
};
union one4all
{
    int int_val;
    long long_val;
    double double_val;
};

int main()
{   
    // create array typename valuename [number];
    int intArray [10] {}; // define and initialize
    char flower[10] = "rose"; 
    flower[0] = 'R';
    cout << flower << endl; // because flower is array ,we can change its value;
    int length = sizeof(flower);
    for(int i=0;i<10;i++){
        intArray[i] = i;
        cout << intArray[i] << endl;

    }


    colors color;
    color = red;
    switch (color)
    {
    case red:
        cout << "red" << endl;
        break;
    case orange:
        cout << "orange" << endl;
        break;

    default:
        break;
    }

    person sumingYin = {2,2,1};
    one4all unionOne ;
    unionOne.int_val = 4;

    person * ptperson = new person; // a pointer towards person data
    ptperson -> arms = 3;
    ptperson -> head = 1;
    delete ptperson; // delete match new ,delete can only free the memory applied with new ,if another pointer also point the new allocated address
    int * psome = new int [10];
    delete [] psome; // the way that delete free array's memory ,must add [] 
    short tell [40] = {0,1,2};
    
    short (*pas) [40] = &tell; // pas means the pointer pas towards address that short numbers is 40; 
    cout << *pas[0] << endl; // we can see the value is 0
    cout << *pas[1] << endl; // the value is not 1 ,but is random value we can't get,this is the wrong way to use it. 
    // when we want to know the type of an variable ,we can move this variable in its statement and see what is type of this variable.
    short * ptell = tell; // this is the address of tell array's first element 
    // or something just like this
    short * aptell = &tell[0]; // the same thing like ptell,the array's first element's memory address
    
    // create string const
    
    const char * pStr = "abc"; // if we add "const" before char , this means we can't change the "abc" in this statement 
    cout << pStr << endl; // original value
    // pStr[0] = 'd'; // if char * pStr = "abc" in the beginning add const we cant change the "abc" string value,
                    // if we dont add ,when we run this code ,it also show mistake(run time error) in the console.
    // cout << pStr << endl; // changed value,segmentation fault (core dumped), we can't change the constant string value
    string aStr = "abc";
    // aStr[0] = "d"; this statement cant pass the compiler,we can see the error is aStr is const char * means we cant change the value of "abc";
    // so how we can change the value of "abc"?
    aStr.erase(0,1); // if we want to change the value of "abc",we can use function in string to do it.
    aStr.assign("another string");
    cout << aStr << endl;




    
}