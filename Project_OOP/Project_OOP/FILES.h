#pragma once
#include<iostream>
#include<fstream>

using namespace std;

int setId(string fname) {
	fstream f(fname.c_str(), ios::binary | ios::in | ios::ate);
	if (!f) {
		throw exception("No file");
	}
	if (f.eof()) {
		int defaultValue = 0;
		f.write((char*)&defaultValue,sizeof(int));
		return 0;
	}
	int id;
	f.read((char*)&id, sizeof(int));
	f.close();
	return id;
}