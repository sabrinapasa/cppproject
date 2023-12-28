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
	int price = 80;
	vector<string> info;

public:
	static int nrTickets;

	Tickets(){
		this->price = 0;
		this->nrTickets++;
		this->id = this->nrTickets;
	}

	void printTickets() const {
		cout << "Ticket ID : " << this->id << endl;
		cout << "Ticket price : " << this->price << endl;
		cout << "Ticket info : ";
		for (int i = 0; i < 3; i++) {
			cout << endl;
			cout << this->info[i];
		}
	}

	~Tickets() {

	}

	Tickets(int price,int idEvent){
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
		if (this->e.getType() == THEATRE) {
			Theatre t = readTheatreFromFile("Places.bin", this->e.getId_place());
			string a = "";
			a += "Theatre ";
			a += t.getAddress();
			this->info.push_back(a);
			this->info.push_back(this->e.getDateTime());
			this->info.push_back("");
			int* b = t.getNrSeats();
			for (int i = 0; i < t.getNrRows(); i++) {
				for (int j = 1; j <= b[i]; j++) {
					a = "Row ";
					a += (i + 1);
					a += " Seat ";
					a += j;
					this->info[2] = a;
					this->writeTicketToFile(fname);
				}
			}
			for (int i = 0; i < t.getNrSeatsVIP(); i++) {
				a = "Nr. seat from VIP zone ";
				a += (i + 1);
				this->info[2] = a;
				this->writeTicketToFile(fname);
			}
			delete[] b;
			this->info.clear();
		}
		if (this->e.getType() == STADIUM) {
			Stadium s = readStadiumFromFile("Places.bin", this->e.getId_place());
			string a = "";
			a += "Stadium ";
			a += s.getName();
			this->info.push_back(a);
			this->info.push_back(this->e.getDateTime());
			this->info.push_back("");
			for (int i = 0; i < s.getNrSectors(); i++) {
				for (int j = 0; j < s.getSectorNrRows(i); j++) {
					for (int k = 0; k < s.getSectorNrSeatsPerRow(i); k++) {
						a = "Sector nr ";
						a += (i + 1);
						a += " Sector row nr ";
						a += (j + 1);
						a += " Seat ";
						a += (k + 1);
						this->info[2] = a;
						this->writeTicketToFile(fname);
					}
				}
			}
			this->info.clear();
		}
	}

	void writeTicketToFile(string fname) {
		fstream f(fname.c_str(), ios::binary | ios::app);
		if (!f) {
			throw exception("No file");
		}
		int a = this->info[0].size();
		int b = this->info[1].size();
		int c = this->info[2].size();
		int TotalSize = 6 * sizeof(int) + a + b + c;
		f.write((char*)&TotalSize, sizeof(int));
		f.write((char*)&this->id, sizeof(int));
		f.write((char*)&a, sizeof(int));
		f.write((char*)this->info[0].c_str(), a);
		f.write((char*)&b, sizeof(int));
		f.write((char*)this->info[1].c_str(), b);
		f.write((char*)&c, sizeof(int));
		f.write((char*)this->info[2].c_str(), c);
		f.write((char*)&this->price, sizeof(int));

		f.seekg(0, ios::beg);
		int value;
		f.read((char*)&value, sizeof(int));
		value++;
		f.seekp(0, ios::beg);
		f.write((char*)&value, sizeof(int));

		f.close();
	}

	friend Tickets readTicketFromFile(string fname, int id);
};

ostream& operator<<(ostream& out,const Tickets& t) {
	t.printTickets();
	return out;
}

int Tickets::nrTickets = setId("Tickets.bin");

void createTickets() {

}

Tickets readTicketFromFile(string fname, int id) {
	fstream f(fname.c_str(), ios::binary | ios::app);
	if (!f) {
		throw exception("No file");
	}
	Tickets t;
	t.nrTickets--;
	int value;
	f.read((char*)&value, sizeof(int));
	int a;
	int b;
	int c;
	char buffer[1000];
	for (int i = 0; i < value; i++) {
		int TotalSize;
		int currentPos = f.tellg();
		f.read((char*)&TotalSize, sizeof(int));
		int idT;
		f.read((char*)&idT, sizeof(int));
		if (idT != id) {
			f.seekg(TotalSize + currentPos, ios::beg);
			continue;
		}
		f.read((char*)&a, sizeof(int));
		f.read(buffer, a);
		t.info[0] = buffer;
		f.read((char*)&b, sizeof(int));
		f.read(buffer, b);
		t.info[1] = buffer;
		f.read((char*)&c, sizeof(int));
		f.read(buffer, c);
		t.info[2] = buffer;
		f.read((char*)&t.price, sizeof(int));
		break;
	}
	f.close();
	return t;
}