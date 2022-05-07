// stock00.h -- Stock class interface
// version 00
#ifndef STOCK00_H_
#define STOCK00_H_

// usestock0.cpp use this class and do some experiments to it ,I find something interesting :)
#include <string>

class TestdifclaInOtherClass // this class
{
private:
    int privateInt;
public:
    TestdifclaInOtherClass();
    void show() const;
    int getPrivateInt() const; // must const
};
class Stock
{
private:
    std::string company;
    long shares; // own the number of stocks
    double share_val; // val of each share
    double total_val; // total shares stock value
    // void set_tot() is also a Inline function since its definition in class anouncement
    // this is implicit way to make the set_tot() a inline function,you can separate it to classLearnstock00.cpp and explictly to use inline keyword.
    void set_tot() // private function ,only in this class or friendly class can visit this function
    {
        total_val = shares * share_val;
    }
public:
    // default constructor
    Stock();
    Stock(const std::string &co,long n=0,double pr=0.0);
    ~Stock(); // do-nothing destructor
    // just give the anoucements are enough
    void acquire(const std::string & co,long n,double pr); // acquire stocks 
    void buy(long num,double price);// buy num of stocks
    void sell(long num,double price);
    void update(double price); // update the price of each share
    void show() const;
    const Stock & topval(const Stock & s) const;// something weird happened,in program we can use s.shares,this means we can access private member in this class 
    int topInt(const Stock & s,const TestdifclaInOtherClass & t); // const Stock & topval(const Stock & s) const func: s.shares can directly access private member,but here t can't,because t is different
                                                                  // we can use t.getPrivateInt() to get private member value , and only the value.
}; // not semicolon at the end



#endif //  