#pragma once
#include<iostream>
#include<string>
#include <fstream>
#include<iomanip>

using namespace std;

class Student
{
	string IDstudent;
	string name;
	string birthday;
	string gender;
	string classStudent;
	float scoreMath, scorePhys, scoreTech;
	float scoreAverage;
	int scholarship;

	Student *next;

public:
	Student();
	~Student();
	friend istream& operator >> (istream& in, Student &a);
	friend ostream& operator << (ostream& out, Student &a);
	friend class List;
};

