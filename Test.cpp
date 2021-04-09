#include <iostream>
#include <cmath>
#define f(y) y*y 

using namespace std;


void twoPoint(double x, double h);
void threePoint(double x, double y, double h);
void second(double x, double y, double h);
int tPy(double pm);


int main()
{
	setlocale(LC_ALL, "Russian");
	int userNumber = 0;
	do {
		int  choosemethod;
		double x, h, y;

		cout << "Enter your x ";
		cin >> x;
		cout << "Enter your y ";
		cin >> y;
		cout << "Enter your step ";
		cin >> h;


		cout << " 1) The first derivative by two-point methods \n";
		cout << " 2) The first derivative by three-point methods \n";
		cout << " 3) Finding the second derivative \n" << endl;

	uncorrect: cout << " Your chose: ";
		cin >> choosemethod;
		cout << endl << endl;

		switch (choosemethod) {

		case 1:
			cout << " First derivative by two-point methods \n" << endl << endl;
			twoPoint(x, h);

			break;

		case 2:
			cout << " First derivative by three-point methods \n" << endl << endl;
			threePoint(x, y, h);

			break;

		case 3:
			cout << " The second derivative\n" << endl << endl;
			second(x, y, h);

			break;

		default:
			cout << " Choose the correct option\n" << endl << endl;
			goto uncorrect;
		}

		cout << " Start over?" << endl << endl
			<< " 1 - Yes" << endl
			<< " 2 - No" << endl << endl
			<< " Your chose: ";
		cin >> userNumber;
		cout << endl << endl;
	} while (userNumber == 1);
}

//First derivative by two-point methods
void twoPoint(double x, double h) {
	double resultFirstMethod = 0.0, resultSecondMethod = 0.0, resultThirdMethod = 0.0, plus, minus, xxx, p, m;
	p = x + h;
	plus = tPy(p);
	m = x - h;
	minus = tPy(m);
	xxx = tPy(x);
	resultFirstMethod = (plus - xxx) / h;
	resultSecondMethod = (xxx - minus) / h;
	resultThirdMethod = (plus - minus) / (2 * h);
	cout << "First method = " << resultFirstMethod << endl;
	cout << "Second method = " << resultSecondMethod << endl;
	cout << "Third method = " << resultThirdMethod << endl;
}
int tPy(double pm) {
	double y;
	y = pm * pm;
	return y;
}
//First derivative by three-point methods
void threePoint(double x, double y, double h) {
	double rez1 = 0.0, rez2 = 0.0, rez3 = 0.0;

	rez1 = (1 / (2 * h)) * (-3 * f(x - h) + 4 * f(x) - f(x + h));
	rez2 = (1 / (2 * h)) * (f(x - h) + 0 * f(x) + f(x + h));
	rez3 = (1 / (2 * h)) * (f(x - h) - 4 * f(x) + 3 * f(x + h));

	cout << "1 Method = " << rez1 << endl;
	cout << "2 Method = " << rez2 << endl;
	cout << "2 Method = " << rez3 << endl;

}
//The second derivative
void second(double x, double y, double h) {
	double rez = 0.0;

	rez = (f(x + h) - 2 * f(x) + f(x - h)) / (h * h);

	cout << "Result = " << rez;
}


