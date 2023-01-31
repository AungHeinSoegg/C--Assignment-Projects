#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>

using namespace std;
	
class member

{
private:
	string name, id_no, type, point;

public:
	void addMember();
	void insert();
	void showDetail();
	void display();
};

void member::addMember()
{
	mainmenu:
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
	
	switch(choice)
	{
		case 1://add new member detail and adding another member for next in case 1.
		do
		{
			member::insert();
			member::showDetail();
			
				cout << "Add Anothe Member Detail (Y,N): ";
				cin >> x;
			break;
		
		case 3: 
		 display();
		 break;
		
		case 4:
			exit(0);
			break;
			
			
		} 
		while (x == 'y' || x == 'Y');
		system("PAUSE"); 
		break;
		
		default:
		cout << "\n\t\t\t Invaild choice...Please Try Again...";
		system("PAUSE");
		break;
	}
	goto mainmenu;

}
void member::insert() // Adding Member Detail.
{
	system("cls");
	fstream file;
	cout << "=====> ADD NEW MEMBER <=====" << endl;

	cout << "Enter Member Name: ";
	cin >> name;
	cout << "Enter Member ID  : ";
	cin >> id_no;
	cout << "Enter Member's Type(Ordinary/ Sailver/ Gold): ";
	cin >> type;
	cout << "Enter Member Credit Point: ";
	cin >> point;
	file.open("MemberDetail.txt", ios::app | ios::out); // Member datila Text Fil Creating.
	file << " " << name << " " << id_no << " " << type << " " << point << "\n";
	file.close();
}
void member::showDetail()
{
	system("cls");
	fstream file;
	cout << "=====> WELCOME <=====" << endl;
	cout<<"Member Name 	: "<<name<<endl;
	cout<<"Member Number: "<<id_no<<endl;
	cout<<"Member Type	: "<<type<<endl;
	cout<<"Credit Point	: "<<point<<endl;
	cout<<"......................." << endl;	
}	
void member::display()
{
	system("cls");
	fstream file;
	int total = 0;
	cout << "\t\t\t*| MEMBER RECORD TABLE |*" << endl;
	cout << "\t\t\t=========================" << endl;
	file.open("MemberDetail.txt", ios::in);
	if (!file)
	{
		cout << "\n\t\t\t NO MEMBER DETAIl !!!";
		file.close();
	}
	else
	{
		file >> name >> id_no >> type >> point;
		while (!file.eof())
		{
			cout << " \nMember No.: " << total++ << endl;
			cout << " Member Name: " << name << endl;
			cout << " Member ID: " << id_no << endl;
			cout << " Member Type: " << type << endl;
			cout << " Member's Credit Point: " << point << endl;
			file >> name >> id_no >> type >> point;
		}
		if (total == 0)
		{
			cout << "\n\t\t\t NO MEMBER DETAIl !!!";
		}
	}
	file.close();
}
int main()
{
	member m;
	m.addMember();
	m.insert();
	m.showDetail();
	m.display();
}

