#include<iostream>
#include"cinemahall.h"
#include"concert.h"
#include"Theatre.h"
#include"sportMatch.h"
#include"event.h"
#include"FILES.h"

using namespace std;

void createPlace() {
	int choice = 0;
	cout << "1. Create a cinema." << endl;
	cout << "2. Create a theatre." << endl;
	cout << "3. Create a concert." << endl;
	cout << "4. Create a stadium." << endl;
	cout << "Choose a number from 1 to 4 : ";
	cin >> choice;
	if (choice == 1) {
		cin.get();
		createCinema();
		return;
	}
	if (choice == 2) {
		cin.get();
		createTheatre();
		return;
	}
	if (choice == 3) {
		cin.get();
		createConcert();
		return;
	}
	if (choice == 4) {
		cin.get();
		createStadium();
		return;
	}
}

void adminMenu() {
	cout << "1. Create an event place." << endl;
	cout << "2. Create an event." << endl;
	cout << "3. Associate the place with the event." << endl;
	cout << "4. Exit." << endl;
	cout << "Choose a number from 1 to 4 : ";
}

void exploreAdminMenu() {
	int choice = 0;
	do { 
		adminMenu();
		cin >> choice;
		if (choice == 1) {
			createPlace();
			continue;
		}
		if (choice == 2) {
			//createEvent();
			continue;
		}
		if (choice == 3) {
			//createTickets();
			continue;
		}
	} while (choice!=4);
}

int main() {
	//CinemaHall cinema;
	//cinema.printCinemaHall();
	//cout << endl;
	//int seats[] = {3, 4, 5, 8};
	/*CinemaHall c1(4, seats);
	cout << c1.sum();
	cout << endl;
	cout << c1.min();
	cout << endl;
	cout << c1.max();
	cout << c1[2] << endl;
	cout << !c1;
	int val = (int)c1;
	cout << endl << val << endl;
	CinemaHall c2;
	c2 = c1;
	if (c2 == c1)
	{
		cout << endl << "They are the same";
	}
	else {
		cout << endl << "They not are the same";
	}

	if (c1 >= c2)
	{
		cout << endl << "The first cinema is bigger or equal to the second one";
	}
	else {
		cout << endl << "The first cinema is not bigger or equal to the second one";
	}

	CinemaHall c3;
	c3 = ++c1;
	cout << endl<< c3;
	CinemaHall c4;
	c4= c1++;
	cout << endl<< c4;
	CinemaHall c5;
	CinemaHall c6;
	CinemaHall c7;
	c6 = c5 + 3;
	c7 = c2 - 2;
	//c6 = 3 + c5;
	cout << endl<< c6;
	//c6.printCinemaHall();
	cout << endl << c7;
	//c7.printCinemaHall();
	cout << endl << c2;
	//c2.printCinemaHall();*/
	

	cout << endl;
	cout << endl;


	/*Theatre t1(4, seats, 50);
	cout << t1.sum();
	cout << endl << t1.min();
	cout << endl << t1.max();
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
	Theatre t6;
	Theatre t7;
	t6 = t5 + 3;
	cout << t6 << endl;
	t6 = 3 + t5;
	cout << t6 << endl;
	t7 = t2 - 2;
	cout << t7 << endl;
	cout << endl;
	if (t2 == t1)
	{
		cout << endl << "They are the same";
	}
	else {
		cout << endl << "They not are the same";
	}

	if (t1 >= t2)
	{
		cout << endl << "The first theatre is bigger or equal to the second one";
	}
	else {
		cout << endl << "The first theatre is not bigger or equal to the second one";
	}*/


	/*Concert concert1(100, "Calea Victoriei no. 4");
	concert1.printConcert();
	concert1.setName("Music Night");
	cout << endl;
	cout << endl;
	Concert concert2;
	concert2 = concert1;
	concert2.printConcert();
	cout << endl;
	cout << concert1[0] << endl;
	cout << !concert1;
	int val1 = (int)concert1;
	cout << endl << val1 << endl;
	if (concert2 == concert1)
	{
		cout << endl << "They are the same";
	}
	else {
		cout << endl << "They not are the same";
	}

	if (concert1 >= concert2)
	{
		cout << endl << "The first cinema is bigger or equal to the second one";
	}
	else {
		cout << endl << "The first cinema is not bigger or equal to the second one";
	}

	Concert concert3 = ++concert1;
	Concert concert4 = concert1++;
	Concert concert5;
	Concert concert6;
	Concert concert7;
	Concert concert8;
	concert6 = concert5 + 3;
	concert7 = concert2 - 2;
	concert6 = 3 + concert5;
	cout << endl << concert6;
	cout << endl << concert7;
	cout << endl << concert2;
	concert8 = 500 - concert2;
	cout << endl << concert8;
	//Concert newConcert;
	//cin >> newConcert;
	cout << endl;
	bool free = concert1.assessFreeEntrance();
	cout << endl << free;*/

	/*Stadium s1(2, "Ghencea nr. 30");
	Stadium s2 = s1;
	cout << s2;
	cout << endl;
	if (s2 == s1)
	{
		cout << endl << "They are the same";
	}
	else {
		cout << endl << "They not are the same";
	}

	if (s1 >= s2)
	{
		cout << endl << "Stadium 1 is bigger or equal to the second one";
	}
	else {
		cout << endl << "Stadium 1 is not bigger or equal to the second one";
	}
	cout << endl << (int)s1;
	Stadium s3;
	s3 = s2;
	cout << s3;
	Stadium s4;
	s4 = s2 + 3;
	cout << s4;
	Stadium s5;
	s5 = s4 - 2;
	cout << s5;
	cout << endl << !s5;
	Stadium s6;
	s6 = s3++;
	cout << endl << s6;
	Stadium s7;
	s7 = ++s4;
	cout << endl << s7;
	int value = (int)s3;
	cout << endl << value;*/

	//exploreAdminMenu();

	Event e1("Magic Night", "30.12.2023", 4, 1, CONCERT);
	cout << e1;
	Event e2;
	e2 = e1;
	cout << e2;
	cout << endl;
	Event e3;
	cin >> e3;
	cout << endl;
	cout << e3;

	return 0;
}