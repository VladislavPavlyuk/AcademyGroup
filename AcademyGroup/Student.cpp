#include "Student.h"

using namespace std;

Student::Student(const char* name, const char* surname, int age, const char* phone, double rating) : Person(name, surname, age)  //  Конструктор с параметрами
{
	/*strcpy_s(this->name, strlen(getName()) + 1, getName());
	strcpy_s(this->surname, strlen(getSurname()) + 1, getSurname());
	this->age = getAge();*/

	strcpy_s(this->phone, 14, phone);
	this->rating = rating;
}

Student::Student(const Student& obj) : Person(obj)                                 //  Конструктор копирования
{
	strcpy_s(this->phone, 14, obj.phone);
	this->rating = obj.rating;
}

Student::Student(Student&& obj) : Person((Person&&)obj)								//  Конструктор переноса
{
	strcpy_s(this->phone, 14, obj.phone);
	this->rating = obj.rating;
}

void Student::setPhone(const char* phone)
{
	strcpy_s(this->phone, 14, phone);
}
void Student::setRating(double average)
{
	this->rating = average;
}
void Student::Print() const
{
	cout << "\nName : \t\t" << name;
	cout << "\nSurname : \t" << surname;
	cout << "\nAge : \t\t" << age;
	cout << "\nPhone : \t" << phone;
	cout << "\nRating : \t" << rating;
	cout << endl;
}

Student& Student::operator=(const Student& obj)
{
	if (this == &obj)
		return *this;
	Person::operator=(obj);
	strcpy_s(this->phone, 14, phone);
	this->rating = obj.rating;
	return *this;
}

Student& Student::operator=(Student&& obj)
{
	if (this == &obj)
		return *this;
	Person::operator=((Person&&)obj);
	strcpy_s(this->phone, 14, phone);
	this->rating = obj.rating;
	//obj.name = nullptr;
	//obj.surname = nullptr;
}

std::istream& operator>>(std::istream& is, Student& obj)
{
	char _name[20];
	char _surname[20];
	char _phone[14];
	operator>>(is, (Person&)obj);

		/*cin.get();
		cout << "Enter name ...\n";
		cin.getline(_name, 20);
		cout << "Enter surname ...\n";
		cin.getline(_surname, 20);
		cout << "Enter phone ...\n";
		cin.getline(_phone, 14);
		cout << "Enter age ...\n";
		cin >> obj.age;*/

	cout << "Enter rating ...\n";
	cin >> obj.rating;

		/*obj.name = new char[strlen(_name) + 1];
		obj.surname = new char[strlen(_surname) + 1];
		strcpy_s(obj.name, (strlen(_name) + 1), _name);
		strcpy_s(obj.surname, (strlen(_surname) + 1), _surname);*/

	strcpy_s(obj.phone, 14, _phone);
	return is;
}

std::ostream& operator<<(std::ostream& os, const Student& obj)
{
	operator<<(os, (Person&)obj);
	int _age = 0;
	if (obj.age <= 9)
		_age = 1;
	else if (obj.age > 9)
		_age = 2;
	else
		_age = 3;

	cout << obj.name << setw(22 - strlen(obj.name))
		<< obj.surname << setw(22 - strlen(obj.surname))
		<< obj.age << setw(22 - _age)
		<< obj.phone << setw(22 - strlen(obj.phone))
		<< obj.rating << setw(20) << endl;
	return os;
}
