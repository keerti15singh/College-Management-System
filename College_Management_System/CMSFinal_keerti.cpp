#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <limits.h>
#define FLBSTUD "student.txt"
#define FLBGRAD "grade.txt"
using namespace std;
class Dir_info
{
public:
	string director_name;
	int yoj;

public:
	Dir_info();
	Dir_info(string, int);
	void display_info();
	void edit_info();
};
Dir_info::Dir_info()
{
	director_name = "noName";
	yoj = 1990;
}
Dir_info::Dir_info(string name, int yoj)
{
	director_name = name;
	this->yoj = yoj;
}

void Dir_info::display_info()
{
	cout << "\n\n Director's Name:      " << director_name << "  " << endl;
	cout << "\n\n Year of Joining: " << yoj << "  " << endl;
}
void Dir_info::edit_info()
{
	int c;
	cout << "\n\n\n What do you want to edit? " << endl;
	cout << "    1) Name            " << endl;
	cout << "    2) Year of Joining " << endl;
	cout << "    Enter your choice  " << endl;
	cin >> c;
	switch (c)
	{
	case 1:
		break;
	case 2:
		break;
	default:
		cout << "\n\n\n INVALID INPUT  " << endl;
		break;
	}
}
class Department_info : public Dir_info
{
public:
	// char dept_name[20];
	// char hod[50];
	string dept_name;
	string hod;
	Department_info()
	{
		dept_name = "no-name";
		hod = "No-dept";
		yoj = 2000;
	}
	Department_info(string a, string b, int n)
	{
		dept_name = a;
		hod = b;
		yoj = n;
	}

public:
	void display_info();
	void edit_info();
	void delete_info();
};
void Department_info::display_info()
{
	cout << "\n\n HOD's Name:      " << hod << "  " << endl;
	cout << "\n\n Year of Joining: " << yoj << "  " << endl;
}
void Department_info::edit_info()
{
	char nname[20];
	int nyoj;
	int a;
	;
	char c;
	cout << "\n\n\n What do you want to edit? " << endl;
	cout << "    A) Name            " << endl;
	cout << "    B) Year of Joining " << endl;
	cout << "    Enter your choice  " << endl;
	cin >> c;
	cout << "test";
	cin >> a;
	switch (c)
	{
	case 'A':
		cout << "    Enter the new HOD's name." << endl;
		cin >> nname;
		// dept_name = nname;
		cout << "    The record has been edited." << endl;
		break;
	case 'B':
		cout << "    Enter the HOD's correct year of joining ." << endl;
		cin >> nyoj;
		yoj = nyoj;
		cout << "    The record has been edited." << endl;
		break;
	default:
		cout << "\n\n\n INVALID INPUT  " << endl;
	}
}
void Department_info::delete_info()
{
	/*char dc[5];
	cout<<"    Are you sure you want to delete this branch from the record?   "<<endl;
	cout<<"    Enter 1 for  YES  and 2 for NO   "<<endl;
	cin>>dc;
	if(dc==1)
	{
	 for(int i=0;i<)
	}*/
}
fstream fil;
class Student
{
	char studentName[30];
	int rollNo;
	int classop1;
	int year;
	char fatherName[30];
	char motherName[30];
	char address[80];
	char bloodGroup[4];

public:
	void getDetails();
	void printDetails()
	{
		cout << "Roll No.      : " << rollNo << endl;
		cout << "Father's Name : " << fatherName << endl;
		cout << "Mother's Name : " << motherName << endl;
		cout << "Address       : " << address << endl;
		cout << "Blood Group   : " << bloodGroup << endl;
	}
	int retRollNo()
	{
		return rollNo;
	}
	char *retString(char x)
	{
		if (x == 'N')
			return studentName;
		if (x == 'F')
			return fatherName;
		if (x == 'M')
			return motherName;
		if (x == 'A')
			return address;
		if (x == 'B')
			return bloodGroup;
	}
	char *retStudentName()
	{
		return retString('N');
	}
};
void insertStudent()
{
	Student obj, obj2;
	char ch;
	int v = 0;
	cout << "Enter Details for new Student\n";
	obj.getDetails();
	fstream fl1(FLBSTUD, ios::in | ios::binary);
	ofstream fl2;
	if (!fl1)
	{
		fl2.open(FLBSTUD, ios::out | ios::binary);
		fl2.write((char *)&obj, sizeof(obj));
		fl2.close();
		cout << "Record successfully inserted !\n";
		return;
	}
	while (!fl1.eof())
	{
		fl1.read((char *)&obj2, sizeof(obj));
		if (fl1.eof())
		{
			break;
		}
		if (obj.retRollNo() == obj2.retRollNo())
		{
			cout << "Record with same Roll No. with following details already exists : \n";
			obj2.printDetails();
			cout << "Insertion Aborted !\n";
			return;
		}
		else if (strcmpi(obj.retStudentName(), obj2.retStudentName()) == 0)
		{
			if (!v)
				cout << "Warning : Record with same name exists with follwing details : \n";
			obj2.printDetails();
			cout << '\n';
			v = 1;
		}
	}
	if (v)
	{
		cout << "Do you still wish to insert record (Y/N) ? ";
		do
		{
			cin >> ch;
			ch = toupper(ch);
		} while (ch != 'Y' && ch != 'N');
		if (ch == 'N')
		{
			cout << "Insertion Aborted !\n";
			return;
		}
	}
	fl2.open(FLBSTUD, ios::out | ios::app | ios::binary);
	fl2.seekp(0, ios::end);
	fl2.write((char *)&obj, sizeof(obj));
	fl2.close();
	cout << "Record Inserted successfully !\n";
}
void delStudentRecord()
{
	Student obj;
	int f = 0;
	cout << "\nEnter Roll No. to delete : ";
	int r;
	char ch;
	cin >> r;
	fstream fl(FLBSTUD, ios::in | ios::binary);
	fstream fo("temp.dat", ios::out | ios::binary);
	while (!fl.eof())
	{
		fl.read((char *)&obj, sizeof(obj));
		if (fl.eof())
			break;
		if (r == obj.retRollNo())
		{
			cout << "Record with following info will be deleted :\n\n";
			obj.printDetails();
			cout << "Do you wish to continue ? (Y/N) : ";
			do
			{
				cin >> ch;
				ch = toupper(ch);
			} while (ch != 'N' && ch != 'Y');
			if (ch == 'N')
			{
				cout << "Deletion Aborted !\n";
				fl.close();
				fo.close();
				remove("temp.dat");
				return;
			}
			f = 1;
			continue;
		}
		fo.write((char *)&obj, sizeof(obj));
	}
	fl.close();
	fo.close();
	remove(FLBSTUD);
	rename("temp.dat", FLBSTUD);
	if (f)
		cout << "Record Successfully Deleted !\n";
	else
		cout << "No Such Record Exists !\n";
}
void Student::getDetails()
{
	cout << "Enter Student's Name        : ";
	do
	{
		gets(studentName);
	} while (strlen(studentName) == 0);
	cout << "Enter Roll No.            : ";
	do
	{
		cin >> rollNo;
	} while (rollNo < 1);
	cout << "Enter Father's Name         : ";
	do
	{
		gets(fatherName);
	} while (strlen(fatherName) == 0);
	cout << "Enter Mother's Name         : ";
	do
	{
		gets(motherName);
	} while (strlen(motherName) == 0);
	cout << "Enter Address             : ";
	do
	{
		gets(address);
	} while (strlen(address) == 0);
	cout << "Enter Blood Group [eg. B+]: ";
	do
	{
		gets(bloodGroup);
	} while (strlen(bloodGroup) == 0);
	cout << "Enter Year       :";
	cin >> year;
}
class Library
{
public:
	char book[100], author[100], publication[100], id[20];
	float price;
	int quantity;
	void getData();
	void showData();
	int booksCategory(int);
	void searchBook(int);
	void issueBook();
	void returnBook();
};
void Library::getData()
{
	cin.ignore();
	cout << "\t\t\t\t\t********** ENTER BOOK DETAILS **********";
	cout << "\n\n\n\t\t\tEnter Book's Name: ";
	cin.getline(book, 100);
	cout << "\n\t\t\tEnter Author's Name: ";
	cin.getline(author, 100);
	cout << "\n\t\t\tEnter Publication Name: ";
	cin.getline(publication, 100);
	cout << "\n\t\t\tEnter Book's ID: ";
	cin >> id;
	cout << "\n\t\t\tEnter Book's Price: ";
	cin >> price;
	cout << "\n\t\t\tEnter Book's Quantity: ";
	cin >> quantity;
}
int Library::booksCategory(int flag)
{
	cout << "\t\t\t\t\t********** CATEGORY OF BOOKS **********\n\n";
	cout << "\t\t\t\t\t>> Select a Category\n\n";
	cout << "\t\t\t\t\t1. School of Computer Engineering\n\n";
	cout << "\t\t\t\t\tEnter choice: ";
	int choice;
	cin >> choice;
	cout << endl
		 << endl;
	switch (choice)
	{
	case 1:
		return 1;
		break;
	default:
		cout << "\t\t\t\t\tInvalid choice.\n\n";
		cout << "\t\t\t\t\tPress any key to be able to enter a valid choice\n\n";
		cin.get();
		booksCategory(flag);
	}
}
void Library::showData()
{
	cout << "\n\t\tName of the book: " << book;
	cout << "\n\n\t\tAuthor's name: " << author;
	cout << "\n\n\t\tPublication's name: " << publication;
	cout << "\n\n\t\tBook's ID: " << id;
	cout << "\n\n\t\tPrice of the book: " << price;
	cout << "\n\n\t\tNumber of books available: " << quantity << endl
		 << endl;
}
void Library::searchBook(int flag)
{
	int sCategory = booksCategory(2);
	int choice;
	char bookName[100], bookID[20];
	int var = 1;
	cout << "\t\t\t\t\t********** SEARCH BOOK **********\n\n";
	cout << "\t\t\t\t\t>> Choose any option\n\n";
	cout << "\t\t\t\t\t1. Search by name\n\n"
		 << "\t\t\t\t\t2. Search by ID\n\n"
		 << "\t\t\t\t\t3. Go Back\n\n";
	cout << "\t\t\t\t\tEnter choice: ";
	cin >> choice;
	cout << endl
		 << endl;
	switch (choice)
	{
	case 1:
		if (sCategory == 1)
		{
			fstream fin("csBooks.txt", ios::in);
			if (!fin)
				cout << "\n\t\tFile Not Found.";
			else
			{
				cout << "\n\t\tEnter Book's Name: ";
				cin.ignore();
				cin.getline(bookName, 100);
				fin.getline(book, 100);
				fin.getline(author, 100);
				fin.getline(publication, 100);
				fin >> id >> price >> quantity;
				while (1)
				{
					if (strcmp(bookName, book) == 0)
					{
						cout << "\n\n\t\t##### SEARCH RESULTS #####\n";
						showData();
						var++;
					}
					if (fin.eof())
						break;
					fin.getline(book, 100);
					fin.getline(author, 100);
					fin.getline(publication, 100);
					fin >> id >> price >> quantity;
				}
				fin.close();
			}
			if (var == 1)
				cout << "\n\n\t\t\tBOOK NOT FOUND";
			cout << "\n\n\n\t\tPress any key to continue";
			cin.get();
		}
	case 2:
		if (sCategory == 1)
		{
			ifstream fin("csBooks.txt", ios::in);
			if (!fin)
				cout << "\n\t\tFile Not Found.";
			else
			{
				cout << "\n\t\tEnter Book's ID: ";
				cin.ignore();
				cin >> bookID;
				fin.getline(book, 100);
				fin.getline(author, 100);
				fin.getline(publication, 100);
				fin >> id >> price >> quantity;
				while (1)
				{
					if (strcmp(bookID, id) == 0)
					{
						cout << "\n\n\t\t##### SEARCH RESULTS #####\n";
						showData();
						var++;
					}
					if (fin.eof())
						break;
					fin.getline(book, 100);
					fin.getline(author, 100);
					fin.getline(publication, 100);
					fin >> id >> price >> quantity;
				}
				fin.close();
			}
			if (var == 1)
				cout << "\n\n\t\t\tBOOK NOT FOUND";
			cout << "\n\n\n\t\tPress any key to continue";
			cin.get();
		}
	default:
		cout << "\n\t\t\t\t\tInvalid choice.\n\n";
		cout << "\n\n\t\t\t\t\tPress any key to be able to enter a valid choice\n\n";
		cin.get();
		searchBook(flag);
	}
}
int main()
{
	ifstream file1;
	ofstream file2;
	int choic1;
	Dir_info director;
	director = Dir_info("Rajeev Kumar", 1990);
	cout << "----------------------------COLLEGE MANAGEMENT SYSTEM-----------------------" << endl;
	cout << "\n\n\n";

	cout << "--------------------------------Director Centre------------------------------" << endl;
	cout << "\n\n  What operation do you want to be performed?    " << endl;
	cout << "\n1) DISPLAY INFO " << endl;
	cout << "2) EDIT INFO    " << endl;
	cout << "3) EXIT         " << endl;
	cout << "  \n\n\n Enter your choice.      " << endl;
	cin >> choic1;
	switch (choic1)
	{
	case 1:
		director.display_info();
		break;
	case 2:
		director.edit_info();
		break;
	case 3:
		cout << "\n\n\n EXIT  " << endl;
	default:
		cout << "\n\n\n INVALID INPUT   " << endl;
		break;
	}
	int choic2, pos = 0;
	Department_info dept[11], d;
	char dname[10];
	dept[0] = Department_info("CSE", "Rajeev Kumar", 1990);
	dept[1] = Department_info("IT", "Riya Malhotra", 1991);
	dept[2] = Department_info("IPE", "Ram Singh", 1992);
	dept[3] = Department_info("ICE", "Jatin Garg", 1993);
	dept[4] = Department_info("ECE", "Harshita Kataria", 1994);
	dept[5] = Department_info("EE", "Keerti Singh", 1995);
	dept[6] = Department_info("Mechanical", "Surnedra Kumar", 1996);
	dept[7] = Department_info("Chemical", "Lovepreet Kaur", 1997);
	dept[8] = Department_info("Civil", "Rajeev Kumar", 1998);
	dept[9] = Department_info("Bio-Tech", "Darshan Raval", 1999);
	dept[10] = Department_info("Textile", "Gursharan Kaur", 1992);

	cout << "--------------------------------Department'HOD Centre------------------------------" << endl;
	cout << "\n\n  What operation do you want to be performed?    " << endl;
	cout << "\n1) DISPLAY INFO " << endl;
	cout << "2) EDIT INFO    " << endl;
	cout << "3) DELETE INFO  " << endl;
	cout << "4) EXIT         " << endl;
	cout << "  \n\n\n Enter your choice.      " << endl;
	cin >> choic2;
	switch (choic2)
	{
	case 1:
		cout << "\n\n\n Enter your department's name " << endl;
		cin >> dname; // department's name;
		for (int i = 0; i < 11; i++)
		{
			if (dept[i].dept_name == dname)
				pos = i;
		}
		dept[pos].display_info();
		break;
	case 2:
		cout << "\n\n\n Enter your department's name " << endl;
		cin >> dname; // department's name;
		for (int i = 0; i < 11; i++)
		{
			if (dept[i].dept_name == dname)
				pos = i;
		}
		dept[pos].edit_info();
		break;
	case 3:
		cout << "\n\n\n Enter department's name to be deleted " << endl;
		cin >> dname; // department's name;
		for (int i = 0; i < 11; i++)
		{
			if (dept[i].dept_name == dname)
				pos = i;
		}
		dept[pos].delete_info();
		break;
	case 4:
		cout << "\n\n\n EXIT  " << endl;
		break;
	default:
		cout << "\n\n\n INVALID INPUT   " << endl;
	}
	int choice1, choice2, choice3;
	cout << "\t\t\t STUDENT'S CORNER \n";
	cout << "\t1. STUDENT INFORMATION SECTION\n";
	cout << "\t2. LIBRARY MANAGEMENT SYSTEM\n";
	cout << "\t3. Exit\n\n";
	cout << "Enter your choice\n";
	fflush(stdin);
	cin >> choice1;
	switch (choice1)
	{
	case 1:
	{
		int ch2;
	studentMenu:
		cout << "\t\t\tSTUDENT INFORMATION SECTION\n";
		cout << "\t1. Admission Details.\n";
		cout << "\t2. Exit.\n\n";
		cout << "Enter your choice\n";
		cin >> choice2;
		if (choice2 == 1)
		{
			fflush(stdin);
			do
			{
				cout << "\t\t\tSTUDENT INFORMATION SECTION\n";
				cout << "\t\t\t     ADMISSION DETAILS\n";
				cout << "\t1.  Register Student.\n";
				cout << "\t2.  Delete a Record.\n";
				cout << "\t3.  Exit.\n";
				cout << "\nEnter your choice\n";
				cin >> ch2;
				switch (ch2)
				{
				case 1:
					insertStudent();
					break;
				case 2:
					delStudentRecord();
					break;
				}
				fflush(stdin);
			} while (ch2 != 3);
		}
	}
	case 2:
	{
		int ch3;
		do
		{
			cout << "\t\t\tLIBRARY DETAILS\n";
			cout << "\t1.Search Book.\t\n";
			cout << "\t2. Exit.\n\n";
			cout << "\nEnter your choice\n";
			cin >> ch3;
			switch (ch3)
			{
			case 1:
				Library obj;
				obj.searchBook(1);
				break;
			}
			fflush(stdin);
		} while (ch3 != 4);
	}
	}
	return 0;
}