#include "Person.h"

Person::Person(const char* name, const char* surname, int age)			//  Конструктор с параметрами
{
	this->name = new char[strlen(name) + 1];
	this->surname = new char[strlen(surname) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	strcpy_s(this->surname, strlen(surname) + 1, surname);
	this->age = age;
}
Person::Person(const Person& obj)										//  Конструктор копирования
{
	this->name = new char[strlen(obj.name) + 1];
	strcpy_s(this->name, strlen(obj.name) + 1, obj.name);
	this->surname = new char[strlen(obj.surname) + 1];
	strcpy_s(this->surname, strlen(obj.surname) + 1, obj.surname);
	this->age = obj.age;
}
Person::Person(Person&& obj)											//  Конструктор переноса
{
	this->name = obj.name;
	this->surname = obj.surname;
	this->age = obj.age;
	obj.name = nullptr;
	obj.surname = nullptr;
}

Person::~Person()														//  Деструктор
{
	if ((this->surname != nullptr) || (this->name != nullptr))
	{
		delete[] this->name;
		delete[] this->surname;
	}
}
void Person::setName(const char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}
void Person::setSurname(const char* surname)
{
	delete[] this->surname;
	this->surname = new char[strlen(surname) + 1];
	strcpy_s(this->surname, strlen(surname) + 1, surname);
}
void Person::setAge(int age)
{
	this->age = age;
}
void Person::Print()const
{
	cout << "\nName : \t\t" << name;
	cout << "\nSurname : \t" << surname;
	cout << "\nAge : \t" << age;
	cout << endl;
}

Person& Person::operator=(const Person& obj)
{
	if (this == &obj)
		return *this;
	delete[] this->name;
	delete[] this->surname;
	this->name = new char[strlen(obj.name) + 1];
	this->surname = new char[strlen(obj.surname) + 1];
	strcpy_s(this->name, (strlen(obj.name) + 1), obj.name);
	strcpy_s(this->surname, (strlen(obj.surname) + 1), obj.surname);
	this->age = obj.age;
	return *this;
}

Person& Person::operator=(Person&& obj)
{
	if (this == &obj)
		return *this;
	delete[]this->name;
	delete[]this->surname;
	this->name = obj.name;
	this->surname = obj.surname;
	this->age = obj.age;
	obj.name = nullptr;
	obj.surname = nullptr;
}

std::istream& operator>>(std::istream& is, Person& obj)
{
	char _name[20];
	char _surname[20];
	if (obj.name != nullptr)
	{
		delete[]obj.name;
		delete[]obj.surname;
	}
	cout << "Enter name ...\n";
	cin.getline(_name, 20);
	cout << "Enter surname ...\n";
	cin.getline(_surname, 20);
	cout << "Enter age ...\n";
	cin >> obj.age;
	obj.name = new char[strlen(_name) + 1];
	obj.surname = new char[strlen(_surname) + 1];
	strcpy_s(obj.name, strlen(_name) + 1, _name);
	strcpy_s(obj.surname, strlen(_surname) + 1, _surname);
	return is;
}

std::ostream& operator<<(std::ostream& os, const Person& obj)
{
	for (int i = 0; i < strlen(obj.name) + 1; i++)
	{
		cout << obj.name[i];
	}
	cout << "\t";
	for (int i = 0; i < strlen(obj.surname) + 1; i++)
	{
		cout << obj.surname[i];
	}
	cout << "\n";
	cout << obj.age;
	cout << "\n";
	return os;
}

