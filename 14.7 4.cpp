#include <iostream>
#include "Person.h"
#include <cstring>

const  int SIZE = 3;

int main()
{
    using std::cout;
	using std::cin;
	using std::endl;
	using std::strchr;

	Person* mankind[SIZE];
	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the mankind category:\n"
			<< "g:gunslinger  p:pokerplyer "
			<< " b:baddude  q:quit\n";
		cin >> choice;
		while (strchr("gpbq", choice) == NULL)
		{
			cout << "Please enter a g, p, b, or q: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch (choice)
		{
		case 'g': mankind[ct] = new Gunslinger;
			break;
		case 'p':mankind[ct] = new PokerPlayer;
			break;
		case 'b':mankind[ct] = new BadDude;
			break;
		}
		//cin.get();
		mankind[ct]->Set();
	}
	cout << "\nHere is your staff:\n";
	int i;
	for (i = 0; i <ct; i++)
	{
		cout << endl;
		mankind[i]->Show();
	}
	for (i = 0; i <ct; i++)
		delete mankind[i];

	cout << "Bye.\n";
	return 0;
}
