#pragma once
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

class CinemaHall {
	int nrRows;
	char name[11];
	int* nrSeats;
	bool isAvailable;

public:
	
	static int  MIN_NR_ROWS;
	static int  MAX_NR_ROWS;
	static int MIN_SEATS_PER_ROW;
	static int MAX_SEATS_PER_ROW;

	CinemaHall() {
		this->isAvailable = false;
		this->name[0] = '\0';
		this->nrRows = 0;
		this->nrSeats = nullptr;
	}

	CinemaHall(const int nrRows,const int* nrSeats) {
		if (nrRows < MIN_NR_ROWS || nrRows > MAX_NR_ROWS)
			throw new exception("Value out of range!");
		this->nrRows = nrRows;
		this->nrSeats = new int[nrRows];
		for (int i = 0; i < nrRows; i++)
			this->nrSeats[i] = nrSeats[i];
		this->isAvailable = false;
		this->name[0] = '\0';
	}

	CinemaHall(const int nrRows, const int* nrSeats, const char* name) {
		if (nrRows < MIN_NR_ROWS || nrRows > MAX_NR_ROWS)
			throw new exception("Value out of range!");
		this->nrRows = nrRows;
		this->nrSeats = new int[nrRows];
		for (int i = 0; i < nrRows; i++)
			this->nrSeats[i] = nrSeats[i];
		this->isAvailable = false;
		if (strlen(name) > 10) {
			throw new exception("Name too long!");
		}
		strcpy_s(this->name, 11, name);
	}

	void setAvailability(bool isAvailable) {
		this->isAvailable = isAvailable;
	}

	bool IsAvailable() const{
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

	void setName(const char* name) {
		if (strlen(name) > 10) {
			throw new exception("Name too long!");
		}
		strcpy_s(this->name, 11, name);
	}

	char* getName() const {
		char* copy = new char[strlen(this->name)+1];
		strcpy_s(copy, 11, this->name);
		return copy;
	}

	~CinemaHall() {
		if (this->nrSeats != nullptr)
			delete[] this->nrSeats;
	}

	CinemaHall(const CinemaHall& c) {
		this->isAvailable = c.isAvailable;
		strcpy_s(this->name, 11, c.name);
		this->nrRows = c.nrRows;
		if (c.nrSeats == nullptr)
			this->nrSeats = nullptr;
		else {
			this->nrSeats = new int[c.nrRows];
			for (int i = 0; i < c.nrRows; i++)
				this->nrSeats[i] = c.nrSeats[i];
		}
	}

	void printCinemaHall() const{
		cout << "Name: ";
		if (this->name[0] == 0)
			cout << "No name";
		else
			cout << this->name;
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

	void readCinemaHall() {
		cout << "Hall name: ";
		this->isAvailable = false;
		char name[11];
		int nrRows;
		cin.getline(name, 11);
		strcpy_s(this->name, 11, name);
		cout << "Number of rows: ";
		cin >> nrRows;
		if (nrRows <= MIN_NR_ROWS || nrRows > MAX_NR_ROWS)
			throw new exception("Value out of range!");
		if (nrRows != this->nrRows && this->nrSeats != nullptr) {
			delete[] this->nrSeats;
			this->nrSeats = nullptr;
		}
		this->nrRows = nrRows;
		if (this->nrSeats == nullptr)
			this->nrSeats = new int[this->nrRows];
		cout << "Give the seats for each row" << endl;
		for (int i = 0; i < this->nrRows; i++)
		{
			cout << "Row number: " << i + 1;
			cin >> this->nrSeats[i];
		}
		cin.get();
	}

	CinemaHall& operator=(const CinemaHall& c) {
		if (this == &c)
			return *this;

		this->isAvailable = c.isAvailable;
		strcpy_s(this->name, 11, c.name);

		if (c.nrRows == 0) {
			if (this->nrSeats != nullptr) {
				delete[] this->nrSeats;
				this->nrSeats = nullptr;
			}
			this->nrRows = 0;
			return *this;
		}

		if (c.nrSeats == nullptr) {
			if (this->nrSeats != nullptr) {
				delete[] this->nrSeats;
				this->nrSeats = nullptr;
			}
			this->nrRows = c.nrRows;
			return *this;
		}

		if (this->nrRows != c.nrRows) {
			if (this->nrSeats != nullptr) {
				delete[] this->nrSeats;
				this->nrSeats = nullptr;
			}
		}

		if (this->nrSeats == nullptr)
			this->nrSeats = new int[c.nrRows];

		for (int i = 0; i < c.nrRows; i++)
			this->nrSeats[i] = c.nrSeats[i];

		this->nrRows = c.nrRows;

		return *this;
	}

	//pre
	CinemaHall operator++() {
		if (this->nrRows + 1 > MAX_NR_ROWS) {
			throw new exception("Imposible operation");
		}
		this->nrRows += 1;
		if (this->nrSeats != nullptr) {
			delete[] this->nrSeats;
			this->nrSeats = nullptr;
		}
		this->nrSeats = new int[this->nrRows];
		return *this;
	}

	//post
	CinemaHall operator++(int) {
		CinemaHall copy = *this;
		if (copy.nrRows + 1 > MAX_NR_ROWS) {
			throw new exception("Imposible operation");
		}
		this->nrRows += 1;
		if (this->nrSeats != nullptr) {
			delete[] this->nrSeats;
			this->nrSeats = nullptr;
		}
		this->nrSeats = new int[this->nrRows];
		return copy;
	}

	CinemaHall operator+(int value) {
		CinemaHall copy = *this;
		if (copy.nrRows + value > MAX_NR_ROWS) {
			throw new exception("Imposible operation");
		}
		copy.nrRows += value;
		if (copy.nrSeats != nullptr) {
			delete[] copy.nrSeats;
			copy.nrSeats = nullptr;
		}
		copy.nrSeats = new int[copy.nrRows];
		return copy;
	}

	CinemaHall operator-(int value) {
		CinemaHall copy = *this;
		if (value >= copy.nrRows) {
			throw new exception("The value is too big!");
		}
		if (value == copy.nrRows) {
			copy.nrRows = 0;
			if (copy.nrSeats != nullptr) {
				delete[] copy.nrSeats;
				copy.nrSeats = nullptr;
				return copy;
			}
		}
		else {
		copy.nrRows -= value;
		if (copy.nrSeats != nullptr) {
			delete[] copy.nrSeats;
			copy.nrSeats = nullptr;
		}
		copy.nrSeats = new int[copy.nrRows];
		return copy;
		}
	}

	int& operator[](int index) {
		if (index >= 0 && index < this->nrRows) {
			return this->nrSeats[index];
		}
		else {
			throw exception ("Ingex out of range");
		}
	}

	bool operator!() {
		bool copy = !this->isAvailable;
		return copy;
	}

	explicit operator int() {
		return this->nrRows;
	}

	friend CinemaHall operator+(int value, const CinemaHall& c);
	friend CinemaHall operator-(int value, const CinemaHall& c);

	bool operator==(const CinemaHall& c) {
		if (this->isAvailable == c.isAvailable && this->nrRows == c.nrRows && strcmp(this->name, c.name) == 0) {
			for (int i = 0; i < this->nrRows; i++)
				for (int j = 0; j < this->nrRows; j++)
					if (this->nrSeats[i] == c.nrSeats[j])
						return true;
		}
		else {
			return false;
		}
	}

	bool operator>=(const CinemaHall& c) {
		if (this->nrRows >= c.nrRows){
			return true;
		}
		else {
			return false;
		}
	}
};

CinemaHall operator+(int value, const CinemaHall& c) {
	CinemaHall copy = c;
	if (copy.nrRows + value > CinemaHall::MAX_NR_ROWS) {
		throw new exception("Imposible operation");
	}
	copy.nrRows += value;
	if (copy.nrSeats != nullptr) {
		delete[] copy.nrSeats;
		copy.nrSeats = nullptr;
	}
	copy.nrSeats = new int[copy.nrRows];
	return copy;
}

CinemaHall operator-(int value, const CinemaHall& c) {
	CinemaHall copy = c;
	if (value <= copy.nrRows) {
		throw new exception("The value is too small!");
	}
	if (copy.nrRows == value) {
		copy.nrRows = 0;
		if (copy.nrSeats != nullptr) {
			delete[] copy.nrSeats;
			copy.nrSeats = nullptr;
			return copy;
		}
	}
	else {
		value -= copy.nrRows;
		copy.nrRows = value;
		if (copy.nrSeats != nullptr) {
			delete[] copy.nrSeats;
			copy.nrSeats = nullptr;
		}
		copy.nrSeats = new int[copy.nrRows];
		return copy;
	}
}

ostream& operator<<(ostream& out, const CinemaHall& c) {
	c.printCinemaHall();
	return out;
}

istream& operator>>(istream& in, CinemaHall& c) {
	c.readCinemaHall();
	return in;
}

int CinemaHall::MIN_NR_ROWS = 0;
int CinemaHall::MAX_NR_ROWS = 30;
int CinemaHall::MIN_SEATS_PER_ROW = 0;
int CinemaHall::MAX_SEATS_PER_ROW = 30;