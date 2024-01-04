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

void chooseSeat(int* seats, int rows) {
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
}


void displaySeatArrangementForCinema_(const vector<vector<int>>& seats) {
    cout << "Seat Arrangement:" << endl;
    for (const auto& row : seats) {
        for (const auto& seat : row) {
            cout << seat << " ";
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