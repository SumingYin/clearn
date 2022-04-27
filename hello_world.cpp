#include <iostream>
#include <string>
#include "coordin.h"
using namespace std;
class Entity
{

private:
    int m_x = 0, m_y = 0, *m_z = nullptr;
    mutable int var = 0; // this definition means we can change the of value of var in const method!
                         // mutable key word will really useful in debug!
    std::string m_Name = "test";
    mutable int m_DebugCount = 0;

public:
    // const & return's additional means this reference we can't change but we can assign to other value;
    const std::string &GetName() const
    {
        m_DebugCount++;
        return m_Name;
    }

    // here const means we can't not change value of this class Entity attribute in this function!
    int GetX() const
    {
        var = 2; // we can change mutable var
        // m_y = 33; // we can't change m_y
        return m_x;
    }
    const int *const GetZ() const
    {
        return m_z; // three const here : first and second for return value means contents and the address of this pointer towards can't be modified !
                    // the third means this method can't change the value of this pointer.
    }

    void setX(int x)
    {
        m_x = x;
    }
    int GetY()
    {
        return m_y;
    }
};

void PrintEntity(const Entity &e)
{

    cout << e.GetX() << endl;
    // cout << e.GetY() << endl; // this statement is wrong because GetY() function isn't const! this const reference prevent us changing the value of this Entity object
}
extern const int states;
extern const double dval;
void changeConstValueToSeeInternalChange()
{

    cout << "const double dval = 1.0 in coordin.h" << endl;
    cout << dval << endl;
    cout << "extern const int states = 50 in coordin.h" << endl;
    cout << states << endl;
    // then we change the value and use it in other cpp file to see the change of these const value
    // for example,we can see the value in complexStructure.cpp
    cout << "Now , change the const value with some tricks" << endl;
    const int *pic = &states;
    cout << "const pointer of states" << endl;
    cout << pic << endl;
    // here pi and pd cause segmentation fault,and something important bring here
    // you are not allowed to cast away const for an object which started its life as a const object.
    // These object may live in read-only memory.
    // if dval define in this function as const doubel dval = 10.0,we can use const_cast<double *> to change its value,here we can't do that!
    // the simplest example of read-only vs read-write memory is a string constant:
    // char * p = "string";p[0] = 'a' ; // segfault
    // char q[] = "string";q[0] = 'a';// "atring"
    int *pi = const_cast<int *>(pic);
    double *pd = const_cast<double *>(&dval);
    *pi = 100;
    *pd = 2.0;
}

int main()
{
    string str1;
    // changeConstValueToSeeInternalChange(); add this will have segmentation fault,you can see the detail above.
    cout << "progress here" << endl;

    cout << "extern const int states = 50 in coordin.h" << endl;
    cout << states << endl;
    cout << "const double dval = 1.0 in coordin.h" << endl;
    cout << dval << endl;
    const Entity e;                 //
    std::string name = e.GetName(); //
    e.GetName();
    e.GetName();
    cout << name << endl;
    name = "change value";
    cout << name << endl;

    cout << endl;
    cout << "You wont't regret it !" << endl;
    cout << "Come up and C++ me some time. ";
    return 0;

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
}