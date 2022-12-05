#include <iostream>
#include <string>
#define CRT_SECURE_NO_WARNINGS
#include "Location.h"

using namespace std;
int main() {
	/*int* seats= new int[10];
	for (int i = 0; i < 10; i++)
	{
		cout << "SEAT" << i + 1 << ": ";
		cin >> seats[i];
	}
	cout <<"this is seats: "<< seats;*/

	int seats[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
	int seat[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };
	Location Ghencea(seats, 16, 4, STAND1);
	Location Giulesti(seat, 13, 4, STAND2);
	Location Rocar(Ghencea);
	//Ghencea = Giulesti; //operator=(Location &, Location &)
	//Ghencea = Giulesti;
	/*Ghencea.setNoSeats();
	Giulesti.setNoSeats();*/
	/*cout << endl << "ghencea noseats: " << Ghencea.getNoSeats();
	cout << endl << "giulesti noseats: " << Giulesti.getNoSeats();*/
	/*Ghencea > Giulesti;*/
	//if (Ghencea > Giulesti)  // operator>(Location& Ghencea, Location & Giulesti)
	//	cout << "true";
	//else cout << "false";
	Rocar.printStand();
	//operator+(location& ghencea, int value)
	/*cout << Ghencea;*///operator<<(&ostream out, Location&location )
	cin >> Ghencea;
	cout << Ghencea;
	/*Ghencea.printStand();*/


}