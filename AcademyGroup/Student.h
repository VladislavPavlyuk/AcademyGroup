#pragma once
#include <iomanip>
#include "Person.h"

class Student : public Person
{
	char phone[14];
	double rating;
public:
	Student()													//  Конструктор по умолчанию
	{
		memset(phone, 0, 15);
		rating = 0.0;
	}

	Student(const char* name, const char* surname, int age, const char* phone, double rating); //  Конструктор с параметрами

	Student(const Student& obj);                        //  Конструктор копирования

	Student(Student&& obj);								//  Конструктор переноса

	double getRating() const
	{
		return rating;
	}
	const char* getPhone() const
	{
		return phone;
	}
	void setPhone(const char* phone);
	void setRating(double average);
	void Print() const;
	Student& operator=(const Student& obj);
	Student& operator=(Student&& obj);
	friend std::istream& operator>>(std::istream& is, Student& obj);
	friend std::ostream& operator<<(std::ostream& os, const Student& obj);
};




