#include <iostream>
#include "classLearnstock00.h"

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


void Stock::show()
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