#include<iostream>
#include<string>
#include"calfunc.h"
using namespace std;
int main() {
	calfunc function;
	bool amalgar = false;
	cout << "Please Select Your Operation:\n\n" << "\t1:sine\n" << "\t2:cosine\n" << "\t3:tangent\n" << "\t4:cotangent\n" << "\t5:logarithm\n"
		<< "\t6:Ln\n" << "\t7:Power\n" << "\t8:factorial\n" << "\t9:radical\n" << "\t0:calculator (this item means an expression containing the desired number of addition, subtraction,\n\t  multiplication and division operations with numbers with desired digits)\n\n" << "Enter the operation number you want:\n";
	int a, l;
	cin >> a;
	system("cls");
	string x;
	cout << "enter your number\n";
	cin >> x;
	l = x.size();
	for (int i = 0; i < l; i++) {
		if (x[i] == 'p')
			x.replace(i, 1, "3.141592");
		else if (x[i] == 'e')
			x.replace(i, 0, "2.71828182");
	}
	for (int i = 0; i < x.size(); i++) {
		if (x[i] == '+' || x[i] == '-' || x[i] == '*' || x[i] == '/') {
			amalgar = true;
		}
		if (amalgar == true) {
			function.calculator(x);
		}
	}
	if (a == 0) {
		cout << function.calculator(x);
	}
	if (a == 1) {
		double s;
		s = stod(x.substr().c_str());
		cout << function.sine(s);
	}
	else if (a == 2) {
		double s;
		s = stod(x.substr().c_str());
		cout << function.cosine(s);
	}
	else if (a == 3) {
		double s;
		s = stod(x.substr().c_str());
		cout << function.tangent(s);
	}
	else if (a == 4) {
		double s;
		s = stod(x.substr().c_str());
		cout << function.cotangent(s);
	}
	else if (a == 5) {
		double s;
		s = stod(x.substr().c_str());
		int a;
		cout << "enter the base of logarithm value:\n";
		cin >> a;
		cout << function.logarithm(s, a);
	}
	else if (a == 6) {
		double s;
		s = stod(x.substr().c_str());
		cout << function.Ln(s);
	}
	else if (a == 7) {
		double s;
		s = stod(x.substr().c_str());
		int q;
		cout << "enter the power value:\n";
		cin >> q;
		cout << function.Pow(s, q);
	}
	else if (a == 8) {
		double s;
		s = stod(x.substr().c_str());
		cout << function.factorial(s);
	}
	else if (a == 9) {
		double s;
		s = stod(x.substr().c_str());
		int n;
		cout << "enter the index of radical value:\n";
		cin >> n;
		cout << function.radical(s, n);
	}
}