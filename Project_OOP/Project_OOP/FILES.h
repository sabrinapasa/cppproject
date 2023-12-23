#pragma once
#include<iostream>
#include<fstream>

using namespace std;

int setId(string fname) {
	//fstream f(fname.c_str(), ios::binary | ios::in | ios::ate);
	fstream f(fname.c_str(), ios::binary | ios::app);
	if (!f) {
		cout << endl << "No file exists.";
	}
	if (f.tellg() == 0) {
		int defaultValue = 0;
		f.write((char*)&defaultValue,sizeof(int));
		return 0;
	}
	f.seekg(ios::beg);
	int id;
	f.read((char*)&id, sizeof(int));

	f.close();
	return id;
}