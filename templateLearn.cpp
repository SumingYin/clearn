#include <iostream>
using namespace std;

// template use in linkage time
template <typename T>
void Print(T value)
{
    cout << value << endl;
}

// class
// template use concrete int type and unknown type T
template <typename T, int N>
class Array
{
private:
    T m_Array[N];

public:
    int GetSize() const
    {
        return N;
    }
};

int main()
{   

    char charArray [5] = {'2','2','2','2','2'};
    char name [20] = {0};
    cin.get(name ,20);
    char * charAddress = charArray;
    cout << charArray << endl;
    int rocs{};
    char achar = 'a';
    int charVar = achar;
    cout <<  achar << " " << charVar << endl;
    Array<int, 5> array;
    cout << array.GetSize() << endl;
    Print(5);
    Print("Hello");
    Print(5.5);
    // another format
    Print<int>(5); // this means the type you pass to T is int;
    Print<string>("Hello world!");

    cout << "    /" << endl;
    cout << "   /" << endl;
    cout << "  /" << endl;
    cout << " /" << endl;
    cout << "/" << endl;

    // const position with different results
    const int MAX_AGE = 90;
    const int *a = new int;
    int *const b = new int;
    const int *const c = new int;

    // *a = 2; // you can't do that!
    // a = &MAX_AGE; // you can
    // *b = 80; // yes, you can
    // b = &MAX_AGE; // no ,you can't
    // *c = 30; // no
    // c  = &MAX_AGE; // no also no

    return 0;
}