#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"event.h"
#include"FILES.h"

using namespace std;

enum status{MADE, BOUGHT, VALIDATED};

class Tickets {
	Event e;
	int id;
	float price;
	vector<string> info;

public:
	static int nrTickets;

	Tickets(){
		this->price = 0;
		this->nrTickets++;
		this->id = this->nrTickets;
	}

	~Tickets() {

	}

	Tickets(float price,int idEvent){
		this->price = price;
		this->nrTickets++;
		this->id = this->nrTickets;
		this->e = readEventFromFile("Events.bin",idEvent);
	}

	void makeTickets(string fname) {
		fstream f(fname.c_str(), ios::binary | ios::app);
		if (!f) {
			throw exception("No file");
		}
		if (this->e.getType() == CONCERT) {
			Concert c = readConcertFromFile("Places.bin", this->e.getId_place());
			string a = "";
			a += "Concert ";
			a += c.getName();
			this->info.push_back(a);
			this->info.push_back(this->e.getDateTime());
			this->info.push_back("");
			for (int i = 0; i < c.getNrPersons(); i++) {
				a = "Ticket nr ";
				a += i + 1;
				this->info[2] = a;
				this->writeTicketToFile(fname);
			}
			this->info.clear();
		}
		if (this->e.getType() == CINEMA_HALL) {
			CinemaHall c = readCinemaFromFile("Places.bin", this->e.getId_place());
			string a = "";
			a += "Cinema ";
			a += c.getName();
			this->info.push_back(a);
			this->info.push_back(this->e.getDateTime());
			this->info.push_back("");
			int* b = c.getNrSeats();
			for (int i = 0; i < c.getNrRows(); i++) {
				for (int j = 1; j <= b[i]; j++) {
					a = "Row ";
					a += (i + 1);
					a += " Seat ";
					a += j;
					this->info[2] = a;
					this->writeTicketToFile(fname);
				}
			}
			delete[] b;
			this->info.clear();
		}
	}

	void writeTicketToFile(string fname) {

	}
};

int Tickets::nrTickets = setId("Tickets.bin");

void createTickets() {

}
