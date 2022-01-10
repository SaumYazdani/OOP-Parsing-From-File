#pragma once
#include "parent.h"
#include "parent.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
//video file that inherits from parent media
class Video : public Media {
	//defining setters and getters that are unique to video data
public:
	Video();
	void setres(string ress) {
		res = ress;
	}
	void setdesc(string descc) {
		desc = descc;
	}
	void setqspec(string qspecc) {
		qspec = qspecc;
	}
	string getres() {
		return res;
	}
	string getdesc() {
		return desc;
	}
	string getqspec() {
		return qspec;
	}
	string gettype();
	void readdata(istream&);
	void writedata(ostream&);
protected:
	//defining variables unique to video data
	string res;
	string desc;
	string qspec;
};
//video default constructor that inherits from media, and adds unique elements
Video::Video() :Media() {
	res = "NULL";
	desc = "NULL";
	qspec = "NULL";
}
//setting gettype to return video
string Video::gettype() {
	return "Video";
}
//reading video data in
void Video::readdata(istream&) {
	ifstream ifile;
	ifile.open("input.txt");
	while (!EOF) {
		string id;
		string nom;
		string time;
		string ress;
		string descc;
		string qspecc;
		getline(ifile, id);
		setidentifier(id);
		getline(ifile, nom);
		setname(nom);
		getline(ifile, time);
		setruntime(time);
		getline(ifile, ress);
		setres(ress);
		getline(ifile, descc);
		setdesc(descc);
		getline(ifile, qspecc);
		setqspec(qspecc);
	}
	ifile.close();
}
//writing video data out and sending it to videoout
void Video::writedata(ostream&) {
	ofstream ofile;
	ofile.open("videoout.txt");
	ofile << getidentifier() << endl;
	ofile << getname() << endl;
	ofile << getruntime() << endl;
	ofile << getres() << endl;
	ofile << getdesc() << endl;
	ofile << getqspec() << endl;
	ofile << "-------------------------------------------";
	ofile.close();
}
