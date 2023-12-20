#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include"FILES.h"
#include"event.h"

using namespace std;

class Theatre {
	int nrRows;
	char address[51];
	int* nrSeats;
	int nrSeatsVIP;
	bool isAvailable;
	int idP;

public:
	
	static int  MIN_NR_ROWS;
	static int  MAX_NR_ROWS;
	static int MIN_SEATS_PER_ROW;
	static int MAX_SEATS_PER_ROW;
	static int MIN_SEATS_VIP;
	static int MAX_SEATS_VIP;
	static int id;

	Theatre() {
		this->isAvailable = false;
		this->address[0] = '\0';
		this->nrRows = 0;
		this->nrSeatsVIP = 0;
		this->nrSeats = nullptr;
		this->id++;
		this->idP = this->id;
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
		this->id++;
		this->idP = this->id;
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
		this->id++;
		this->idP = this->id;
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
		this->id++;
		this->idP = this->id;
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

	void readTheatre() {
		this->id--;
		cout << "Theatre address: ";
		this->isAvailable = true;
		char address[11];
		int nrRows;
		int nrSeatsVIP;
		cin.getline(address, 11);
		strcpy_s(this->address, 11, address);
		cout << "Number of seats VIP: ";
		cin >> nrSeatsVIP;
		this->nrSeatsVIP = nrSeatsVIP;
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

	int sum() {
		if (this->nrRows == 0)
			return this->nrSeatsVIP;
		if(this->nrSeats==nullptr)
			return this->nrSeatsVIP;
		int sum = 0;
		for (int i = 0; i < this->nrRows; i++) {
			sum += this->nrSeats[i];
		}
		sum += this->nrSeatsVIP;
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

	//pre
	Theatre& operator++() {
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
	Theatre operator++(int) {
		Theatre copy = *this;
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

	Theatre operator+(int value) {
		Theatre copy = *this;
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

	Theatre operator-(int value) {
		Theatre copy = *this;
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
			throw exception("Ingex out of range");
		}
	}

	bool operator!() {
		bool copy = !this->isAvailable;
		return copy;
	}

	explicit operator int() {
		return this->nrRows;
	}

	friend Theatre operator+(int value, const Theatre& t);

	bool operator==(const Theatre& t) {
		if (this->isAvailable == t.isAvailable && this->nrRows == t.nrRows && strcmp(this->address, t.address) == 0 && this->nrSeatsVIP == t.nrSeatsVIP) {
			for (int i = 0; i < this->nrRows; i++)
				for (int j = 0; j < this->nrRows; j++)
					if (this->nrSeats[i] == t.nrSeats[j])
						return true;
		}
		else {
			return false;
		}
	}

	bool operator>=(const Theatre& t) {
		if (this->nrRows >= t.nrRows) {
			return true;
		}
		else {
			return false;
		}
	}

	friend Theatre readTheatreFromFile(string fname, int id);
	friend void writeTheatreToFile(const Theatre& t);
};

Theatre operator+(int value, const Theatre& c) {
	Theatre copy = c;
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

ostream& operator<<(ostream& out, const Theatre& t) {
	t.printTheatre();
	return out;
}

istream& operator>>(istream& in, Theatre& t) {
	t.readTheatre();
	return in;
}

int Theatre::MIN_NR_ROWS = 0;
int Theatre::MAX_NR_ROWS = 300;
int Theatre::MIN_SEATS_PER_ROW = 0;
int Theatre::MAX_SEATS_PER_ROW = 50;
int Theatre::MIN_SEATS_VIP = 0;
int Theatre::MAX_SEATS_VIP = 100;
int Theatre::id = setId("Places.bin");

void writeTheatreToFile(const Theatre& t) {
	//fstream f("Places.bin", ios::binary | ios::in | ios::ate);
	fstream f("Places.bin", ios::binary | ios::app);
	if (!f) {
		throw exception("No file");
	}
	typeP Place = Theatre_;
	int TotalSize = (t.nrRows + 3) * sizeof(int) + sizeof(char) * 51 + sizeof(bool) + sizeof(typeP);
	f.write((char*)&TotalSize, sizeof(int));
	f.write((char*)&Place, sizeof(typeP));
	f.write((char*)&t.idP, sizeof(int));
	f.write(t.address, sizeof(char) * 51);
	f.write((char*)&t.nrRows, sizeof(int));
	for (int i = 0; i < t.nrRows; i++) {
		f.write((char*)&t.nrSeats[i], sizeof(int));
	}
	f.write((char*)&t.isAvailable, sizeof(bool));
	f.write((char*)&t.nrSeatsVIP, sizeof(int));

	f.seekg(ios::beg);
	int value;
	f.read((char*)&value, sizeof(int));
	value++;
	f.seekp(0, ios::beg);
	f.write((char*)&value, sizeof(int));

	f.close();
}

void createTheatre() {
	Theatre t;
	cin >> t;
	writeTheatreToFile(t);
}

Theatre readTheatreFromFile(string fname, int id) {
	//fstream f(fname.c_str(), ios::binary | ios::in | ios::ate);
	fstream f(fname.c_str(), ios::binary | ios::app);
	if (!f) {
		throw exception("No file");
	}
	Theatre t;
	int value;
	f.read((char*)&value, sizeof(int));
	for (int i = 1; i < value; i++) {
		int totalSize;
		f.read((char*)&totalSize, sizeof(int));
		typeP place;
		f.read((char*)&place, sizeof(typeP));
		if (place != Theatre_) {
			f.seekg(totalSize - sizeof(int) - sizeof(typeP), ios::cur);
			continue;
		}
		int idP;
		f.read((char*)&idP, sizeof(int));
		if (idP != id) {
			f.seekg(totalSize - sizeof(int) - sizeof(typeP) - sizeof(int), ios::cur);
			continue;
		}
		f.read(t.address, sizeof(char) * 51);
		f.read((char*)&t.nrRows, sizeof(int));
		t.nrSeats = new int[t.nrRows];
		for (int i = 0; i < t.nrRows; i++) {
			f.read((char*)&t.nrSeats[i], sizeof(int));
		}
		f.read((char*)&t.isAvailable, sizeof(bool));
		f.read((char*)&t.nrSeatsVIP, sizeof(int));
		break;
	}
	f.close();
	return t;
}