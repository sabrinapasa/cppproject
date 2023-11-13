#pragma once
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

class Theatre {
	int nrRows;
	char address[51];
	int* nrSeats;
	int nrSeatsVIP;
	bool isAvailable;

	static int  MIN_NR_ROWS;
	static int  MAX_NR_ROWS;
	static int MIN_SEATS_PER_ROW;
	static int MAX_SEATS_PER_ROW;
	static int MIN_SEATS_VIP;
	static int MAX_SEATS_VIP;

public:
	
	Theatre() {
		this->isAvailable = false;
		this->address[0] = '\0';
		this->nrRows = 0;
		this->nrSeatsVIP = 0;
		this->nrSeats = nullptr;
	}

	Theatre(const int nrRows, const int* nrSeats, const int nrSeatsVIP) {
		if (nrRows < MIN_NR_ROWS || nrRows > MAX_NR_ROWS)
			throw new exception("Value out of range!");
		this->nrRows = nrRows;
		this->nrSeats = new int[nrRows];
		for (int i = 0; i < nrRows; i++)
			this->nrSeats[i] = nrSeats[i];
		this->nrSeatsVIP = nrSeatsVIP;
		this->isAvailable = false;
		this->address[0] = '\0';
	}

	Theatre(const int nrRows, const int* nrSeats, const char* address, const int nrSeatsVIP) {
		this->nrSeatsVIP = nrSeatsVIP;
		if (nrRows < MIN_NR_ROWS || nrRows > MAX_NR_ROWS)
			throw new exception("Value out of range!");
		this->nrRows = nrRows;
		this->nrSeats = new int[nrRows];
		for (int i = 0; i < nrRows; i++)
			this->nrSeats[i] = nrSeats[i];
		this->isAvailable = false;
		if (strlen(address) > 50) {
			throw new exception("Address too long!");
		}
		strcpy_s(this->address, 51, address);
	}

	void setAvailability(bool isAvailable) {
		this->isAvailable = isAvailable;
	}

	bool IsAvailable() const {
		return this->isAvailable;
	}

	void setNrRows(int nrRows) {
		if (nrRows < MIN_NR_ROWS || nrRows > MAX_NR_ROWS)
			throw new exception("Value out of range!");
		if (nrRows == this->nrRows)
			return;
		this->nrRows = nrRows;
		if (this->nrSeats != nullptr)
			delete[] this->nrSeats;
	}
	int getNrRows() const {
		return this->nrRows;
	}

	void setNrSeats(int nrRows, int* nrSeats) {
		if (nrSeats == nullptr)
			return;
		this->setNrRows(nrRows);
		if (this->nrSeats != nullptr)
			delete[] this->nrSeats;
		this->nrSeats = new int[nrRows];
		for (int i = 0; i < nrRows; i++)
			this->nrSeats[i] = nrSeats[i];
	}

	int* getNrSeats() const {
		if (this->nrSeats == nullptr)
			return NULL;
		int* copy = new int[this->nrRows];
		for (int i = 0; i < this->nrRows; i++)
			copy[i] = this->nrSeats[i];
		return copy;
	}

	void setNrSeatsVIP(int nrSeatsVIP) {
		if (nrSeatsVIP < MIN_SEATS_VIP || nrSeatsVIP > MAX_SEATS_VIP)
			throw new exception("Value out of range!");
		this->nrSeatsVIP = nrSeatsVIP;
	}

	int getNrSeatsVIP() {
		return this->nrSeatsVIP;
	}

	void setAddress(const char* address) {
		if (strlen(address) > 50) {
			throw new exception("Address too long!");
		}
		strcpy_s(this->address, 11, address);
	}

	char* getAddress() const {
		char* copy = new char[strlen(this->address) + 1];
		strcpy_s(copy, 51, this->address);
		return copy;
	}

	~Theatre() {
		if (this->nrSeats != nullptr)
			delete[] this->nrSeats;
	}

	Theatre(const Theatre& t) {
		this->isAvailable = t.isAvailable;
		this->nrSeatsVIP = t.nrSeatsVIP;
		strcpy_s(this->address, 11, t.address);
		this->nrRows = t.nrRows;
		if (t.nrSeats == nullptr)
			this->nrSeats = nullptr;
		else {
			this->nrSeats = new int[t.nrRows];
			for (int i = 0; i < t.nrRows; i++)
				this->nrSeats[i] = t.nrSeats[i];
		}
	}

	void printTheatre() const {
		cout << "Address: ";
		if (this->address[0] == 0)
			cout << "No address";
		else
			cout << this->address;
		cout << endl;
		cout << "Number of seats at VIP: ";
		if (this->nrSeatsVIP == 0)
			cout << "No of seats at VIP";
		else
			cout << this->nrSeatsVIP;
		cout << endl;
		cout << "Number of rows: " << this->nrRows << endl;
		if (this->nrSeats == nullptr)
			cout << "No seats defined";
		else {
			cout << "Number of seats: ";
			for (int i = 0; i < this->nrRows; i++)
				cout << this->nrSeats[i] << " ";
		}
	}

	Theatre& operator=(const Theatre& t) {
		if (this == &t)
			return *this;

		this->isAvailable = t.isAvailable;
		this->nrSeatsVIP = t.nrSeatsVIP;
		strcpy_s(this->address, 51, t.address);

		if (t.nrRows == 0) {
			if (this->nrSeats != nullptr) {
				delete[] this->nrSeats;
				this->nrSeats = nullptr;
			}
			this->nrRows = 0;
			return *this;
		}

		if (t.nrSeats == nullptr) {
			if (this->nrSeats != nullptr) {
				delete[] this->nrSeats;
				this->nrSeats = nullptr;
			}
			this->nrRows = t.nrRows;
			return *this;
		}

		if (this->nrRows != t.nrRows) {
			if (this->nrSeats != nullptr) {
				delete[] this->nrSeats;
				this->nrSeats = nullptr;
			}
		}

		if (this->nrSeats == nullptr)
			this->nrSeats = new int[t.nrRows];

		for (int i = 0; i < t.nrRows; i++)
			this->nrSeats[i] = t.nrSeats[i];

		this->nrRows = t.nrRows;

		return *this;
	}
};

int Theatre::MIN_NR_ROWS = 0;
int Theatre::MAX_NR_ROWS = 300;
int Theatre::MIN_SEATS_PER_ROW = 0;
int Theatre::MAX_SEATS_PER_ROW = 50;
int Theatre::MIN_SEATS_VIP = 0;
int Theatre::MAX_SEATS_VIP = 100;