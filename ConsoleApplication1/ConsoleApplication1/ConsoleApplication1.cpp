#include "pch.h"
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
ifstream in("infile");
ofstream out("outfile");
struct vedom {
	int kol;
	float ves;
	string fam, im, otch;
	void show();
	void output();
};
void vedom::show() {
	cout << setw(3) << '\t' << fam << setw(3) << '\t' << im << setw(3) << '\t' << otch << setw(3) << '\t' << kol << setw(3) << '\t' << ves << endl;
}
void vedom::output() {
	out << setw(3) << '\t' << fam << setw(3) << '\t' << im << setw(3) << '\t' << otch << setw(3) << '\t' << kol << setw(3) << '\t' << ves << endl;
}
int main()
{
	vedom pass[50];
	int v, n = 0, j = 0;
	while (in.peek() != EOF) {
		in >> pass[n].fam;
		in >> pass[n].im;
		in >> pass[n].otch;
		in >> pass[n].kol;
		in >> pass[n].ves;
		++n;
	}
	for (int i = 0; i < n; ++i) {
		pass[i].show();
	}
	cout << "Enter ves: "; cin >> v;
	for (int i = 0; i < n && !j; ++i) {
		if (pass[i].ves < v) {
			for (j = i; j < n; ++j) {
				pass[j] = pass[j + 1];
			}
			--n;
		}
	}
	for (int i = 0; i < n; ++i) { pass[i].output(); }
	in.close();
	out.close();
	return 0;
}