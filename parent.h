#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//parent media class includes default constructor, definition of like terms and virtual io functions
class Media {
public:
	// defining default constructor, setters and getters, and virtual functions in public
	Media();
	void setidentifier(string id) {
		identifier = id;
	}
	void setname(string nom) {
		name = nom;
	}
	void setruntime(string rtime) {
		runtime = rtime;
	}
	string getidentifier() {
		return identifier;
	}
	string getname() {
		return name;
	}
	string getruntime() {
		return runtime;
	}
	virtual string gettype() const = 0;
	virtual void readdata(istream&);
	virtual void writedata(ostream&);
protected:
	// defining variables that are present across both audio and video data
	string identifier;
	string name;
	string runtime;
};
// default constructor
Media::Media() {
	identifier = "NULL";
	name = "NULL";
	runtime = "0";
}
// reading data in 
void Media::readdata(istream&) {
	ifstream ifile;
	ifile.open("input.txt");
	while (!EOF) {
		string id;
		string nom;
		string time;
		getline(ifile, id);
		setidentifier(id);
		getline(ifile, nom);
		setname(nom);
		getline(ifile, time);
		setruntime(time);
	}
	ifile.close();
}
//reading data out into default file (as placeholder)
void Media::writedata(ostream&) {
	ofstream ofile;
	ofile.open("outdefault");
	ofile << getidentifier() << endl;
	ofile << getname() << endl;
	ofile << getruntime() << endl;
	ofile << "-------------------------------------------";
	ofile.close();
}