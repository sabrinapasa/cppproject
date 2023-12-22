#pragma once
#include<iostream>
#include<string>

using namespace std;

enum typeP{Concert_, Theatre_, Cinema_Hall_, Stadium_};
enum typeE{CONCERT, THEATRE, CINEMA_HALL, STADIUM, NOT_KNOWN};

class Event {
private:
	typeE typeEvent;
	string name;
	string dateTime;
	int id;
	int id_place;

public:
	Event() {
		this->name = "NONE";
		this->dateTime = "NOT KNOWN";
		this->typeEvent=NOT_KNOWN;
		this->id = 0;
		this->id_place = 0;
	}

	Event(string name, string dateTime,int id, int id_place, typeE typeEvent) {
		this->name = name;
		this->dateTime = dateTime;
		this->typeEvent = typeEvent;
		this->id = id;
		this->id_place = id_place;
	}

	~Event() {

	}

	Event(const Event& e) {
		this->name = e.name;
		this->dateTime = e.dateTime;
		this->typeEvent = e.typeEvent;
		this->id = e.id;
		this->id_place = e.id_place;
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
		cout << endl << "Event ID: ";
		cin >> this->id;
		if (this->id <= 0) {
			throw exception("Invalid input!");
		}
		cout << endl << "Event date: ";
		cin >> this->dateTime;
		cout << endl << "Event ID_place: ";
		cin >> this->id_place;
		if (this->id_place <= 0) {
			throw exception("Invalid input!");
		}
	}

	friend void writeEventToFile(const Event& e);
};

ostream& operator<<(ostream& out, const Event& e) {
	e.printEvent();
	return out;
}

istream& operator>>(istream& in, Event& e) {
	e.readEvent();
	return in;
}

void writeEventToFile(const Event& e) {
	//fstream f("Places.bin", ios::binary | ios::in | ios::ate);
	fstream f("Events.bin", ios::binary | ios::app);
	if (!f) {
		throw exception("No file");
	}
	int TotalSize = 3 * sizeof(int) + sizeof(typeE) + e.name.size() + 1 + e.dateTime.size() + 1;
	f.write((char*)&TotalSize, sizeof(int));
	f.write((char*)&e.typeEvent, sizeof(typeE));
	f.write((char*)&e.id_place, sizeof(int));
	f.write(e.name.c_str(), e.name.size() + 1);
	f.write((char*)&e.id, sizeof(int));
	f.write(e.dateTime.c_str(), e.dateTime.size() + 1);

	f.close();
}

void createEvent() {
	Event e;
	cin >> e;
	writeEventToFile(e);
}

