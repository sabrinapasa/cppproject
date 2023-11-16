#include<iostream>
#include"cinemahall.h"
#include"concert.h";
#include"Theatre.h";

using namespace std;

int main() {
	CinemaHall cinema;
	cinema.printCinemaHall();
	cout << endl;
	int seats[] = { 3, 4, 5, 8 };
	CinemaHall c1(4,seats);
	cout << c1[2] << endl;
	cout << !c1;
	int val = (int)c1;
	cout << endl << val << endl;
	CinemaHall c2;
	c2 = c1;
	CinemaHall c3 = ++c1;
	CinemaHall c4 = c1++;
	CinemaHall c5;
	c5 + 3;
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
	cout << t1[2] << endl;
	cout << !t1;
	int value = (int)t1;
	cout << endl << value << endl;
	Theatre t3 = ++t1;
	Theatre t4 = t1++;
	Theatre t5;
	t5 + 3;
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