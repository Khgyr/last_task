#include "pch.h"
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
ifstream in("infile.txt");
ofstream out("outfile.txt");
struct vedom {
	int kol;
	float ves;
	string fam, im, otch;
	void show();
	void output();
};
void vedom::show() {
	cout <<'\t'<< setiosflags(ios::left) << setw(20) << fam << setw(20) << im << setw(20) << otch << setw(5) << kol << setw(5) << ves << endl;
}
void vedom::output() {
	out <<'\t'<< setiosflags(ios::left) << setw(20)<< fam << setw(20) << im << setw(20) << otch << setw(5)<< kol << setw(5) << ves << endl;
}
int main()
{
	vedom pass[50];
	int v, n = 0, j = 0;
	if (!in) { cout << "error opening infile\n"; }
	else {
		while (in.peek() != EOF) {
			in >> pass[n].fam;
			in >> pass[n].im;
			in >> pass[n].otch;
			in >> pass[n].kol;
			in >> pass[n].ves;
			++n;
		}
		--n;
		for (int i = 0; i < n; ++i) {
			pass[i].show();
		}
		cout << endl;
		cout <<'\t'<< "Enter ves: "; cin >> v;
		if (!out) { cout<<"error opening outfile\n"; }
		else {
			for (int i = 0; i < n && !j; ++i) {
				if (pass[i].ves < v) {
					for (j = i; j < n; ++j) {
						pass[j] = pass[j + 1];
					}
					--n;
				}
			}
			for (int i = 0; i < n; ++i) { pass[i].output(); }
		}
	}
	in.close();
	out.close();
	return 0;
}