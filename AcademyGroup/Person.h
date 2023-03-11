
#pragma once
#include <iostream>
using namespace std;

class Person
{
protected:
	char* name;
	char* surname;
	int age;
public:
	Person()														//  Конструктор по умолчанию
	{
		name = nullptr;
		surname = nullptr;
		age = 0;
	}
	Person(const char* name, const char* surname, int age);			//  Конструктор, позволяющий  проинициализировать вектор

	Person(const Person& obj);										//  Конструктор копирования

	Person(Person&& obj);											//  Конструктор переноса

	~Person();														//  Деструктор

	const char* getName()const
	{
		return name;
	}
	const char* getSurname()const
	{
		return surname;
	}
	int getAge() const
	{
		return age;
	}
	void setName(const char* name);
	void setSurname(const char* surname);
	void setAge(int age);
	void Print()const;
	Person& operator=(const Person& obj);
	Person& operator=(Person&& obj);
	friend std::istream& operator>>(std::istream& is, Person& obj);
	friend std::ostream& operator<<(std::ostream& os, const Person& obj);

};





