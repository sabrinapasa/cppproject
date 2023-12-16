#pragma once
#include"FILES.h"
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

class CinemaHall {
	int nrRows;
	char name[11];
	int* nrSeats;
	bool isAvailable;
	int idP;

public:
	
	static int  MIN_NR_ROWS;
	static int  MAX_NR_ROWS;
	static int MIN_SEATS_PER_ROW;
	static int MAX_SEATS_PER_ROW;
	static int id;

	CinemaHall() {
		this->isAvailable = false;
		this->name[0] = '\0';
		this->nrRows = 0;
		this->nrSeats = nullptr;
		this->id++;
		this->idP = this->id;
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
		this->id++;
		this->idP = this->id;
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
		this->id++;
		this->idP = this->id;
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
		this->id++;
		this->idP = this->id;
	}

	void printCinemaHall() const{
		cout << "Id : " << this->id;
		cout << endl << "Name: ";
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

	int sum() {
		if (this->nrRows == 0)
			return 0;
		if (this->nrSeats == nullptr)
			return 0;
		int sum = 0;
		for (int i = 0; i < this->nrRows; i++) {
			sum += this->nrSeats[i];
		}
		return sum;
	}

	int min() {
		if (this->nrRows == 0)
			return 0;
		if (this->nrSeats == nullptr)
			return 0;
		int min = MAX_SEATS_PER_ROW;
		for (int i = 0; i < this->nrRows; i++) {
			if (this->nrSeats[i] < min)
				min = this->nrSeats[i];
		}
		return min;
	}

	int max() {
		if (this->nrRows == 0)
			return 0;
		if (this->nrSeats == nullptr)
			return 0;
		int max = MIN_SEATS_PER_ROW;
		for (int i = 0; i < this->nrRows; i++) {
			if (this->nrSeats[i] > max)
				max = this->nrSeats[i];
		}
		return max;
	}

	void readCinemaHall() {
		this->id--;
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
		this->id++;
		this->idP = this->id;
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
	CinemaHall& operator++() {
		if (this->nrRows + 1 > MAX_NR_ROWS) {
			throw new exception("Imposible operation");
		}
		int* copy = new int[this->nrRows + 1];
		for (int i = 0; i < this->nrRows; i++) {
			copy[i] = this->nrSeats[i];
		}
		copy[this->nrRows] = 10;
		if (this->nrSeats != nullptr) {
			delete[] this->nrSeats;
			this->nrSeats = nullptr;
		}
		this->nrSeats = copy;
		this->nrRows += 1;
		return *this;
	}

	//post
	CinemaHall operator++(int) {
		CinemaHall copy = *this;
		if (copy.nrRows + 1 > MAX_NR_ROWS) {
			throw new exception("Imposible operation");
		}
		int* copyRows = new int[this->nrRows + 1];
		for (int i = 0; i < this->nrRows; i++) {
			copyRows[i] = this->nrSeats[i];
		}
		copyRows[this->nrRows] = 10;
		if (this->nrSeats != nullptr) {
			delete[] this->nrSeats;
			this->nrSeats = nullptr;
		}
		this->nrSeats = copyRows;
		this->nrRows += 1;
		return copy;
	}

	CinemaHall operator+(int value) {
		CinemaHall copy = *this;
		if (copy.nrRows + value > MAX_NR_ROWS) {
			throw new exception("Imposible operation");
		}
		int* copyRows = new int[this->nrRows + value];
		for (int i = 0; i < this->nrRows; i++) {
			copyRows[i] = this->nrSeats[i];
		}
		for (int i = this->nrRows; i < this->nrRows + value; i++) {
			copyRows[i] = 10;
		}
		if (copy.nrSeats != nullptr) {
			delete[] copy.nrSeats;
			copy.nrSeats = nullptr;
		}
		copy.nrSeats = copyRows;
		copy.nrRows += value;
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
			int* copyRows = new int[this->nrRows - value];
			for (int i = 0; i < this->nrRows - value; i++) {
				copyRows[i] = this->nrSeats[i];
			}
			if (copy.nrSeats != nullptr) {
				delete[] copy.nrSeats;
				copy.nrSeats = nullptr;
			}
			copy.nrSeats = copyRows;
			copy.nrRows -= value;
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

	friend void writeCinemaToFile(const CinemaHall& c);
	friend CinemaHall readCinemaFromFile(string fname, int id);
};

CinemaHall operator+(int value, const CinemaHall& c) {
	CinemaHall copy = c;
	if (copy.nrRows + value > CinemaHall::MAX_NR_ROWS) {
		throw new exception("Imposible operation");
	}
	int* copyRows = new int[c.nrRows + value];
	for (int i = 0; i < c.nrRows; i++) {
		copyRows[i] = c.nrSeats[i];
	}
	for (int i = c.nrRows; i < c.nrRows + value; i++) {
		copyRows[i] = 10;
	}
	
	if (copy.nrSeats != nullptr) {
		delete[] copy.nrSeats;
		copy.nrSeats = nullptr;
	}
	copy.nrSeats = copyRows;
	copy.nrRows += value;
	return copy;
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
int CinemaHall::id = setId("Places.bin");

void writeCinemaToFile(const CinemaHall& c) {
	fstream f("Places.bin", ios::binary | ios::in | ios::ate);
	if (!f) {
		throw exception("No file");
	}
	typeP Place = Cinema_Hall_;
	int TotalSize = (c.nrRows + 2) * sizeof(int) + sizeof(char) * 11 + sizeof(bool) + sizeof(typeP);
	f.write((char*)&TotalSize, sizeof(int));
	f.write((char*)&Place, sizeof(typeP));
	f.write((char*)&c.idP, sizeof(int));
	f.write(c.name, sizeof(char) * 11);
	f.write((char*)&c.nrRows, sizeof(int));
	for (int i = 0; i < c.nrRows; i++) {
		f.write((char*)&c.nrSeats[i], sizeof(int));
	}
	f.write((char*)&c.isAvailable, sizeof(bool));

	f.seekg(ios::beg);
	int value;
	f.read((char*)&value, sizeof(int));
	value++;
	f.seekp(0,ios::beg);
	f.write((char*)&value, sizeof(int));

	f.close();
}

void createCinema() {
	CinemaHall c;
	cin >> c;
	writeCinemaToFile(c);
}

CinemaHall readCinemaFromFile(string fname,int id) {
	fstream f(fname.c_str(), ios::binary | ios::in | ios::ate);
	if (!f) {
		throw exception("No file");
	}
	CinemaHall c;
	int value;
	f.read((char*)&value, sizeof(int));
	for (int i = 1; i < value; i++) {
		int totalSize;
		f.read((char*)&totalSize, sizeof(int));
		typeP place;
		f.read((char*)&place, sizeof(typeP));
		if (place != Cinema_Hall_) {
			f.seekg(totalSize - sizeof(int) - sizeof(typeP), ios::cur);
			continue;
		}
		int idP;
		f.read((char*)&idP, sizeof(int));
		if (idP != id) {
			f.seekg(totalSize - sizeof(int) - sizeof(typeP) - sizeof(int), ios::cur);
			continue;
		}
		f.read(c.name, sizeof(char) * 11);
		f.read((char*)&c.nrRows, sizeof(int));
		c.nrSeats = new int[c.nrRows];
		for (int i = 0; i < c.nrRows; i++) {
			f.read((char*)&c.nrSeats[i], sizeof(int));
		}
		f.read((char*)&c.isAvailable, sizeof(bool));
		break;
	}
	f.close();
	return c;
}