#include <iostream>
#include <conio.h>
#include "AcademyGroup.h"

using namespace std;

AcademyGroup::AcademyGroup(const AcademyGroup& obj)				// конструктор копирования
{
	count = obj.count;
	pSt = new Student * [count];
	for (int i = 0; i < count; i++)
	{
		pSt[i] = new Student(*obj.pSt[i]);
	}
}

AcademyGroup::AcademyGroup(AcademyGroup&& obj)					//конструктор переноса
{
	count = obj.count;
	pSt = obj.pSt;
	obj.pSt = nullptr;
	obj.count = 0;
}

AcademyGroup::~AcademyGroup()
{
	for (int i = 0; i < count; i++)
	{
		delete pSt[i];
	}
	delete[]pSt;
}

void AcademyGroup::AddStudents()						//добавление студентов в группу;
{
	system("cls");
	cout << "Enter a quantity of students to add: ";
	int n;
	cin >> n;
	if (n <= 0)
		return;
	count = n + count;
	Student** temp = new Student * [count];
	for (int i = 0; i < count - n; i++)
	{
		temp[i] = pSt[i];
	}
	delete[]pSt;
	pSt = temp;
	for (int i = count - n; i < count; i++)
	{
		Student* s = new Student;
		cout << "Enter a new student data #";
		cout << i + 1;
		char* name = new char[15];
		char* surname = new char[15];
		int age;
		double rating;
		char phone[14];
		cout << "\nEnter name : ";
		cin >> name;
		cout << "\nEnter surname : ";
		cin >> surname;
		cout << "\nEnter age : ";
		cin >> age;
		cout << "\nEnter phone : ";
		cin >> phone;
		cout << "\nEnter rating : ";
		cin >> rating;
		s->setName(name);
		s->setSurname(surname);
		s->setAge(age);
		s->setPhone(phone);
		s->setRating(rating);
		system("cls");
		pSt[i] = s;
	}
}

void AcademyGroup::DeleteStudent()
{
	char surname[20];
	cout << "\nPlease enter surname of the student : ";
	cin >> surname;
	for (int i = 0; i < count; i++)
	{
		delete pSt[i];
		for (int j = 0; j < count - 1; j++)
			pSt[j] = pSt[j + 1];
		pSt[--count] = nullptr;
		//_getch();
		return;
	}
	cout << "Student not found...";
	_getch();
}

void AcademyGroup::EditStudent()
{
	char name[20];
	char surname[20];
	bool res = false;

	cout << "\nEnter name of the student : ";
	cin >> name;
	cout << "\nEnter surname of the student : ";
	cin >> surname;
	system("cls");
	for (int i = 0; i < count; i++)
	{
		if (!strcmp(name, pSt[i]->getName()) && !strcmp(surname, pSt[i]->getSurname()))
		{
			cout << setw(15) << pSt[i]->getName();
			cout << setw(15) << pSt[i]->getSurname();
			cout << setw(10) << pSt[i]->getAge();
			cout << setw(20) << pSt[i]->getRating();
			cout << setw(15) << pSt[i]->getPhone();
			cout << endl;

			cout << "\nPlease enter a new student data : ";
			char new_name [15];
			char new_surname [15];
			int new_age;
			double new_rating;
			char new_phone[14];
			cout << "\nEnter name : ";
			cin >> new_name;
			pSt[i]->setName(new_name);
			cout << "\nEnter surname : ";
			cin >> new_surname;
			pSt[i]->setSurname(new_surname);
			cout << "\nEnter age : ";
			cin >> new_age;
			pSt[i]->setAge(new_age);
			cout << "\nEnter phone : ";
			cin >> new_phone;
			pSt[i]->setPhone(new_phone);
			cout << "\nEnter rating : ";
			cin >> new_rating;
			pSt[i]->setRating(new_rating);

			Print();
			res = true;
			return;
		}
	}
	if (res == false)
	{
		cout << "\nStudent " << name << " " << surname << " was not found in the list..." << endl;
	}
	_getch();
}

void AcademyGroup::Print()
{
	//system("cls");
	cout << setw(15);
	cout << "Name";
	cout << setw(15);
	cout << "Surname";
	cout << setw(11);
	cout << "Age";
	cout << setw(15);
	cout << "Rating";
	cout << setw(20);
	cout << "Phone";
	cout << endl << endl;
	for (int i = 0; i < count; i++)
	{
		cout << setw(15) << pSt[i]->getName();
		cout << setw(15) << pSt[i]->getSurname();
		cout << setw(10) << pSt[i]->getAge();
		cout << setw(20) << pSt[i]->getRating();
		cout << setw(15) << pSt[i]->getPhone();
		cout << endl;
	}

	_getch();
}
void AcademyGroup::FindStudent()
{
	char surname[20];
	bool res = false;
	cout << "\nPlease enter a surname to search ...";
	cin >> surname;
	system("cls");
	cout << setw(15);
	cout << "Name";
	cout << setw(15);
	cout << "Surname";
	cout << setw(11);
	cout << "Age";
	cout << setw(15);
	cout << "Adress";
	cout << setw(20);
	cout << "Phone Number";
	cout << endl << endl;

	for (int i = 0; i < count; i++)
	{
		if (!strcmp(surname, pSt[i]->getSurname()))
		{
			cout << setw(15) << pSt[i]->getName();
			cout << setw(15) << pSt[i]->getSurname();
			cout << setw(10) << pSt[i]->getAge();
			cout << setw(20) << pSt[i]->getRating();
			cout << setw(15) << pSt[i]->getPhone();
			res = true;
			cout << endl;
		}
	}
	if (res == false)
	{
		cout << "\nStudent " << surname << " was not found in the list..." << endl;
	}


	_getch();
}

void AcademyGroup::Sort()
{

	for (long i = 1; i < count; i++)
	{
		Student* temp = pSt[i];
		long j = i - 1;
		while (j >= 0 && strcmp(pSt[j]->getSurname(), temp->getSurname()) > 0)
		{
			pSt[j + 1] = pSt[j];
			j--;
		}
		pSt[j + 1] = temp;
	}

	cout << "\nList sorted successfully";
	_getch();
	system("cls");
}


void AcademyGroup::Save()
{
	FILE* file = nullptr;
	fopen_s(&file, "Student.txt", "wb");
	fwrite(&count, sizeof(int), 1, file);
	for (size_t i = 0; i < count; i++)
	{
		int name_size = strlen(pSt[i]->getName()) + 1;
		fwrite(&name_size, sizeof(int), 1, file);
		fwrite(pSt[i]->getName(), name_size, 1, file);

		int surname_size = strlen(pSt[i]->getSurname()) + 1;
		fwrite(&surname_size, sizeof(int), 1, file);
		fwrite(pSt[i]->getSurname(), surname_size, 1, file);

		int age = pSt[i]->getAge();
		fwrite(&age, sizeof(int), 1, file);

		double rating = pSt[i]->getRating();
		fwrite(&rating, sizeof(double), 1, file);

		int phone_size = 14;
		fwrite(pSt[i]->getPhone(), sizeof(char), phone_size, file);
	}
	fclose(file);
	if (true)
	{
		cout << "\nList saved.";
	}
	else {
		cout << "\nError!!! List not saved.";
	}
	_getch();
	system("cls");
}

void AcademyGroup::Load()
{
	FILE* file = nullptr;
	fopen_s(&file, "//Student.txt", "rb");
	int name_size;
	int surname_size;
	if (file == nullptr)
	{
		perror("Error opening");
		return;
	}
	else
	{
		fread(&count, sizeof(int), 1, file);
	}
	pSt = new Student * [count];
	for (int i = 0; i < count; i++)
	{
		fread(&name_size, sizeof(int), 1, file);
		char* name = new char[name_size + 1];
		fread(name, name_size, 1, file);

		fread(&surname_size, sizeof(int), 1, file);
		char* surname = new char[surname_size + 1];
		fread(surname, surname_size, 1, file);

		int age;
		fread(&age, sizeof(int), 1, file);

		double rating;
		fread(&rating, sizeof(double), 1, file);

		char phone[14];
		fread(phone, sizeof(phone), 1, file);

		pSt[i] = new Student(name, surname, age, phone, rating);
		delete[]name;
		delete[]surname;
		name = nullptr;
		surname = nullptr;
		pSt[i]->Print();
	}
	fclose(file);
	if (true)
	{
		cout << "\nList loaded.";
	}
	else {
		cout << "\nError!!! List not loaded.";
	}
	_getch();
}

AcademyGroup& AcademyGroup::operator=(const AcademyGroup& obj)
{
	if (this == &obj)
		return *this;
	for (int i = 0; i < count; i++)
	{
		delete pSt[i];
	}
	delete[] pSt;

	count = obj.count;
	pSt = new Student * [count];
	for (size_t i = 0; i < obj.count; i++)
	{
		pSt[i] = new Student(*obj.pSt[i]);
	}
	return *this;
}

AcademyGroup& AcademyGroup::operator=(AcademyGroup&& obj)
{
	if (this == &obj)
		return *this;
	for (int i = 0; i < count; i++)
	{
		delete pSt[i];
	}

	delete[] pSt;
	count = obj.count;
	pSt = obj.pSt;
	obj.pSt = nullptr;
	obj.count = 0;
	return *this;
}

Student& AcademyGroup:: operator[](int index)
{
	if (index >= count || index < 0)
		return *pSt[0];
	return *pSt[index];
}

std::ostream& operator<<(std::ostream& os, AcademyGroup& obj)
{
	obj.Print();			//уточнить
	return os;
}
