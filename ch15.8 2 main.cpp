#include <iostream>
#include "exc_mean.h"
#include <cmath>

double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	double x, y, z;
	cout << "Enter two numbers: ";
	while (cin >> x >> y)
	{
		try
		{
			z = hmean(x, y);
			cout << "Harmonic mean of " << x << " and " << y
				<< " is " << z << endl;
			cout << "Geometric mean of " << x << " and " << y
				<< " is " << gmean(x, y) << endl;
			cout << "Enter next set of numbers <q to quit>: ";
		}
		catch (bad_bmean& bg)
		{
			cout << bg.what() << endl;
		}
		catch (bad_gmean & hg)
		{
			cout << hg.what() << endl;
		}
	}
	cout << "Bye!\n";
	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
		throw bad_bmean("Error: bad arguments for hmean()\n");
	return 2.0 * a * b / (a + b);
}


double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw  bad_gmean("Error: bad arguments for gmean()\n");
	return std::sqrt(a * b);
}
