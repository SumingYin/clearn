#include <iostream>
#include "classLearnstock00.h"

// constuctors

Stock::Stock()
{
    company = "no name";
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const std::string & co,long n,double pr)
{
    company = co;
    if(n < 0)
    {
        std::cout << "Number of shares can't be negative;"
                  << company << "shares set to 0.\n";
        shares = 0;
    }else{
        shares = n;
    }
    share_val = pr;
    set_tot();
}

Stock::~Stock()
{

}


void Stock::acquire(const std::string &co, long n, double pr)
{
    company = co;
    if (n < 0)
    {
        std::cout << "Number of shares can't be negative ;"
                  << company << " shares set to 0.\n";
        shares = 0;
    }else
    {
        shares = n;
        share_val = pr;
        set_tot();
    }
}


void Stock::buy(long num,double price)
{
    if(num < 0)
    {
        std::cout << "Number of shares pruchased can't be negative. "
                  << "Transaction is aborted.\n";
    }else{
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num,double price)
{
    using std::cout;
    if(num < 0){
        cout << "Number of shares sold can't be negative."
             << "Transaction is aborted.\n";
    
    }
    else if( num > shares)
    {
        cout << "You can't sell more than you have!"
             << "Transaction is aborted.\n";
    }
    else{

        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}


void Stock::show() const
{
    using std::cout;
    using std::ios_base;
    // set format to #.###
    ios_base::fmtflags orig = cout.setf(ios_base::fixed,ios_base::floatfield);
    std::streamsize prec = cout.precision(3);
    cout << "Company: " << company
         << "Shares: " << shares << '\n';
    cout << "Share Price: $" << share_val;
    // set format to #.##
    cout.precision(2);
    cout << " Total Worth:$ " << total_val << '\n';
    // retore original format
    cout.setf(orig,ios_base::floatfield);
    cout.precision(prec);
}


const Stock & Stock::topval(const Stock & s) const{
    if(s.total_val > total_val) // here reference s can visit the private value with "." way,what happened?
    {   std::cout << "Stock object s's private member shares,here can also visit :" << s.shares << std::endl;
        // this may indicate that in this class we can use Stock object with "." way to visit any private member
        // only if your Class is Stock? how about other class? let me do another experiment
        return s;
    }else
    {   std::cout << "Stock object s's private member shares,here can also visit : " << s.shares << std::endl;
        return *this;
    }
        
}

// test:different class can use "." way to access private member
// we have reference t point TestdifclaInOtherClass,in this class
int Stock::topInt(const Stock & s,const TestdifclaInOtherClass & t)
{   // different from topval function above,the compiler shows errors when we use t.privateInt,we can't access here 
    // this means different class can't access private value,but the same class can ,perfect :)
    // if(t.privateInt > s.shares) // we can't use this way
    // {
    //     return t.privateInt;
    // }else{
    //     return s.shares;
    // }
    // use this way,we pass the compiler correctly
    int tPrivateInt = t.getPrivateInt(); // getPrivateInt() must const because we pass the arguement t is const & 
    if(tPrivateInt > s.shares)
    {
        return tPrivateInt;
    }else{
        return s.shares;
    }

}

TestdifclaInOtherClass::TestdifclaInOtherClass()
{
    privateInt = 10;
}

void TestdifclaInOtherClass::show() const{
    std::cout << "t private member's " << privateInt << std::endl;
}

int TestdifclaInOtherClass::getPrivateInt() const{
    return privateInt;
}