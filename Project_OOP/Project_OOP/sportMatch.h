#pragma once
#include"FILES.h"
#include<iostream>
#include<string>
#include<cstring>
#include"event.h"

using namespace std;

struct Sector{
	int name;
	int nrRows;
	int nrSeatsPerRow;
	int ring;
	int isAvailable;
};

class Stadium {
	const int nrPermanentlyFree = 50;
	char name[31];
	char* address;
	bool isAvailable;
	Sector sector[200];
	int nrSectors;
	int idP;

public:

	static int MAX_NR_SEATS;
	static int MIN_NR_SEATS;
	static int MAX_NR_SEATS_PER_ROW;
	static int MIN_NR_SEATS_PER_ROW;
	static int MAX_NR_SECTORS;
	static int MIN_NR_SECTORS;
	static int MAX_NR_ROWS;
	static int MIN_NR_ROWS;
	static int MAX_NR_RINGS;
	static int MIN_NR_RINGS;
	static int id;

	Stadium() {
		this->name[0] = '\0';
		this->address = nullptr;
		this->isAvailable = false;
		this->nrSectors = 0;
		this->id++;
		this->idP = this->id;
	}

	Stadium(const int nrSectors, const char* address) {
		if (nrSectors < MIN_NR_SECTORS || nrSectors > MAX_NR_SECTORS)
			throw new exception("Value out of range!");
		this->nrSectors = nrSectors;
		for (int i = 0; i < this->nrSectors; i++) {
			(*this)[i].name = 0;
		}
		this->address = new char[strlen(address) + 1];
		strcpy_s(this->address, strlen(address) + 1, address);
		this->name[0] = '\0';
		this->isAvailable = false;
		this->id++;
		this->idP = this->id;
	}

	Stadium(const int nrSectors, const char* address, const char* name, bool isAvailable,const Sector* sector) {
		if (nrSectors < MIN_NR_SECTORS || nrSectors > MAX_NR_SECTORS)
			throw new exception("Value out of range!");
		this->nrSectors = nrSectors;
		this->address = new char[strlen(address) + 1];
		strcpy_s(this->address, strlen(address) + 1, address);
		if (strlen(name )<= 30) {
			strcpy_s(this->name, strlen(name) + 1, name);
		}
		else {
			throw new exception("Invalid input");
		}
		this->isAvailable = isAvailable;
		for (int i = 0; i < this->nrSectors; i++) {
			this->sector[i] = sector[i];
		}
		this->id++;
		this->idP = this->id;
	}

	~Stadium() {
		if (this->address != nullptr) {
			delete[] this->address;
			this->address = nullptr;
		}
	}

	void setAvailability(bool isAvailable) {
		this->isAvailable = isAvailable;
	}

	bool IsAvailable() const {
		return this->isAvailable;
	}

	void setNrSectors(int nrSectors) {
		if (nrSectors < MIN_NR_SECTORS || nrSectors > MAX_NR_SECTORS)
			throw new exception("Value out of range!");
		this->nrSectors = nrSectors;
	}

	int getNrPersons() const {
		return this->nrSectors;
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
		if (strlen(name) > 30) {
			throw new exception("Name too long!");
		}
		strcpy_s(this->name, 31, name);
	}

	char* getName() {
		char* copy = new char[strlen(this->name) + 1];
		strcpy_s(copy, 31, this->name);
		return copy;
	}

	void setSectors(Sector* sector, int nrSectors) {
		if (nrSectors < MIN_NR_SECTORS || nrSectors > MAX_NR_SECTORS)
			throw new exception("Value out of range!");
		this->nrSectors = nrSectors;
		for (int i = 0; i < this->nrSectors; i++) {
			this->sector[i] = sector[i];
		}
	}

	Sector getSector(int SectorNr) {
		if (SectorNr < MIN_NR_SECTORS || SectorNr > MAX_NR_SECTORS) {
			throw new exception("Value out of range!");
		}
		if (SectorNr >= this->nrSectors) {
			throw new exception("Value out of range!");
		}
		else {
			return this->sector[SectorNr];
		}
	}

	void setSector(int SectorNr, int ring, int name, int nrRows, int nrSeatsPerRow, bool isAvailable){
		this->setSectorNrRows(SectorNr, nrRows);
		this->setSectorIsAvailable(SectorNr, isAvailable);
		this->setSectorNrSeatsPerRow(SectorNr, nrSeatsPerRow);
		this->setSectorRing(SectorNr, ring);
		this->setSectorName(SectorNr, name);
	}

	void setSectorRing(int SectorNr, int ring) {
		if (SectorNr < MIN_NR_SECTORS || SectorNr > MAX_NR_SECTORS) {
			throw new exception("Value out of range!");
		}
		if (SectorNr >= this->nrSectors) {
			throw new exception("Value out of range!");
		}
		if (ring >= MIN_NR_RINGS && ring <= MAX_NR_RINGS) {
			(*this)[SectorNr].ring = ring;
		}
		else {
			throw new exception("Value out of range!");
		}
	}

	int getSectorRing(int SectorNr) {
		return (*this)[SectorNr].ring;
	}

	void setSectorNrRows(int SectorNr, int nrRows) {
		if (SectorNr < MIN_NR_SECTORS || SectorNr > MAX_NR_SECTORS) {
			throw new exception("Value out of range!");
		}
		if (SectorNr >= this->nrSectors) {
			throw new exception("Value out of range!");
		}
		if (nrRows >= MIN_NR_ROWS && nrRows <= MAX_NR_ROWS) {
			(*this)[SectorNr].nrRows = nrRows;
		}
		else {
			throw new exception("Value out of range!");
		}
	}

	int getSectorNrRows(int SectorNr) {
		return (*this)[SectorNr].nrRows;
	}

	void setSectorNrSeatsPerRow(int SectorNr, int nrSeatsPerRow) {
		if (SectorNr < MIN_NR_SECTORS || SectorNr > MAX_NR_SECTORS) {
			throw new exception("Value out of range!");
		}
		if (SectorNr >= this->nrSectors) {
			throw new exception("Value out of range!");
		}
		if (nrSeatsPerRow >= MIN_NR_SEATS_PER_ROW && nrSeatsPerRow <= MIN_NR_SEATS_PER_ROW) {
			(*this)[SectorNr].nrSeatsPerRow = nrSeatsPerRow;
		}
		else {
			throw new exception("Value out of range!");
		}
	}

	int getSectorNrSeatsPerRow(int SectorNr) {
		return (*this)[SectorNr].nrSeatsPerRow;
	}

	void setSectorIsAvailable(int SectorNr, bool isAvailable) {
		if (SectorNr < MIN_NR_SECTORS || SectorNr > MAX_NR_SECTORS) {
			throw new exception("Value out of range!");
		}
		if (SectorNr >= this->nrSectors) {
			throw new exception("Value out of range!");
		}
		else {
			(*this)[SectorNr].isAvailable = isAvailable;
		}
	}

	bool getSectorIsAvailable(int SectorNr) {
		return (*this)[SectorNr].isAvailable;
	}

	void setSectorName(int SectorNr, int name) {
		if (SectorNr < MIN_NR_SECTORS || SectorNr > MAX_NR_SECTORS) {
			throw new exception("Value out of range!");
		}
		if (SectorNr >= this->nrSectors) {
			throw new exception("Value out of range!");
		}
		if (name < 0) {
			throw new exception("Value out of range!");
		}
		else {
			(*this)[SectorNr].name = name;
		}
	}

	int getSectorName(int SectorNr) {
		return (*this)[SectorNr].name;
	}

	Stadium(const Stadium& s) {
		this->nrSectors = s.nrSectors;
		this->isAvailable = s.isAvailable;
		if (s.address != nullptr) {
			this->address = new char[strlen(s.address) + 1];
			strcpy_s(this->address, strlen(s.address) + 1, s.address);
		}
		else {
			this->address = nullptr;
		}
		strcpy_s(this->name, 31, s.name);
		for (int i = 0; i < this->nrSectors; i++) {
			this->sector[i] = s.sector[i];
		}
		this->id++;
		this->idP = this->id;
	}

	void printStadium() const {
		cout << "Id : " << this->id;
		cout << endl << "Name : " << this->name;
		cout << endl << "Address : " << this->address;
		cout << endl << "Number of sectors : " << this->nrSectors;
		for (int i = 0; i < this->nrSectors; i++) {
			cout << endl << endl << "Sector name : " << this->sector[i].name;
			cout << endl << "Sector ring : " << this->sector[i].ring;
			cout << endl << "Sector  rows : " << this->sector[i].nrRows;
			cout << endl << "Sector  seats per row : " << this->sector[i].nrSeatsPerRow;
		}
	}

	void readStadium() {
		this->id--;
		this->isAvailable = true;
		cout << "Name : ";
		char name[31];
		cin.getline(name, 31);
		strcpy_s(this->name, 31, name);
		cout << endl << "Address : ";
		char address[100];
		cin.getline(address, 100);
		if (this->address != nullptr) {
			delete[] this->address;
			this->address = nullptr;
		}
		this->address = new char[strlen(address)+1];
		strcpy_s(this->address, strlen(address) + 1, address);
		cout << endl << "Number of sectors : ";
		int nrSectors;
		cin >> nrSectors;
		cin.get();
		if (nrSectors >= MIN_NR_SECTORS && nrSectors <= MAX_NR_SECTORS) {
			this->nrSectors = nrSectors;
		}
		else {
			throw new exception("Invalid input");
		}
		int s_name;
		int ring;
		int nrRows;
		int nrSeatsPerRow;
		for (int i = 0; i < this->nrSectors; i++) {
			this->sector[i].isAvailable = true;
			cout << endl << endl << "Sector name : ";
			cin >> s_name;
			this->sector[i].name = s_name;
			cout << endl << "Sector ring : ";
			cin >> ring;
			if (ring >= MIN_NR_RINGS && ring <= MAX_NR_RINGS) {
				this->sector[i].ring = ring;
			}
			else {
				throw new exception("Invalid input");
			}
			cout << endl << "Sector  rows : ";
			cin >> nrRows;
			if (nrRows >= MIN_NR_ROWS && nrRows <= MAX_NR_ROWS) {
				this->sector[i].nrRows = nrRows;
			}
			else {
				throw new exception("Invalid input");
			}
			cout << endl << "Sector  seats per row : ";
			cin >> nrSeatsPerRow;
			if (nrSeatsPerRow >= MIN_NR_SEATS_PER_ROW && nrSeatsPerRow <= MAX_NR_SEATS_PER_ROW) {
				this->sector[i].nrSeatsPerRow;
			}
			else {
				throw new exception("Invalid input");
			}
		}
		this->id++;
		this->idP = this->id;
	}

	Stadium& operator=(const Stadium& s) {
		if (this == &s)
			return *this;
		this->nrSectors = s.nrSectors;
		this->isAvailable = s.isAvailable;
		if (s.address != nullptr) {
			if (this->address != nullptr) {
				delete[] this->address;
				this->address = nullptr;
			}
			this->address = new char[strlen(s.address) + 1];
			strcpy_s(this->address, strlen(s.address) + 1, s.address);
		}
		else {
			if (this->address != nullptr) 
				delete[] this->address;
			this->address = nullptr;
		}
		strcpy_s(this->name, 31, s.name);
		for (int i = 0; i < this->nrSectors; i++) {
			this->sector[i] = s.sector[i];
		}
		return *this;
	}

	Sector& operator[](int index) {
		if (index >= 0 && index < this->nrSectors) {
			return this->sector[index];
		}
		else {
			throw exception("Ingex out of range");
		}
	}

	bool operator==(Stadium& s) {
		if (this->isAvailable != s.isAvailable)
			return false;
		if (strcmp(this->name, s.name) != 0)
			return false;
		if (this->address == nullptr && s.address != nullptr)
			return false;
		if (this->address != nullptr && s.address == nullptr)
			return false;
		if (this->address != nullptr && s.address != nullptr && strcmp(this->address, s.address) != 0)
			return false;
		if(this->nrSectors!=s.nrSectors)
			return false;
		for (int i = 0; i < this->nrSectors; i++) {
			if ((*this)[i].isAvailable != s[i].isAvailable)
				return false;
			if ((*this)[i].name != s[i].name)
				return false;
			if ((*this)[i].nrSeatsPerRow != s[i].nrSeatsPerRow)
				return false;
			if ((*this)[i].nrRows != s[i].nrRows)
				return false;
			if ((*this)[i].ring != s[i].ring)
				return false;
		}
		return true;
	}

	int getTotalSeats() {
		int sum = 0;
		for (int i = 0; i < this->nrSectors; i++) {
			sum += (*this)[i].nrRows * (*this)[i].nrSeatsPerRow;
		}
		return sum;
	}

	bool operator>=(Stadium& s) {
		return (this->getTotalSeats() >= s.getTotalSeats());
	}

	explicit operator int() {
		return this->getTotalSeats();
	}

	//pre
	Stadium operator++() {
		if (this->nrSectors + 1 > MAX_NR_SECTORS) {
			throw new exception("Imposible operation");
		}
		else {
			this->nrSectors += 1;
			for (int i = this->nrSectors-1; i < this->nrSectors; i++) {
				(*this)[i].name = 0;
			}
			return *this;
		}
	}

	//post
	Stadium operator++(int) {
		Stadium copy = *this;
		if (this->nrSectors + 1 > MAX_NR_SECTORS) {
			throw new exception("Imposible operation");
		}
		else {
			this->nrSectors += 1;
			for (int i = copy.nrSectors; i < this->nrSectors; i++) {
				(*this)[i].name = 0;
			}
		}
		return copy;
	}

	bool operator!() {
		bool copy = !this->isAvailable;
		return copy;
	}

	Stadium operator+(int value) {
		Stadium copy = *this;
		if (copy.nrSectors + value > MAX_NR_SECTORS) {
			throw new exception("Imposible operation");
		}
		copy.nrSectors += value;
		for (int i = this->nrSectors; i < copy.nrSectors; i++) {
			copy[i].name = 0;
		}
		return copy;
	}

	Stadium operator-(int value) {
		Stadium copy = *this;
		if (value<MIN_NR_SECTORS || value>MAX_NR_SECTORS) {
			throw new exception("Invalid input!");
		}
		if (value > copy.nrSectors) {
			throw new exception("Invalid input!");
		}
		else {
			for (int i = value + 1; i < this->nrSectors; i++)
				copy[i - 1] = copy[i];
		}
		copy.nrSectors--;
		return copy;
	}

	friend Stadium operator+(int value, const Stadium& s);
	friend void writeStadiumToFile(const Stadium& s);
	friend Stadium readStadiumFromFile(string fname, int id);
};

Stadium operator+(int value, const Stadium& s) {
	Stadium copy = s;
	if (copy.nrSectors + value > Stadium::MAX_NR_SECTORS) {
		throw new exception("Imposible operation");
	}
	copy.nrSectors += value;
	for (int i = s.nrSectors; i < copy.nrSectors; i++) {
		copy[i].name = 0;
	}
	return copy;
}

ostream& operator<<(ostream& out, const Stadium& s) {
	s.printStadium();
	return out;
}

istream& operator>>(istream& in, Stadium& s) {
	s.readStadium();
	return in;
}

int Stadium::MAX_NR_SEATS = 100000;
int Stadium::MIN_NR_SEATS = 50;
int Stadium::MAX_NR_SECTORS = 200;
int Stadium::MIN_NR_SECTORS = 0;
int Stadium::MAX_NR_SEATS_PER_ROW = 50;
int Stadium::MIN_NR_SEATS_PER_ROW = 1;
int Stadium::MAX_NR_ROWS = 20;
int Stadium::MIN_NR_ROWS =1 ;
int Stadium::MAX_NR_RINGS = 4;
int Stadium::MIN_NR_RINGS = 1;
int Stadium::id = setId("Places.bin");

void writeStadiumToFile(const Stadium& s) {
	//fstream f("Places.bin", ios::binary | ios::in | ios::ate);
	fstream f("Places.bin", ios::binary | ios::app);
	if (!f) {
		throw exception("No file");
	}
	typeP Place = Stadium_;
	int TotalSize = (s.nrSectors * 4 + 3) * sizeof(int) + sizeof(char) * 31 + sizeof(char) * (strlen(s.address) + 1) + sizeof(bool) + sizeof(typeP);
	f.write((char*)&TotalSize, sizeof(int));
	f.write((char*)&Place, sizeof(typeP));
	f.write((char*)&s.idP, sizeof(int));
	f.write(s.name, sizeof(char) * 31);
	f.write((char*)&s.nrPermanentlyFree, sizeof(int));
	f.write((char*)&s.isAvailable, sizeof(bool));
	f.write(s.address, sizeof(char) * (strlen(s.address) + 1));
	f.write((char*)&s.nrSectors, sizeof(int));
	for (int i = 0; i < s.nrSectors; i++) {
		f.write((char*)&s.sector[i].name, sizeof(int));
		f.write((char*)&s.sector[i].nrRows, sizeof(int));
		f.write((char*)&s.sector[i].nrSeatsPerRow, sizeof(int));
		f.write((char*)&s.sector[i].ring, sizeof(int));
		f.write((char*)&s.sector[i].isAvailable, sizeof(int));
	}

	f.seekg(ios::beg);
	int value;
	f.read((char*)&value, sizeof(int));
	value++;
	f.seekp(0, ios::beg);
	f.write((char*)&value, sizeof(int));

	f.close();
}

void createStadium() {
	Stadium s;
	cin >> s;
	writeStadiumToFile(s);
}

Stadium readStadiumFromFile(string fname, int id) {
	//fstream f(fname.c_str(), ios::binary | ios::in | ios::ate);
	fstream f(fname.c_str(), ios::binary | ios::app);
	if (!f) {
		throw exception("No file");
	}
	Stadium s;
	int value;
	f.read((char*)&value, sizeof(int));
	for (int i = 1; i < value; i++) {
		int totalSize;
		f.read((char*)&totalSize, sizeof(int));
		typeP place;
		f.read((char*)&place, sizeof(typeP));
		if (place !=Stadium_) {
			f.seekg(totalSize - sizeof(int) - sizeof(typeP), ios::cur);
			continue;
		}
		int idP;
		f.read((char*)&idP, sizeof(int));
		if (idP != id) {
			f.seekg(totalSize - sizeof(int) - sizeof(typeP) - sizeof(int), ios::cur);
			continue;
		}
		f.read(s.name, sizeof(char) * 31);
		f.read((char*)&s.nrPermanentlyFree, sizeof(int));
		f.read((char*)&s.isAvailable, sizeof(bool));
		char add[100];
		f.read(add, sizeof(char)*100);
		s.address = new char[strlen(add) + 1];
		strcpy_s(s.address, strlen(add) + 1, add);
		f.read((char*)&s.nrSectors, sizeof(int));
		for (int i = 0; i < s.nrSectors; i++) {
			f.read((char*)&s.sector[i].name, sizeof(int));
			f.read((char*)&s.sector[i].nrRows, sizeof(int));
			f.read((char*)&s.sector[i].nrSeatsPerRow, sizeof(int));
			f.read((char*)&s.sector[i].ring, sizeof(int));
			f.read((char*)&s.sector[i].isAvailable, sizeof(int));
		}
		break;
	}
	f.close();
	return s;
}