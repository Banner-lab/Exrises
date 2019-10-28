#include "Person.h"
#include <cstdlib>
#include <ctime>

Person::~Person() { }
void Person::Data()const
{
	cout << first_name << ", " << last_name << endl;
}

void Person::Get()
{
	cout << "Please enter the first_name:";
	cin >> first_name;
	cout << "Please enter the last_name:";
	cin >> last_name;
}

void Person::Show()const
{
	Data();
}

void Person::Set()
{
	Get();
}

void Gunslinger::Data()const
{
	cout << "There are " << guns_grad << " on the gun\n";
	cout << "You need " << times << " seconds show the gun\n";
}

void Gunslinger::Get()
{
	cout << "Please enter the nicks of guns:";
	cin >> guns_grad;
	cout << "Pleaase enter the time you need:";
	cin >> times;
	while (cin.get() != '\n')
		continue;
}

void Gunslinger::Set()
{
	Person::Get();
	Get();
}

void Gunslinger::Show()const
{
	Person::Data();
	Data();
}




void PokerPlayer::Show()const
{
	Person::Show();
	cout <<"The card is"<< Draw()<<endl;
}

void PokerPlayer::Set()
{
	Person::Get();
}

int PokerPlayer::Draw()const
{
	srand(time(0));
	int bl = rand() % 52 + 1;
	return bl;
}

void BadDude::Data()const
{
	
}

void BadDude::Get()
{

}

void BadDude::Show()const
{
	Person::Data();
	Gunslinger::Data();
	cout << "The card is " << PokerPlayer::Draw();
}

void BadDude::Set()
{
	Person::Get();
	Gunslinger::Get();
}

double BadDude::Gdraw()
{
	return Gunslinger::Draw();
}

int BadDude::Cdraw()const
{
	return PokerPlayer::Draw();
}
