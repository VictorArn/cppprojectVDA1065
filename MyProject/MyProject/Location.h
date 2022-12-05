#pragma once
#include <iostream>
#include <string>
#define CRT_SECURE_NO_WARNINGS
using namespace std;


enum ZONES {STAND1, STAND2};

class Location {
private:
	int noRows = 0;
	int* seats = nullptr;
	ZONES zone = STAND1;
	int noSeatsPerRow = 0;
	 int NoSeats = 0;

public:
	const static int MAX_NO_SEATS_PER_ROW = 30;

public:

	//defining setters and getters

	void setNoRows(int value) {
		if (value <= 0)
		{
			throw "No.of rows should be at least equal to 1";
		}
		this->noRows = value;
	}

	int getNoRows() {
		return this->noRows;
	}
	void setNoSeatsPerRow(int value) {
		if (value <= 0)
		{
			throw "No.of seats/row should be at least equal to 1";
		}
		this->noSeatsPerRow = value;
	}
	
	int getNoSeatsPerRow() {
		return this->noSeatsPerRow;
	}
	void setSeats(int* NewSeats, int noSeatsPerRow) {
		if (noSeatsPerRow <= 0)
		{
			throw "Number of rows is not ok";
		}
		if (noSeatsPerRow > MAX_NO_SEATS_PER_ROW)
		{
			throw "MAX number of seats is 30";
		}
		if (NewSeats == nullptr)
			throw "Pointer is not ok, thus it's null";
		if (this->seats != nullptr)
			delete[] this->seats;
		this->seats = new int[noSeatsPerRow];
		for (int i = 0; i < noSeatsPerRow; i++) {
			this->seats[i] = NewSeats[i];
			
		}
		this->noSeatsPerRow = noSeatsPerRow;
	}

	//void setNoSeats() {
	//	for (int j = 0; j < this->noRows; j++)
	//	{
	//		for (int i = 0; i < this->noSeatsPerRow; i++)
	//		{
	//			NoSeats++;
	//		}
	//	}

	//}
	
	void setNoSeats() {
		
		if (this->noRows != 0) {
			 this->NoSeats = this->noRows * this->noSeatsPerRow;
		}
		else
			this->NoSeats = 0;
		

	}
	int* getSeats() {
		int* copy = copyArray(this->seats, this->noSeatsPerRow);
		return copy;
	}

	void setZone(ZONES zone) {
		this->zone = zone;
	}
	
	ZONES getZone() {
		return this->zone;
	}
	int getNoSeats() {
		return this->NoSeats;
	}


	//default constructor
	Location() {
		this->setZone(STAND1);

	}
	//constructor with all attributes for a stand
	Location(int* seats, int noSeatsPerRow, int noRows, ZONES zone) {
		this->setSeats(seats, noSeatsPerRow);
		this->setNoRows(noRows);
		this->setZone(zone);
		this->setNoSeats();
	}

	//class destructor
	~Location() {
		this->deleteSeats();
	}

	//class copy constructor
	Location(Location& obj) {
		this->setSeats(obj.seats, obj.noSeatsPerRow);
		this->setNoRows(obj.noRows);
		this->setZone(obj.zone);
		this->NoSeats = obj.NoSeats;

	}

	void deleteSeats() {
		if (this->seats != nullptr) {
			delete[] this->seats;
			this->seats = nullptr;
			this->noSeatsPerRow = 0;
		}
	}

	//operator=(Location&, Location&)
	void operator=(Location& source) {
		if (this == &source)
		{
			cout << endl << "The locations provided are the same";
			
		}
		else {
			this->setSeats(source.seats, source.noSeatsPerRow);
			this->setZone(source.zone);
			this->noRows = source.noRows;
			this->NoSeats = source.NoSeats;
		}
	
	}


	bool operator>(Location& right) {
		if (this->NoSeats > right.NoSeats)
		{
			return true;
		}
		else return false;
	}
	//defining operator+ for adding rows to the location
	Location  operator+(int rows) {
		Location copy = *this;
		copy.noRows = rows;
		return copy;
	}

private:
	//static method to copy an dynamically allocated array of numbers
	static int* copyArray(int* array, int size) {
		int* copy = new int[size];
		for (int i = 0; i < size; i++)
		{
			copy[i] = array[i];
		}
		return copy;

	}

	//function to print the seats by row along with there numerical coding
public:
	void printStand() {
		for (int j = 0; j < this->noRows; j++)
		{
			cout << j + 1 << " ";
			for (int i = 0; i < this->noSeatsPerRow; i++)
			{
				cout << this->seats[i] << " ";
				/*NoSeats++;*/
			}
			cout << endl;
		}
		cout << "Number of total seats is: " << NoSeats;

	}
	friend void operator>>(istream& in, Location& location);
};

void operator<<(ostream& out, Location location) {
	out << endl;
	out << "No rows is:";
	out << location.getNoRows()<<endl;
	out << "Zone is:";
	out << location.getZone()<<endl;
	out << "No seats per row is:";
	out << location.getNoSeatsPerRow()<<endl;
	int* seats = location.getSeats();
	out << "The seats are disposed like this: " << endl;
	for (int j = 0; j < location.getNoRows(); j++)
	{
		out << j + 1 << "      ";
		for (int i = 0; i < location.getNoSeatsPerRow(); i++)
		{
			out << seats[i] << " ";
			/*NoSeats++;*/
		}
		out << endl;
	}
	out << "Number of total seats is: " << location.getNoSeats();
	

}


void operator>>(istream& in, Location& location) {
	cout << " \nInput no of rows: ";
	in >> location.noRows;
	cout << endl << " Input  Zone(0-stand1, 1-stand2): ";
	int a;
	in >> a;
	if (a == 0) {
		location.setZone(STAND1);
	}
	else
		location.setZone(STAND2);

	cout << endl << " Input number of seats per row: ";
	in >> location.noSeatsPerRow;
	cout << endl << " The seat disposal will be automatically done...";
	//delete[]location.seats;
	//location.seats = new int[location.noSeatsPerRow];
	//for (int j = 0; j < location.noRows; j++)
	//{
	//	cout<<"Row" << j + 1 << ": ";
	//	for (int i = 0; i < location.noSeatsPerRow; i++)
	//	{
	//		in >> location.seats[i];
	//		/*NoSeats++;*/
	//	}
	//	cout << endl;
	//}
	


}



