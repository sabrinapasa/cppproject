#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include"FILES.h"
#include"event.h"

using namespace std;

class Concert {
	int nrPersons;
	char name[21];
	char* address;
	bool freeEntrance;
	int idP;

public:

	static int MAX_NR_PERSONS;
	static int MIN_NR_PERSONS;
	static int id;

	Concert() {
		this->name[0] = '\0';
		this->nrPersons = 0;
		this->address = nullptr;
		this->freeEntrance = false;
		this->id++;
		this->idP = this->id;
	}

	Concert(const int nrPersons, const char* address) {
		if (nrPersons < MIN_NR_PERSONS || nrPersons > MAX_NR_PERSONS)
			throw new exception("Value out of range!");
		this->nrPersons = nrPersons;
		this->address = new char[strlen(address)+1];
		strcpy_s(this->address, strlen(address) + 1, address);
		this->name[0] = '\0';
		this->freeEntrance = false;
		this->id++;
		this->idP = this->id;
	}

	Concert(const int nrPersons, const char* address, const char* name, bool freeEntrance) {
		if (nrPersons < MIN_NR_PERSONS || nrPersons > MAX_NR_PERSONS)
			throw new exception("Value out of range!");
		this->nrPersons = nrPersons;
		this->address = new char[strlen(address) + 1];
		strcpy_s(this->address, strlen(address) + 1, address);
		if (strlen(name) > 20) {
			throw new exception("Name too long!");
		}
		strcpy_s(this->name, 21, name);
		this->freeEntrance = freeEntrance;
		this->id++;
		this->idP = this->id;
	}

	void setFreeEntrance(bool freeEntrance) {
		this->freeEntrance = freeEntrance;
	}

	bool getFreeEntrance() {
		return this->freeEntrance;
	}

	void setNrPersons(int nrPersons) {
		if (nrPersons < MIN_NR_PERSONS || nrPersons > MAX_NR_PERSONS)
			throw new exception("Value out of range!");
		this->nrPersons = nrPersons;
	}

	int getNrPersons() const {
		return this->nrPersons;
	}

	void setAddress(const char* address) {
		if (this->address != nullptr)
			delete[] this->address;
		this->address = new char[strlen(address) + 1];
		strcpy_s(this->address, strlen(address) + 1, address);
	}

	char* getAddress() const {
		char* copy = new char[strlen(this->address) + 1];
		strcpy_s(copy, strlen(this->address) + 1, this->address);
		return copy;
	}

	void setName(const char* name) {
		if (strlen(name) > 20) {
			throw new exception("Name too long!");
		}
		strcpy_s(this->name, 21, name);
	}

	char* getName() {
		char* copy = new char[strlen(this->name)+1];
		strcpy_s(copy, 21, this->name);
		return copy;
	}

	~Concert() {
		if (this->address != nullptr)
			delete[] this->address;
	}

	Concert(const Concert& c) {
		this->freeEntrance = c.freeEntrance;
		this->nrPersons = c.nrPersons;
		strcpy_s(this->name, 21, c.name);
		if (c.address == nullptr)
			this->address = nullptr;
		else {
			this->address = new char[strlen(c.address)+1];
			strcpy_s(this->address, strlen(c.address) + 1, c.address);
		}
		this->id++;
		this->idP = this->id;
	}

	void printConcert() const {
		cout << "Name: ";
		if (this->name[0] == 0)
			cout << "No name";
		else
			cout << this->name;
		cout << endl;
		cout << "Number of persons: ";
		if (this->nrPersons == 0)
			cout << "No persons";
		else
			cout << this->nrPersons;
		cout << endl;
		if (this->address == nullptr)
			cout << "The address is unknown";
		else {
			cout << "The address is: " << this->address;
		}
	}

	void readConcert() {
		this->id--;
		cout << "Concert name: ";
		this->freeEntrance = false;
		char name[21];
		int nrPersons;
		cin.getline(name, 21);
		strcpy_s(this->name, 21, name);
		cout << "Number of persons: ";
		cin >> nrPersons;
		cin.get();
		if (nrPersons <= MIN_NR_PERSONS || nrPersons > MAX_NR_PERSONS)
			throw new exception("Value out of range!");
		this->nrPersons = nrPersons;
		if (this->address != nullptr) {
			delete[] this->address;
			this->address = nullptr;
		}
		cout << "Address : ";
		char address[100];
		cin.getline(address, 100);
		this->address = new char[strlen(address) + 1];
		strcpy_s(this->address, strlen(address) + 1, address);
		this->id++;
		this->idP = this->id;
	}

	bool assessFreeEntrance() {
		if (this->nrPersons > MAX_NR_PERSONS / 2)
			return false;
		else
			return true;
	}

	Concert& operator=(const Concert& c) {
		if (this == &c)
			return *this;

		this->freeEntrance = c.freeEntrance;
		this->nrPersons = c.nrPersons;
		strcpy_s(this->name, 21, c.name);

		if (c.address == nullptr) {
			if (this->address != nullptr) {
				delete[] this->address;
				this->address = nullptr;
			}
			return *this;
		}

		if (this->address != nullptr) {
			delete[] this->address;
			this->address = nullptr;
		}
		this->address = new char[strlen(c.address)+1];
		strcpy_s(this->address, strlen(c.address) + 1, c.address);
		
		return *this;
	}

	//pre
	Concert operator++() {
		if (this->nrPersons + 1 > MAX_NR_PERSONS) {
			throw new exception("Imposible operation");
		}
		else {
			this->nrPersons += 1;
			return *this;
		}
	}

	//post
	Concert operator++(int) {
		Concert copy = *this;
		if (this->nrPersons + 1 > MAX_NR_PERSONS) {
			throw new exception("Imposible operation");
		}
		else {
			this->nrPersons += 1;
		}
		return copy;
	}

	Concert operator+(int value) {
		Concert copy = *this;
		if (copy.nrPersons + value > MAX_NR_PERSONS) {
			throw new exception("Imposible operation");
		}
		copy.nrPersons += value;
		return copy;
	}

	Concert operator-(int value) {
		Concert copy = *this;
		if (value >= copy.nrPersons) {
			throw new exception("The value is too big!");
		}
		else {
			copy.nrPersons -= value;
			return copy;
		}
	}

	char& operator[](int index) {
		if (index >= 0 && index < strlen(this->address)) {
			return this->address[index];
		}
		else {
			throw exception("Ingex out of range");
		}
	}

	bool operator!() {
		bool copy = !this->freeEntrance;
		return copy;
	}

	explicit operator int() {
		return this->nrPersons;
	}

	friend Concert operator+(int value, const Concert& c);
	friend Concert operator-(int value, const Concert& c);

	bool operator==(const Concert& c) {
		if (this->freeEntrance == c.freeEntrance && this->nrPersons == c.nrPersons && strcmp(this->address, c.address) == 0 && strcmp(this->name, c.name) == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator>=(const Concert& c) {
		if (this->nrPersons >= c.nrPersons) {
			return true;
		}
		else {
			return false;
		}
	}

	friend void writeConcertToFile(const Concert& c);
	friend Concert readConcertFromFile(string fname, int id);
};

Concert operator+(int value, const Concert& c) {
	Concert copy = c;
	if (copy.nrPersons + value > Concert::MAX_NR_PERSONS) {
		throw new exception("Imposible operation");
	}
	copy.nrPersons += value;
	return copy;
}

Concert operator-(int value, const Concert& c) {
	Concert copy = c;
	if (value <= copy.nrPersons) {
		throw new exception("The value is too small!");
	}
	if (copy.nrPersons == value) {
		copy.nrPersons = 0;
		return copy;
	}
	else {
		value -= copy.nrPersons;
		copy.nrPersons = value;
		return copy;
	}
}

ostream& operator<<(ostream& out, const Concert& c) {
	c.printConcert();
	return out;
}

istream& operator>>(istream& in, Concert& c) {
	c.readConcert();
	return in;
}


int Concert::MAX_NR_PERSONS = 100000;
int Concert::MIN_NR_PERSONS = 0;
int Concert::id = setId("Places.bin");

void writeConcertToFile(const Concert& c) {
	//fstream f("Places.bin", ios::binary | ios::in | ios::ate);
	fstream f("Places.bin", ios::binary | ios::app);
	if (!f) {
		throw exception("No file");
	}
	typeP Place = Concert_;
	int TotalSize = 4 * sizeof(int) + sizeof(char) * 21 + sizeof(bool) + sizeof(typeP) + strlen(c.address) + 1;
	f.write((char*)&TotalSize, sizeof(int));
	f.write((char*)&Place, sizeof(typeP));
	f.write((char*)&c.idP, sizeof(int));
	f.write(c.name, sizeof(char) * 21);
	f.write((char*)&c.nrPersons, sizeof(int));
	int nrChar = strlen(c.address) + 1;
	f.write((char*)&nrChar, sizeof(int));
	f.write(c.address, nrChar);
	f.write((char*)&c.freeEntrance, sizeof(bool));

	f.seekg(0,ios::beg);
	int value;
	f.read((char*)&value, sizeof(int));
	value++;
	f.seekp(0, ios::beg);
	f.write((char*)&value, sizeof(int));

	f.close();
}

void createConcert() {
	Concert c;
	cin >> c;
	writeConcertToFile(c);
}

Concert readConcertFromFile(string fname, int id) {
	//fstream f(fname.c_str(), ios::binary | ios::in | ios::ate);
	fstream f(fname.c_str(), ios::binary | ios::app);
	if (!f) {
		throw exception("No file");
	}
	Concert c;
	c.id--;
	int value;
	f.read((char*)&value, sizeof(int));
	for (int i = 1; i < value; i++) {
		int totalSize;
		int currentPos = f.tellg();
		f.read((char*)&totalSize, sizeof(int));
		typeP place;
		f.read((char*)&place, sizeof(typeP));
		if (place != Concert_) {
			f.seekg(totalSize + currentPos, ios::beg);
			continue;
		}
		int idP;
		f.read((char*)&idP, sizeof(int));
		if (idP != id) {
			f.seekg(totalSize +currentPos, ios::beg);
			continue;
		}
		f.read(c.name, sizeof(char) * 21);
		f.read((char*)&c.nrPersons, sizeof(int));
		int value;
		f.read((char*)&value, sizeof(int));
		c.address = new char[value];
		f.read(c.address, value);
		f.read((char*)&c.freeEntrance, sizeof(bool));
		break;
	}
	f.close();
	return c;
}