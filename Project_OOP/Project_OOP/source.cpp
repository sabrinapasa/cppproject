#include<iostream>
#include"cinemahall.h"
#include"concert.h";
#include"Theatre.h";

using namespace std;

int main() {
	CinemaHall cinema;
	cinema.printCinemaHall();
	int seats[] = { 3, 4, 5, 8 };
	CinemaHall c1(4,seats);
	CinemaHall c2;
	c2 = c1;
	cout << endl;
	cout << endl;
	c2.printCinemaHall();
	cout << endl;
	cout << endl;
	Theatre t1(4, seats, 50);
	Theatre t2;
	t2 = t1;
	t2.printTheatre();
	cout << endl;
	cout << endl;
	Concert concert1(100, "Calea Victoriei no. 4");
	concert1.printConcert();
	concert1.setName("Music Night");
	cout << endl;
	cout << endl;
	Concert concert2;
	concert2 = concert1;
	concert2.printConcert();
	cout << endl;
	return 0;
}