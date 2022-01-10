/*
Saum Yazdani
Program 5
11/22/20
*/

// including necessary libraries and header files
#include <iostream>
#include "audio.h"
#include "video.h"
#include <string>
#include <fstream>
#include <vector>
using namespace std;

// main that collects data from files
int main() {
	string id, nom, time, flet, format, quality, res, desc, qspec;
	vector <string> vid;
	vector <string> aud;
	ifstream ifile;
	ifile.open("input.txt");
	while (ifile.good()) {
		ifile >> flet;
		if (flet == "V") {
			ifile.ignore();
			getline(ifile, id);
			getline(ifile, nom);
			getline(ifile, time);
			getline(ifile, res);
			getline(ifile, desc);
			getline(ifile, qspec);
			vid.push_back(id);
			vid.push_back(nom);
			vid.push_back(time);
			vid.push_back(res);
			vid.push_back(desc);
			vid.push_back(qspec);
			vid.push_back("--------------------");
		}
		else if (flet == "A") {
			ifile.ignore();
			getline(ifile, id);
			getline(ifile, nom);
			getline(ifile, time);
			getline(ifile, format);
			getline(ifile, quality);
			aud.push_back(id);
			aud.push_back(nom);
			aud.push_back(time);
			aud.push_back(format);
			aud.push_back(quality);
			aud.push_back("--------------------");
		}
	}
	ifile.close();
	ofstream ofile,ofile2;
	ofile.open("audioout");
	ofile2.open("videoout");
	for (int i = 0;i < aud.size();i++) {
		ofile << aud[i] << endl;
	}
	for (int i = 0;i < vid.size();i++) {
		ofile2 << vid[i] << endl;
	}
	ofile.close();
	ofile2.close();
}

