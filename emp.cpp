#include "emp.h"

abstr_emp::~abstr_emp() { }

void abstr_emp::ShowAll()const
{
   cout<< "firstname: " << fname << endl;
   cout << "lastname: " << lname << endl;
   cout << "job: " << job << endl;
}

void abstr_emp::SetAll()
{
	cout << "Enter firstname: ";
	getline(std::cin, fname);
	cout << "Enter lastname: ";
	getline(std::cin, lname);
	cout << "Enter job: ";
	getline(std::cin, job);
}

ostream& operator<<(ostream& os, const abstr_emp& e)
{
	os << "firstname: " << e.fname << " " << endl;
	os << "lastname: " << e.lname << endl;
	os << "job: " << e.job << endl;
	return os;
}

void employee::ShowAll()const
{
	abstr_emp::ShowAll();
}

void employee::SetAll()
{
	abstr_emp::SetAll();
}

void manager::ShowAll()const
{
	abstr_emp::ShowAll();
	cout << "Inchargeof: " << inchargeof << endl;
}

void manager::SetAll()
{
	abstr_emp::SetAll();
	cout << "Enter inchargeof: ";
	cin >> inchargeof;
	cin.get();
}

void fink::ShowAll()const
{
	abstr_emp::ShowAll();
	cout << "Reportsto: " << reportsto << endl;
}

void fink::SetAll()
{
	abstr_emp::SetAll();
	cout << "Enter reportsto: ";
	cin >> reportsto;
}


void highfink::ShowAll()const
{
	abstr_emp::ShowAll();
	cout << "Inchargeof: " << manager::InChargeOf() << endl;
	cout << "Reportsto: " << fink::ReportsTo() << endl;
}

void highfink::SetAll()
{
	abstr_emp::SetAll();
	cout << "Enter inchargeof: ";
	cin>>InChargeOf();
	cout << "Ennter reportsto: ";
	getline(cin, fink::ReportsTo());
	cin.get();
}
