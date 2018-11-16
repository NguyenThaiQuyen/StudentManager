#include "List.h"

// constructor and open, read file "Input.txt"
List::List()
{
	fstream f;
	f.open("Input.txt");
	if (f.fail())
	{
		cout << "Failed to open this file!" << endl;
	}
	while(!f.eof())
	{
		f.ignore();
	    Student *p = new Student;
	
		getline(f, p->IDstudent);
		getline(f, p->name);
		getline(f, p->birthday);
		getline(f, p->gender);
		getline(f, p->classStudent);
		f >> p->scoreMath;
		f >> p->scorePhys;
		f >> p->scoreTech;
		p->scoreAverage = (p->scoreMath + p->scorePhys + p->scoreTech) / 3;
		if (p->scoreAverage >= 8.0)
		{
			p->scholarship = 200;
		}if (p->scoreAverage > 7.0)
		{
			p->scholarship = 100;
		}
		else
		{
			p->scholarship = 0;
		}
		AddSortID(p);
	}
}

// function destuctor
void List::destructor()
{
	Student *p;
	p = F;
	while (p != NULL)
	{
		Student *tmp = p;  // bien tmp luu nut can xoa
		p = p->next;       // chuyen toi nut ke tiep
		delete tmp;        // xoa
	}
	F = NULL; // khoi tao lai NULL cho bien F;
}
List::~List()
{
	destructor();
}

// display screen
void List::Display()
{
	{
		cout << left << setw(5) << "STT " << left << setw(13) << "ID " << left << setw(20) << "NAME ";
		cout << left << setw(13) << "BIRTHDAY " << left << setw(8) << "GENDER " << left << setw(8) << "CLASS ";
		cout << left << setw(6) << "MATH " << left << setw(10) << "PHYSICAL " << left << setw(12) << "TECHNOLOGY ";
		cout << left << setw(10) << "AVERAGE " << left << setw(14) << "SCHOLARSHIP " << endl;
		Student* p;
		p = F;
		int k = 0;
		while (p != NULL)
		{
			k++;
			DisplayOneStudent((*p), k);
			p = (*p).next;
		}
	}
}

void List::DisplayOneStudent(Student &a, int k)
{
	cout << left << setw(5) << k << left << setw(13) << a.IDstudent << left << setw(20) << a.name;
	cout << left << setw(13) << a.birthday << left << setw(8) << a.gender << left << setw(8) << a.classStudent;
	cout << left << fixed << setiosflags(ios::showpoint) << setprecision(1) << setw(6) << a.scoreMath << left << setw(10) << a.scorePhys << left << setw(12) << a.scoreTech;
	cout << left << setw(10) << a.scoreAverage << left << setw(14) << a.scholarship << endl;
}

// add  and insert object
void List::AddSortID(Student *p)
{
	Student* before = NULL;
	Student* after;
	after = F;
	while (after != NULL)
	{
		if (after->IDstudent == p->IDstudent)
		{
			cout << "\nID existed! ";
			return;
		}
		after = after->next;
	}
	after = F;
	while (after != NULL && (after->IDstudent < (p->IDstudent) ) )
	{
		before = after;
		after = after->next;
	}

	p->next = after;
	if (F == after)
	{
		F = p;
	}
	else
	{
		before->next = p;
	}
}

void List::AddTheFirst(Student *p)
{
	Student* after = NULL;
	while (after != NULL)
	{
		if (after->IDstudent == p->IDstudent)
		{
			cout << "\nID existed! ";
			return;
		}
		after = after->next;
	}
	p->next = F;
	F = p;
}


int List::getIntRange(int low, int high)
{
	int input;
	while (true)
	{
		cin >> input;
		if (input < low || input > high)
		{
			cout << "Value invalid!\n";
			cout << "\nEnter again: ";
		}
		else
		{
			break;
		}
	}
	return input;
}

// search student
void List::Search()
{
	int choice = 0;
	cout << "What information do you want to search by?" << endl;
	cout << "1.By ID." << endl;
	cout << "2.By Name." << endl;
	cout << "3.By Birthday." << endl;
	cout << "4.By Gender." << endl;
	cout << "5.By Class." << endl;
	cout << "6.By Math." << endl;
	cout << "7.By Physical." << endl;
	cout << "8.By Technology." << endl;
	cout << "9.By Average." << endl;
	cout << "10.By Scholarship." << endl;

	cout << "\nEnter your choice : ";
	choice = getIntRange(0, 10);

	switch (choice)
	{
	case 1:
	{
		Student* pResult = NULL;
		string is_ID;
		int i;
		do
		{
			cout << "Enter ID of student (9 number): ";
			getline(cin, is_ID);
			if (is_ID.length() == 9)
			{
				for (i = 0; i < 9; i++)
				{
					if (is_ID[i] < '0' || is_ID[i] > '9') break;
				}
				if (i == 9) break;
			}
		} while (is_ID.length() != 9 || i != 9);
		pResult = SearchID(is_ID);
		if (pResult != NULL)
		{
			DisplayOneStudent((*pResult), 1);
		}
		else
		{
			cout << endl << "Not found!";
		}

		break;
	}


	case 2:
	{
		string is_name;
		cout << "Enter name you want to seach: ";
		cin.ignore(1);
		getline(cin, is_name);
		SearchName(is_name);
		break;
	}
	case 3:
	{
		string is_birthday;
		cout << "Enter birthday you want to seach: ";
		cin.ignore(1);
		getline(cin, is_birthday);
		SearchBirthday(is_birthday);
		break;
	}
	case 4:
	{
		string is_gender;
		cout << "Enter gender you want to seach: ";
		cin.ignore(1);
		getline(cin, is_gender);
		SearchGender(is_gender);
		break;
	}
	case 5:
	{
		string is_classStudent;
		do
		{
			cout << "Enter class of student (Ex: 13T1) : ";
			getline(cin, is_classStudent);
			if (is_classStudent.length() == 4 && is_classStudent[2] == toupper('t'))
			{
				if (is_classStudent[0] >= '0' &&is_classStudent[0] <= '9')
				{
					if (is_classStudent[1] >= '0' && is_classStudent[1] <= '9')
					{
						if (is_classStudent[3] >= '0' && is_classStudent[3] <= '9')
						{
							break;
						}
					}
				}
			}

		} while (is_classStudent.length() != 4);
		SearchClass(is_classStudent);
		break;
	}
	case 6:
	{
		float is_scoreMath;
		cout << "Enter score Math you want to seach: ";
		cin >> is_scoreMath;
		SearchMath(is_scoreMath);
		break;
	}
	case 7:
	{
		float  is_scorePhys;
		cout << "Enter score Math you want to seach: ";
		cin >> is_scorePhys;
		SearchPhysical(is_scorePhys);
		break;
	}
	case 8:
	{
		float is_scoreTech;
		cout << "Enter score Math you want to seach: ";
		cin >> is_scoreTech;
		SearchTechnology(is_scoreTech);
		break;
	}
	case 9:
	{
		float is_Average;
		cout << "Enter score Average you want to seach: ";
		cin >> is_Average;
		SearchAverage(is_Average);
		break;
	}
	case 10:
	{
		cout << "What scholarship do you want to search ?" << endl;
		cout << "1.Scholarship 200." << endl;
		cout << "2.Scholarship 100." << endl;
		cout << "\nEnter your choice : ";
		choice = getIntRange(1, 2);

		switch (choice)
		{
		case 1:
		{
			SearchScho(200);
			break;
		}
		case 2:
		{
			SearchScho(100);
			break;
		}
		}
	}
	}
}


Student* List::SearchID(string is_ID)
{
	Student *p = NULL;
	p = F;
	while (p != NULL && p->IDstudent != is_ID)
	{
		p = p->next;
	}
	return p;
}

void List::SearchName(string is_name)
{
	string name = is_name.substr(is_name.find_last_of(' ') + 1);
	if (name[0] != ' ')
	{
		name[0] = toupper(is_name[0]);
		for (int i = 1; i < name.length(); i++)
		{
			name[i] = tolower(name[i]);
		}
	}

	Student *p = NULL;
	p = F;
	int k = 0;
	while (p != NULL)
	{
		string pName = p->name.substr(p->name.find_last_of(' ') + 1);
		if (pName == name || p->name == is_name)
		{
			k++;
			DisplayOneStudent((*p), k);
		}
		p = p->next;
	}
}


void List::SearchBirthday(string is_birthday)
{
	Student *p = NULL;
	p = F;
	int k = 0;
	while (p != NULL)
	{
		if (p->birthday == is_birthday)
		{
			k++;
			DisplayOneStudent((*p), k);
		}
		p = p->next;
	}
}

void List::SearchGender(string is_gender)
{
	Student *p = NULL;
	p = F;
	int k = 0;
	while (p != NULL)
	{
		if (p->gender == is_gender)
		{
			k++;
			DisplayOneStudent((*p), k);
		}
		p = p->next;
	}
}

void List::SearchClass(string is_classStudent)
{
	Student *p = NULL;
	p = F;
	int k = 0;
	while (p != NULL)
	{
		if (p->classStudent == is_classStudent)
		{
			k++;
			DisplayOneStudent((*p), k);
		}
		p = p->next;
	}
}

void List::SearchMath(float is_scoreMath)
{
	Student *p = NULL;
	p = F;
	int k = 0;
	while (p != NULL)
	{
		if (p->scoreMath == is_scoreMath)
		{
			k++;
			DisplayOneStudent((*p), k);
		}
		p = p->next;
	}
}

void List::SearchPhysical(float is_scorePhys)
{
	Student *p = NULL;
	p = F;
	int k = 0;
	while (p != NULL)
	{
		if (p->scorePhys == is_scorePhys)
		{
			k++;
			DisplayOneStudent((*p), k);
		}
		p = p->next;
	}
}

void List::SearchTechnology(float is_scoreTech)
{
	Student *p = NULL;
	p = F;
	int k = 0;
	while (p != NULL)
	{
		if (p->scoreTech == is_scoreTech)
		{
			k++;
			DisplayOneStudent((*p), k);
		}
		p = p->next;
	}
}

void List::SearchAverage(float is_Average)
{
	Student *p = NULL;
	p = F;
	int k = 0;
	while (p != NULL)
	{
		if (p->scoreAverage == is_Average)
		{
			k++;
			DisplayOneStudent((*p), k);
		}
		p = p->next;
	}
}

void List::SearchScho(int scho)
{
	Student *p = NULL;
	p = F;
	int k = 0;
	while (p != NULL)
	{
		if (p->scholarship == scho)
		{
			k++;
			DisplayOneStudent((*p), k);
		}
		p = p->next;
	}
}

// sort list

void List::Swap(Student* a, Student* b)
{
	
	string tmp_IDstudent = a->IDstudent;
	string tmp_name = a->name;
	string tmp_birthday = a->birthday;
	string tmp_gender = a->gender;
	string tmp_classStudent = a->classStudent;
	float tmp_scoreMath =a->scoreMath;
	float tmp_scorePhys = a->scorePhys;
	float tmp_scoreTech =a->scoreTech;
	float tmp_scoreAverage = a->scoreAverage;
	int tmp_scholarship = a->scholarship;

	a->IDstudent = b->IDstudent;
	a->name = b->name;
	a->birthday = b->birthday;
	a->gender = b->gender;
	a->classStudent = b->classStudent;
	a->scoreMath = b->scoreMath;
	a->scorePhys = b->scorePhys;
	a->scoreTech = b->scoreTech;
	a->scoreAverage = b->scoreAverage;
	a->scholarship = b->scholarship;

	b->IDstudent = tmp_IDstudent;
	b->name = tmp_name;
	b->birthday = tmp_birthday;
	b->gender = tmp_gender;
	b->classStudent = tmp_classStudent;
	b->scoreMath = tmp_scoreMath;
	b->scorePhys = tmp_scorePhys;
	b->scoreTech = tmp_scoreTech;
	b->scoreAverage = tmp_scoreAverage;
	b->scholarship = tmp_scholarship;
}
bool Ascending(string nameLeft, string nameRight)
{
	return nameLeft < nameRight;
}
bool Descending(string nameLeft, string nameRight)
{
	return nameLeft > nameRight;
}
string GetFirstName(string name)
{
	return name.substr(name.find_last_of(' ') + 1);
}

void List::SortByName(bool (*p)(string a, string b))
{
	Student *head, *after;
	for (head = F; head != NULL; head = head->next)
	{
		for (after = head->next; after != NULL; after = after->next)
		{
			if( p(GetFirstName(head->name), GetFirstName(after->name)) )
			Swap(head, after);
		}
	}
}

void List::Sort()
{
	cout << "\nWhat sort by name ? " << endl;
	cout << "\n1.Ascending." << endl;
	cout << "\n2.Descending." << endl;
	cout << "\nEnter your choice: ";
	int choice = getIntRange(1, 2);

	switch (choice)
	{
	case 1:
		SortByName(Ascending);
		break;
	case 2:
		SortByName(Descending);
		break;
	}
}

// delete student
void List::DeleteByID(string is_ID)
{
	Student* t;
	Student* before = NULL;
	Student* after;
	t = SearchID(is_ID);
	after = F;
	while (after != t)
	{
		before = after;
		after = after->next;
	}
	if (F == t) F = t->next;
	else before->next = t->next;
	delete t;
}

// detele studen female grade 08
void List::DeleteByFemale08()
{
	Student* p = NULL;
	p = F;
	while (p != NULL)
	{
		if ( (p->classStudent).substr(0, 2) == "08" && (p->gender == "nu"))
		{
			Student *t;
			t = p;
			p = t->next;
			DeleteByID(t->IDstudent);
		}
		else
		{
			p = p->next;
		}		
	}
}

// List class have scholarship
void List::DisplayScholaship()
{

}
