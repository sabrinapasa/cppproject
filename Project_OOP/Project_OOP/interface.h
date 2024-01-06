#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"cinemahall.h"

using namespace std;

void displaySeatArrangementForCinema(int* seats,int rows) {
	int* available_nr_seats = seats;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < available_nr_seats[i]; j++) {
			cout << " " << "*";
		}
		cout << endl;
	}
	delete[] available_nr_seats;
}

//void chooseSeat(int** seats, int rows) {
//	int row;
//	int* available_seats_per_row = new int[rows];
//	for (int i = 0; i < rows; i++) {
//		available_seats_per_row[i] = (*seats)[i];
//	}
//	//int position_on_row;
//	cout << endl << "Enter the row number: ";
//	cin >> row;
//	if (row-1 < 0 && row-1 >=rows) {
//		cout << "Row number not aveilable!";
//	}
//	if (available_seats_per_row[row-1] == 0) {
//		cout << "No seat available on this row";
//	}
//	else{
//		int seat;
//		seat = available_seats_per_row[row - 1];
//		cout << endl << "Row number is: " << row;
//		cout << endl << "Seat is: " << seat;
//		available_seats_per_row[row - 1]--;
//		for (int i = 0; i < rows; i++) {
//			(*seats)[i] = available_seats_per_row[i];
//		}
//	}
//	delete[] available_seats_per_row;
//}


//void chooseSeat(int** seats, int rows) {
//	int row;
//	cout << endl << "Enter the row number: ";
//	cin >> row;
//
//	if (row < 1 || row > rows) {
//		cout << "Invalid row number!" << endl;
//		return;
//	}
//
//	if ((*seats)[row - 1] == 0) {
//		cout << "No seat available in this row" << endl;
//		return;
//	}
//	//int seat = (*seats)[row - 1];
//	int seat = seats[row - 1];
//	cout << endl << "Row number is: " << row << endl;
//	cout << "Seat is: " << seat << endl;
//
//	(*seats)[row - 1]--;
//}

/*void chooseSeat(int* seats, int rows) {
    int row;
    cout << endl << "Enter the row number: ";
    cin >> row;

    if (row < 1 || row > rows) {
        cout << "Invalid row number!" << endl;
        return;
    }

    if (seats[row - 1] == 0) {
        cout << "No seat available in this row" << endl;
        return;
    }

    int seat = seats[row - 1];
    cout << endl << "Row number is: " << row << endl;
    cout << "Seat is: " << seat << endl;

    seats[row - 1]--;
}*/


void displaySeatArrangementForCinema_(const vector<vector<int>>& seats) {
    cout << "Seat Arrangement:" << endl;
    for (int i = 0; i < seats.size();i++) {
        for (int j = 0; j < seats[i].size(); j++) {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }
}

void chooseSeat(vector<vector<int>>& seats) {
    int row, seat;
    cout << "Enter the row number: ";
    cin >> row;
    cout << "Enter the seat number: ";
    cin >> seat;

    if (row < 1 || row > seats.size() || seat < 1 || seat > seats[row - 1].size()) {
        cout << "Invalid row or seat number!" << endl;
        return;
    }

    if (seats[row - 1][seat - 1] == 0) {
        cout << "Seat already taken!" << endl;
        return;
    }

    seats[row - 1][seat - 1] = 0;
    cout << "Seat successfully reserved!" << endl;
}







void displaySeatArrangementForStadium_(const vector<vector<vector<int>>>& s) {
    cout << "Seat Arrangement:" << endl;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < s[i].size(); j++) {
            for (int k = 0; k < s[i][j].size(); k++) {
                cout << " " << s[i][j][k];
            }
            cout << endl;
        }
        cout << endl;
        cout << endl;
    }
}

void chooseSeat_Stadium(vector<vector<vector<int>>>& s) {
    int sector;
    int row;
    int seat;
    cout << endl << "Choose the sector: ";
    cin >> sector;
    if (sector < 1 || sector > s.size()) {
        cout << "Invalid sector number!";
        return;
    }
    cout << endl << "Choose the row from your sector: ";
    cin >> row;
    if (row < 1 || row > s[sector-1].size()) {
        cout << "Invalid row number!";
        return;
    }
    cout << endl << "Choose your seat: ";
    cin >> seat;
    if (seat < 1 || seat > s[sector-1][row-1].size()) {
        cout << "Invalid seat number!";
        return;
    }
    if (s[sector-1][row-1][seat-1] == 0) {
        cout << endl << "Seat has already by taken";
        return;
    }
    s[sector - 1][row - 1][seat - 1] = 0;
    cout << "Seat successfully reserved!" << endl;
}






void buyTicketConcert(int& volume_persons) {
    if (volume_persons == 0) {
        cout << endl << "No tickets available";
        return;
    }
    cout << endl << "Ticket bought successfully!";
    volume_persons--;
}

void displayAvailableVolume(int& volume_persons) {
    cout << endl << "Available tickets places to the concert " << volume_persons << " !";
}




struct Theatre_structure {
    vector<vector<int>> seatsTheatre = {
        {1, 2, 3, 4, 5, 6},
        {1, 2, 3, 4,5,6, 7, 8},
        {1, 2,3 ,4 ,5 ,6 ,7 ,8, 9},
        {1, 2, 3, 4, 5,6 ,7 ,8, 9,10}
    };
    vector<int> VIP_Places = { 1, 2, 3, 4, 5, 6 };
};

void displaySeatArrangementForTheatre_(Theatre_structure& t) {
    cout << endl << "Seat arrangement" << endl;
    for (int i = 0; i < t.seatsTheatre.size(); i++) {
        for (int j = 0; j < t.seatsTheatre[i].size(); j++) {
            cout << t.seatsTheatre[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl << "VIP seats" << endl;
    for (int i = 0; i < t.VIP_Places.size(); i++) {
        cout << t.VIP_Places[i] << " ";
    }
    cout << endl;
}

void chooseSeat_Theatre(Theatre_structure& t) {
    int row;
    int seat;
    int choice;
    cout << endl << "If you want a regular ticket press  1 or press 2 fro a VIP place: ";
    cin >> choice;
    if (choice == 1) {
        cout << "Choose the row: ";
        cin >> row;
        if (row < 1 || row > t.seatsTheatre.size()) {
            cout << "Invalid row number!";
            return;
        }
        cout << "Choose seat: ";
        cin >> seat;
        if (seat < 1 || seat > t.seatsTheatre[row - 1].size()) {
            cout << "Invalid seat number!";
            return;
        }
        if (t.seatsTheatre[row - 1][seat - 1] == 0) {
            cout << "The seat has already been taken!";
            return;
        }
        t.seatsTheatre[row - 1][seat - 1] = 0;
        cout << "Seat was successfully chosen!";
    }
    if (choice == 2) {
        cout << "Choose VIP seat: ";
        cin >> seat;
        if (seat < 1 || seat>t.VIP_Places.size()) {
            cout << "Invalid seat number!";
            return;
        }
        if (t.VIP_Places[seat - 1] == 0) {
            cout << "The seat has already been taken!";
            return;
        }
        t.VIP_Places[seat - 1] = 0;
        cout << "VIP seat was successfully chosen!";
    }
    if (choice != 1 || choice != 2) {
        cout << "Invalid choice!";
        return;
    }
}