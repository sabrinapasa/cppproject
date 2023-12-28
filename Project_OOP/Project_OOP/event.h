#pragma once
#include<iostream>
#include<string>
#include"FILES.h"

using namespace std;

enum typeP{Concert_, Theatre_, Cinema_Hall_, Stadium_};
enum typeE{CONCERT, THEATRE, CINEMA_HALL, STADIUM, NOT_KNOWN};

class Event {
protected:
	typeE typeEvent;
	string name;
	string dateTime;
	int id;
	int id_place;

public:
	static int nrEvent;

	Event() {
		this->name = "NONE";
		this->dateTime = "NOT KNOWN";
		this->typeEvent=NOT_KNOWN;
		this->id_place = 0;
		this->nrEvent++;
		this->id = this->nrEvent;
	}

	friend Event readEventFromFile(string fname, int id);
	
	typeE getType() {
		return this->typeEvent;
	}

	string getName() {
		return this->name;
	}

	string getDateTime() {
		return this->dateTime;
	}

	int getId() {
		return this->id;
	}

	int getId_place() {
		return this->id_place;
	}

	/*Event(int id) {
		*this = readEventFromFile("Events.bin", id);
	}*/

	Event(string name, string dateTime, int id_place, typeE typeEvent) {
		this->name = name;
		this->dateTime = dateTime;
		this->typeEvent = typeEvent;
		this->id_place = id_place;
		this->nrEvent++;
		this->id = this->nrEvent;
	}

	~Event() {

	}

	Event(const Event& e) {
		this->name = e.name;
		this->dateTime = e.dateTime;
		this->typeEvent = e.typeEvent;
		this->id_place = e.id_place;
		this->nrEvent++;
		this->id = this->nrEvent;
	}

	Event& operator=(const Event& e) {
		if (this == &e) {
			return *this;
		}
		this->name = e.name;
		this->dateTime = e.dateTime;
		this->typeEvent = e.typeEvent;
		this->id = e.id;
		this->id_place = e.id_place;
	}

	void printEvent() const {
		cout << endl << "Event name: " << this->name;
		cout << endl << "Event type: ";
		if (this->typeEvent == CINEMA_HALL) {
			cout << "Cinema_Hall";
		}
		if (this->typeEvent == CONCERT) {
			cout << "Concert";
		}
		if (this->typeEvent == STADIUM) {
			cout << "Stadium";
		}
		if (this->typeEvent == THEATRE) {
			cout << "Theatre";
		}
		if (this->typeEvent == NOT_KNOWN) {
			cout << "Not known";
		}
		cout << endl << "Event ID: " << this->id;
		cout << endl << "Event date: " << this->dateTime;
		cout << endl << "Event ID_place: " << this->id_place;
	}

	void readEvent() {
		this->nrEvent--;
		cout << endl << "Event name: ";
		cin >> this->name;
		cout << endl << "Event type: ";
		string EventType;
		cin >> EventType;
		while (true) {
			if (EventType == "Cinema") {
				this->typeEvent = CINEMA_HALL;
				break;
			}
			if (EventType == "Concert") {
				this->typeEvent = CONCERT;
				break;
			}
			if (EventType == "Stadium") {
				this->typeEvent = STADIUM;
				break;
			}
			if (EventType == "Theatre") {
				this->typeEvent = THEATRE;
				break;
			}
			cout << endl << "Event type: ";
			cin >> EventType;
		}
		cout << endl << "Event date: ";
		cin >> this->dateTime;
		cout << endl << "Event ID_place: ";
		cin >> this->id_place;
		if (this->id_place <= 0) {
			throw exception("Invalid input!");
		}
		this->nrEvent++;
		this->id = this->nrEvent;
	}

	friend void writeEventToFile(const Event& e);
	
};

int Event::nrEvent = setId("Events.bin");

ostream& operator<<(ostream& out, const Event& e) {
	e.printEvent();
	return out;
}

istream& operator>>(istream& in, Event& e) {
	e.readEvent();
	return in;
}

void writeEventToFile(const Event& e) {
	//fstream f("Events.bin", ios::binary | ios::in | ios::ate);
	fstream f("Events.bin", ios::binary | ios::app);
	if (!f) {
		throw exception("No file");
	}
	int TotalSize = 4 * sizeof(int) + sizeof(typeE) + e.name.size() + 1 + e.dateTime.size() + 1;
	f.write((char*)&TotalSize, sizeof(int));
	f.write((char*)&e.typeEvent, sizeof(typeE));
	f.write((char*)&e.id_place, sizeof(int));
	int a = e.name.size() + 1;
	f.write((char*)&a, sizeof(int));
	f.write(e.name.c_str(), e.name.size() + 1);
	f.write((char*)&e.id, sizeof(int));
	int b = e.dateTime.size() + 1;
	f.write((char*)&b, sizeof(int));
	f.write(e.dateTime.c_str(), e.dateTime.size() + 1);

	f.seekg(0,ios::beg);
	int value;
	f.read((char*)&value, sizeof(int));
	value++;
	f.seekp(0, ios::beg);
	f.write((char*)&value, sizeof(int));

	f.close();
}

void createEvent() {
	Event e;
	cin >> e;
	writeEventToFile(e);
}

Event readEventFromFile(string fname, int id) {
	fstream f(fname.c_str(), ios::binary | ios::app);
	if (!f) {
		throw exception("No file");
	}
	Event e;
	e.nrEvent--;
	int value;
	char buffer[100];
	f.read((char*)&value, sizeof(int));
	for (int i = 0; i < value; i++) {
		int TotalSize;
		int currentPos = f.tellg();
		f.read((char*)&TotalSize, sizeof(int));
		f.read((char*)&e.typeEvent, sizeof(typeE));
		f.read((char*)&e.id_place, sizeof(int));
		int a;
		f.read((char*)&a, sizeof(int));
		f.read((char*)buffer, a);
		e.name = buffer;
		f.read((char*)&e.id, sizeof(int));
		if (e.id != id) {
			f.seekg(TotalSize + currentPos, ios::beg);
			continue;
		}
		int b;
		f.read((char*)&b, sizeof(int));
		f.read((char*)buffer, b);
		e.dateTime = buffer;
		break;
	}
	f.close();
	return e;
}