// sayings1.cpp -- using expanded String class
// compile with string1.cpp
#include <iostream>
#include "string1.h"
const int ArSize = 11;
const int MaxLen = 81;

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    String name;
    cout << "Hi,what's your name ?\n";
    cin >> name;
    cout << name << ", please enter up to " << ArSize
                 <<  " short sayings <empty line to quit>:\n";
    String sayings[ArSize]; // array of Objects
    char temp[MaxLen]; // temporary string storage
    int i;
    // const char * testc = "the ArSize string";
    // sayings[ArSize] = testc; // munmap_chunk():invalid pointer,Aborted (core dumped)
    cout << "class object ArcSize length's value " << sayings[ArSize] << endl; // this can output some unknown value and doesn't call error from compiler
    // cout << "class object ArcSize length's value " << sayings[ArSize + 1] << endl; // this results segmentation fault (core dumped) doesn't show output,different from above line 
    for(i = 0;i < ArSize;i++)
    {
        cout << i + 1 << ": ";
        cin.get(temp,MaxLen);
        while(cin && cin.get() !='\n')
            continue;
        if(!cin || temp[0] == '\0') // empty line?
            break;
        else
            sayings[i] = temp;// overloaded assignment
    }

    int total = i; // total # of lines read
    if(total > 0)
    {
        cout << "Here are your sayings:\n";
        for(i = 0;i < total;i++)
        {
            cout << sayings[i][0] << ": " << sayings[i] << endl;
        }

        int shortest = 0;
        int first = 0;
        for(i = 1;i < total;i++)
        {
            if(sayings[i].length() < sayings[shortest].length())
                shortest = i;
            if(sayings[i] <sayings[first])
                first = i;
        }
        cout << "Shortest saying :\n" << sayings[shortest] << endl;
        cout << "First alphabetically: \n" << sayings[first] << endl;
        cout << "This program used " << String::HowMany() << " String objects.Bye.\n";
        // this program used 11 String object,why?
        // it should be 10 at most,think about it.

    }
    else
    {
        cout << "No input!Bye.\n";
    }
    return 0;




}