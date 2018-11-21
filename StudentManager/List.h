#pragma once

#include"Student.h"

class List
{
	Student *F;
public:
	List();
	~List();
	void destructor();

	// display screen
	void Display();
	void DisplayOneStudent(Student &a, int k);
	
	// add  and insert object
	void AddTheFirst(Student *p);
	void AddSortID(Student *p);

	// search student
	void Search();
	Student* SearchID(string is_ID);
	void SearchName(string is_name);
	void SearchBirthday(string is_birthday);
	void SearchGender(string is_gender);
	void SearchClass(string is_classStudent);
	void SearchMath(double is_scoreMath);
	void SearchPhysical(double is_scorePhys);
	void SearchTechnology(double is_scoreTech);
	void SearchAverage(double is_scoreAverage);
	void SearchScho(int scho);
	
	// sort list
	void Sort();
	void SortByName(bool (*p)(string a, string b));
	int getIntRange(int  low, int high);
	friend bool Ascending(string nameLeft, string nameRight);
	friend bool Descending(string nameLeft, string nameRight);
	friend string GetFirstName(string name);
	void Swap(Student *a, Student *b);

	// delete student
	void DeleteByID(string is_ID);

	// detele studen female grade 08
	void DeleteByFemale08();

	// List class have scholarship
	void DisplayScholaship();

};

