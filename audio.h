#pragma once
#include "parent.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
//audio class that inherits from media parent
class Audio: public Media {
	//declaring all default constructors and unique getters/setters to audio data
public:
	Audio();
	void setformat(string formatt) {
		format = formatt;
	}
	void setquality(string qualityy) {
			quality = qualityy;
		}
	string getformat() {
		return format;
	}
	string getquality() {
		return quality;
	}
	void readdata(istream&);
	void writedata(ostream&);
	//declaring unique variables for audio data
protected:
	string format;
	string quality;
};
//default audio constructor that inherits from media's default constructor - adds format and quality variables
Audio::Audio() :Media() {
	format = "NULL";
	quality = "NULL";
}
//changes gettype to return audio
string gettype() {
	return "Audio";
}
//reading audio data from file
void Audio::readdata(istream&) {
	ifstream ifile;
	ifile.open("input.txt");
	while (!EOF) {
		string id;
		string nom;
		string time;
		string formatt;
		string qualityy;
		getline(ifile, id);
		setidentifier(id);
		getline(ifile, nom);
		setname(nom);
		getline(ifile, time);
		setruntime(time);
		getline(ifile, formatt);
		setformat(formatt);
		getline(ifile, qualityy);
		setquality(qualityy);
	}
	ifile.close();
}
//outputting audio data and sending it to adioout 
void Audio::writedata(ostream&) {
	ofstream ofile;
	ofile.open("audioout.txt");
	ofile << getidentifier() << endl;
	ofile << getname() << endl;
	ofile << getruntime() << endl;
	ofile << getformat() << endl;
	ofile << getquality() << endl;
	ofile << "-------------------------------------------";
	ofile.close();
}