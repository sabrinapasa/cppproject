#include<iostream>
#include"cinemahall.h"
#include"concert.h";
#include"Theatre.h";

using namespace std;

int main() {
	//CinemaHall cinema;
	//cinema.printCinemaHall();
	//cout << endl;
	int seats[] = { 3, 4, 5, 8 };
	/*CinemaHall c1(4, seats);
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

	CinemaHall c3 = ++c1;
	CinemaHall c4 = c1++;
	CinemaHall c5;
	CinemaHall c6;
	CinemaHall c7;
	c6 = c5 + 3;
	c7 = c2 - 2;
	c6 = 3 + c5;
	//c7 = 2 - c2;
	cout << endl<< c6;
	//c6.printCinemaHall();
	cout << endl << c7;
	//c7.printCinemaHall();
	cout << endl << c2;
	//c2.printCinemaHall();*/
	

	cout << endl;
	cout << endl;


	/*Theatre t1(4, seats, 50);
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


	Concert concert1(100, "Calea Victoriei no. 4");
	concert1.printConcert();
	concert1.setName("Music Night");
	cout << endl;
	cout << endl;
	Concert concert2;
	concert2 = concert1;
	concert2.printConcert();
	cout << endl;
	
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
	concert6 = concert5 + 3;
	concert7 = concert2 - 2;
	concert6 = 3 + concert5;
	cout << endl << concert6;
	cout << endl << concert7;
	cout << endl << concert2;

	return 0;
}