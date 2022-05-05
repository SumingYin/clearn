#include <iostream>

using namespace std;
int main()
{

    const char * constChar = "const";
    char * nonConstChar = "noConst";
    char charArray [] = "charArray";
    char * newChar = new char [4] {'a','b','c'};


    cout << constChar << endl;
    cout << nonConstChar << endl;
    cout << charArray << endl;
    cout << newChar << endl;
    // nonConstChar[0] = 'K'; // intend to change const string value,Segmentation fault(core dumped),can't not change
    // cout << nonConstChar << endl;
    
    charArray[0] = 'K';
    cout << charArray << endl; // you can change the value of a Array

    delete [] newChar;
    // delete [] constChar; // can't do it
    // delete [] nonConstChar; // can't do it,free():invalid pointer
    // delete [] charArray; // delete [] can only use for new exp ,Aborted (core dumped)

    return 0;

}