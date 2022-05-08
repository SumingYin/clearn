// usett1.cpp -- using base class and derived class

#include <iostream>
#include "tabtenn1.h"

void show(const TableTennisPlayer & rt);
int main(void)
{
	using std::cout;
	using std::endl;
	TableTennisPlayer player1("Tara","Boomdea",false);
	RatedPlayer rplayer1(1140,"Mallory","Duck",true);
	rplayer1.Name(); // derived object uses base method
	if(rplayer1.HasTable())
		cout << ": has a table.\n";
	else
		cout << ": hasn't a table.\n";
	player1.Name(); // basse object uses base method;
	if(player1.HasTable())
		cout << ": has a table\n";
	else
		cout << ": hasn't a table\n";
	cout << "Name: ";
	rplayer1.Name();
	cout << "; Rating: " << rplayer1.Rating() << endl;
	// inialize RatedPlayer using TableTennisPlayer object 
	RatedPlayer rplayer2(1212,player1);
	cout << "Name: ";
	rplayer2.Name();
	cout << "; Rating :" << rplayer2.Rating() << endl;

	RatedPlayer addPlayer(5000,"yin","suming",true);
	cout << "Name: ";
	addPlayer.Name();
	cout << ":hightest rating: " <<addPlayer.Rating() << endl;

	// demenstrate the relationship between father and son class
	show(player1);// works with TableTennisPlayer argument;
	show(rplayer1); // works with RatedPlayer argument; 

	return 0;
}

// this function will show the relationship between base class reference(or pointer) and derived class reference(or pointer)
// you can change the reference rt to pointer,it also works
void show(const TableTennisPlayer & rt)
{	
	using std::cout;
	cout << "Name: ";
	rt.Name();
	cout << " \n Table: ";
	if(rt.HasTable())
		cout << "yes\n";
	else
		cout<< "no \n";
}









