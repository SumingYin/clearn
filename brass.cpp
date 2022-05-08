// bank.cpp --bank account class methods

#include <iostream>
#include "brass.h"

// format stuff
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f,precis p);
using std::cout;

using std::endl;
using std::string;

Brass::Brass(const std::string s,long an,double bal)
{
	fullName = s;
	acctNum = an;
	balance = bal;
}



void Brass::Deposit(double amt)
{
	if(amt < 0)
		cout << "Negative deposit not allowed; " << "deposit is cancelled.\n";
	else
		balance += amt;
}

// don't need to add virtual on it 
void Brass::Withdraw(double amt)
{
	// set up ###.## format
	format initialState  = setFormat();
	precis prec = cout.precision(2);
	if(amt < 0)
		cout << "Withdraw amount must be positive; " << "withdrawal cancelled.\n";
	else if(amt <= balance)
		balance -= amt;
	else
		cout << "Withdraw amount of $" << amt
		     << " exceeds your balance.\n"
		     << "Withdreawal cancelled.\n";
	restore(initialState,prec);

}

double Brass::Balance()const
{
	return balance;
}

void Brass::ViewAcct() const
{
	// set up ###.## format
	format initialState = setFormat();
	precis prec = cout.precision(2);
	cout << "Client: " << fullName << endl;
	cout << "Account Number: " << acctNum << endl;
	cout << "Balance: $" << balance << endl;
	restore(initialState,prec); // restore original format
}

// BrassPlus Methods
BrassPlus::BrassPlus(const std::string & s,long an,double bal,double ml,double r):Brass(s,an,bal)// base class initialize
{
	maxLoan = ml;
	owesBank = 0.0;
        rate = r;	
}
BrassPlus::BrassPlus(const Brass & ba,double ml,double r):Brass(ba)// base class initialize
{
	maxLoan = ml;
	owesBank = 0.0;
        rate = r;	
}
// redefine how ViewAcct() works
void BrassPlus::ViewAcct() const
{
	// set up ###.## format
	format initialState = setFormat();
	precis prec = cout.precision(2);
	Brass::ViewAcct(); // display base portion,use base class "Brass::" way to do it 
	cout << " Maxmum loan: $ " << maxLoan << endl;
	cout << "Owed to bank: $ " << owesBank<< endl;
	cout.precision(3); // ###.### format
	cout << "Loan Rate:  " << 100 * rate <<"%\n";
	restore(initialState,prec);
}
// redefine how Withdraw() works
void BrassPlus::Withdraw(double amt)
{
	// set ###.## format
	format initialState = setFormat();
	precis prec = cout.precision(2);
	double bal = Balance();// BrassPlus don't redefine this function,so we can just use it,different from ViewAcct() method.
	if(amt <= bal)
		Brass::Withdraw(amt);
	else if(amt <= bal + maxLoan - owesBank)
	{
		double advance = amt - bal;
		owesBank += advance * (1.0 + rate);
		cout << "Bank advance: $" << advance << endl;
		cout << "Fiance charge: $"<< advance * rate << endl;
		Deposit(advance);
		Brass::Withdraw(amt);
	}
	else
		cout << "Credit limit exceeded.Transaction cancelled.\n";
	restore(initialState,prec);



}

format setFormat()
{
	// set up ###.## format
	return cout.setf(std::ios_base::fixed,std::ios_base::floatfield);
}

void restore(format f,precis p)
{
	cout.setf(f,std::ios_base::floatfield);
	cout.precision(p);
}

