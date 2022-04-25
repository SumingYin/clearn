#include <iostream>
#include <string>
using namespace std; 
class Entity
{

private:
    int m_x =0 ,m_y = 0,*m_z = nullptr;
    mutable int var = 0; // this definition means we can change the of value of var in const method!
                    // mutable key word will really useful in debug!
    std::string m_Name = "test";
    mutable int m_DebugCount = 0;

public:
    // const & return's additional means this reference we can't change but we can assign to other value;
    const std::string & GetName() const{
        m_DebugCount++;
        return m_Name;
    }

    // here const means we can't not change value of this class Entity attribute in this function!
    int GetX() const{
        var = 2; // we can change mutable var 
        //m_y = 33; // we can't change m_y
        return m_x;
    }
    const int* const GetZ() const{
        return m_z; // three const here : first and second for return value means contents and the address of this pointer towards can't be modified !
                    // the third means this method can't change the value of this pointer.

    }

    void setX(int x)
    {
        m_x = x;
    
    }
    int GetY(){
        return m_y;
    }

};

void PrintEntity(const Entity & e){

    cout << e.GetX() << endl;
   // cout << e.GetY() << endl; // this statement is wrong because GetY() function isn't const! this const reference prevent us changing the value of this Entity object

}

int main(){
    string str1;
    
    const Entity e; // 
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
    const int * a = new int;
    int * const b = new int;
    const int * const c = new int;

    // *a = 2; // you can't do that!
    // a = &MAX_AGE; // you can
    // *b = 80; // yes, you can
    // b = &MAX_AGE; // no ,you can't
    // *c = 30; // no
    // c  = &MAX_AGE; // no also no


}