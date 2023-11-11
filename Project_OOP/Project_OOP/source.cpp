#include<iostream>
#include"cinemahall.h"

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
	return 0;
}