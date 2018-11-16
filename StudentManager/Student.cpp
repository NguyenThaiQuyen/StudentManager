#include "Student.h"

// function constructor
Student::Student()
{
	IDstudent = "";
	name = "";
	birthday = "";
	gender = "";
	classStudent = "";
	scoreMath = 0.0;
	scorePhys = 0.0;
	scoreTech = 0.0;
	scoreAverage = 0.0;
	scholarship = 0;
	next = NULL;
}

// function destructor
Student::~Student()
{

}

// operator >> with Student
istream& operator >> (istream& in, Student &a)
{
	in.ignore(1); 
	// check ID 9 number
	int i;
	do
	{
		cout << "Enter ID of student (9 number): ";
		getline(in, a.IDstudent);
		if (a.IDstudent.length() == 9)
		{
			for (i = 0; i < 9; i++)
			{
				if (a.IDstudent[i] < '0' || a.IDstudent[i] > '9') break;
			}
			if (i == 9) break;
		}
	} while (a.IDstudent.length() != 9 || i != 9);

	cout << "Enter name student: ";
	getline(in, a.name);
	cout << "Enter birthday student: ";
	getline(in, a.birthday);
	cout << "Enter gender student: ";
	getline(in, a.gender);

	// check class 4 character ex: 13T1
	do
	{
		cout << "Enter class of student (Ex: 13T1) : ";
		getline(in, a.classStudent);
		if (a.classStudent.length() == 4 && a.classStudent[2] == toupper('t'))
		{
			if (a.classStudent[0] >= '0' && a.classStudent[0] <= '9')
			{
				if (a.classStudent[1] >= '0' && a.classStudent[1] <= '9')
				{
					if (a.classStudent[3] >= '0' && a.classStudent[3] <= '9')
					{
						break;
					}
				}
			}
		}

	} while (a.classStudent.length() != 4 );

	cout << "Enter score Math: "; cin >> a.scoreMath;
	cout << "Enter core Physical: "; cin >> a.scorePhys;
	cout << "Enter score Technology: "; cin >> a.scoreTech;

	a.scoreAverage = (a.scoreMath + a.scorePhys + a.scoreTech) / 3;
	if (a.scoreAverage >= 8.0)
	{
		a.scholarship = 200;
	}
	else if (a.scoreAverage > 7.0)
	{
		a.scholarship = 100;
	}
	else
	{
		a.scholarship = 0;
	}
	return in;
}

// operator << with Student
ostream& operator << (ostream& out, Student &a)
{
	out << left << setw(13) << a.IDstudent << left << setw(20) << a.name;
	out << left << setw(13) << a.birthday << left << setw(8) << a.gender << left << setw(8) << a.classStudent;
	out << left << fixed << setiosflags(ios::showpoint) << setprecision(1) << setw(6) << a.scoreMath << left << setw(10) << a.scorePhys << left << setw(12) << a.scoreTech;
	out << left << setw(10) << a.scoreAverage << left << setw(14) << a.scholarship << endl;
	return out;
}

