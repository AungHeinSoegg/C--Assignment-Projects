#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>

using namespace std;

class member

{
private:

public:
	void addMember();
};

void member::addMember()
{

	int choice;
	char x;
	system("cls");
	
	cout << "Student Management System" << endl;
	cout << "<<<<<<<<--------->>>>>>>>" << endl;
	cout << "1. Add New Member" << endl;
	cout << "2. Modifies an EXisting Member" << endl;
	cout << "3. Display The Member Details From The File" << endl;
	cout << "4. Exit" << endl;
	
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << " Choose No For Confirm Your Option:[ 1/ 2/ 3/ 4]" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Enter Your Choose: ";
	cin >> choice;
	
	
}

int main()
{
	member m;
	m.addMember();
}

