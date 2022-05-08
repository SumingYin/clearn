// usett1.cpp -- using base class and derived class

#include <iostream>
#include "tabtenn1.h"

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

	return 0;
}
