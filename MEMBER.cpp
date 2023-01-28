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
	void display();
	void modify();

};
void member::addMember() // Display Menu For Member Management System.
{
	addMember:
	int choice;
	char x;
	system("cls");

	cout << "\t\t\t-----| MEMBER MANAGEMENT SYSTEM-----|" << endl;
	cout << "\t\t\t=====================================" << endl;
	cout << "\t\t\t 1. Add New Member To The File." << endl;
	cout << "\t\t\t 2. Modifies The Detials Of An Exiting Member." << endl;
	cout << "\t\t\t 3. Display The Member Details From The File." << endl;
	cout << "\t\t\t 4. Exit" << endl;

	cout << "\t\t\t=====================================" << endl;
	cout << "\t\t\tChoose Option:[1/ 2/ 3/ 4]" << endl;
	cout << "\t\t\t=====================================" << endl;
	cout << "Enter Your Choose Option: "<< endl;
	cin >> choice;

	switch (choice)
	{
	case 1://add new member detail and adding another member for next in case 1.
		do
		{
			member::insert();
			cout << "Add Anothe Member Detail (Y,N): ";
			cin >> x;
		} while (x == 'y' || x == 'Y');
		break;
	case 2:
		modify();
		break;
	case 3:
		display();
		system("PAUSE");
		break;

	case 4:
		exit(0);
		break;
	default:
		cout << "\n\t\t\t Invaild choice...Please Try Again...";
		system("PAUSE");
		break;
	}
	
	goto addMember;
}
void member::insert() // Adding Member Detail.
{
	system("cls");
	fstream file;
	cout << "=====> ADD NEW MEMBER <=====" << endl;

	cout << "Enter Member Name: ";
	cin >> name;
	cout << "Enter Member ID: ";
	cin >> id_no;
	cout << "Enter Member's Type(Ordinary/ Sailver/ Gold): ";
	cin >> type;
	cout << "Enter Member Credit Point: ";
	cin >> point;
	file.open("MemberDetail.txt", ios::app | ios::out); // Member datila Text Fil Creating.
	file << " " << name << " " << id_no << " " << type << " " << point << "\n";
	file.close();
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
void member::modify()
{
	system("cls");
	fstream file, file1;
	string id_no;
	int found = 0;

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
		cout << "Enter Member ID Which Member You Want To Modify: ";
		cin >> id_no;
		file1.open("Detail.txt", ios::app | ios::out);
		file >> name >> id_no >> type >> point;
		while (!file.eof())
		{
			if (id_no != id_no)
			{
				file << " " << name << " " << id_no << " " << type << " " << point << "\n";
			}
			else
			{
				cout << "Enter Member Name: ";
				cin >> name;
				cout << "Enter Member ID: ";
				cin >> id_no;
				cout << "Enter Member's Type(Ordinary/ Sailver/ Gold): ";
				cin >> type;
				cout << "Enter Member Credit Point: ";
				cin >> point;
				file1 << " " << name << " " << id_no << " " << type << " " << point << "\n";
				found++;
			}
			file >> name >> id_no >> type >> point;
			if (found == 0)
			{
				cout << " Member ID NOt Found!!! Try Again....";
			}
		}
		file.close();
		file1.close();
		remove("MemberDetail.txt");
		rename("Detail.txt", "MemberDetail.txt");
	}
}
int main()
{
	member project;
	project.addMember();
	return 0;
}
