#pragma once
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

class Concert {
	int nrPersons;
	char name[21];
	char* address;

	static int MAX_NR_PERSONS;
	static int MIN_NR_PERSONS;

public:

	Concert() {
		this->name[0] = '\0';
		this->nrPersons = 0;
		this->address = nullptr;
	}

	Concert(const int nrPersons, const char* address) {
		if (nrPersons < MIN_NR_PERSONS || nrPersons > MAX_NR_PERSONS)
			throw new exception("Value out of range!");
		this->nrPersons = nrPersons;
		this->address = new char[strlen(address)+1];
		strcpy_s(this->address, strlen(address) + 1, address);
		this->name[0] = '\0';
	}

	Concert(const int nrPersons, const char* address, const char* name) {
		if (nrPersons < MIN_NR_PERSONS || nrPersons > MAX_NR_PERSONS)
			throw new exception("Value out of range!");
		this->nrPersons = nrPersons;
		this->address = new char[strlen(address) + 1];
		strcpy_s(this->address, strlen(address) + 1, address);
		if (strlen(name) > 20) {
			throw new exception("Name too long!");
		}
		strcpy_s(this->name, 21, name);
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
	}

	~Concert() {
		if (this->address != nullptr)
			delete[] this->address;
	}

	Concert(const Concert& c) {
		this->nrPersons = c.nrPersons;
		strcpy_s(this->name, 21, c.name);
		if (c.address == nullptr)
			this->address = nullptr;
		else {
			this->address = new char[strlen(c.address)+1];
			strcpy_s(this->address, strlen(c.address) + 1, c.address);
		}
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
			cout << "The address is: ";
			for (int i = 0; i < strlen(this->address); i++)
				cout << this->address[i];
		}
	}

	Concert& operator=(const Concert& c) {
		if (this == &c)
			return *this;

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
};

int Concert::MAX_NR_PERSONS = 1000;
int Concert::MIN_NR_PERSONS = 0;