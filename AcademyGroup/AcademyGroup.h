#pragma once
#include <iostream>
#include "Student.h"

class AcademyGroup
{
	Student** pSt;
	int count;
public:
	AcademyGroup()
	{
		pSt = nullptr;
		count = 0;
	}
	AcademyGroup(const AcademyGroup& obj);				// конструктор копирования

	AcademyGroup(AcademyGroup&& obj);					//конструктор переноса

	~AcademyGroup();

	void AddStudents();
	void DeleteStudent();
	void EditStudent();
	void Print();
	void FindStudent();
	void Sort();
	void Save();
	void Load();
	AcademyGroup& operator=(const AcademyGroup& obj);
	AcademyGroup& operator=(AcademyGroup&& obj);
	Student& operator[](int index);

	friend std::ostream& operator<<(std::ostream& os, AcademyGroup& obj);
};



