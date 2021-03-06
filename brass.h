// brass.h -- bank account classes
#ifndef BRASS_H_
#define BRASS_H_
#include <string>

//Brass Account Class
class Brass
{
private:
	std::string fullName;
	long acctNum;
	double balance;
public:
	Brass(const std::string s = "Nullbody",long an = -1,double bal = 0.0);
	void Deposit(double ant);
	virtual void Withdraw(double amt); // virtual function 
	double Balance() const;
	virtual void ViewAcct() const;
	virtual ~Brass(){}; // need the virtual destructor function,so that destructor function can depend on the real object of class,if reference is father,it can destructor father memory;if reference is son,it can destructor son memory,then father memory.
};

// Brass Plus Account Class
class BrassPlus:public Brass // must be public inherit
{
private:
	double maxLoan;
	double rate;
	double owesBank;
public:
	BrassPlus(const std::string & s= "Nullbody",long an = -1,double bal = 0.0,double ml = 500,double r = 0.11125);
	BrassPlus(const Brass & ba,double ml = 500,double r = 0.11125);
	virtual void ViewAcct() const;
        virtual	void Withdraw(double ant);
	void ResetMax(double m){maxLoan = m;}
	void ResetRate(double r){rate = r;}
	void ResetOwes(){owesBank = 0;}
};



#endif
