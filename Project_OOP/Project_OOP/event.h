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

	Event(const Event& e) {
		this->name = e.name;
		this->dateTime = e.dateTime;
		this->typeEvent = e.typeEvent;
		this->id = e.id;
		this->id_place = e.id_place;
	}

	
};