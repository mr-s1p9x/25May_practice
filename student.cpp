#include <iostream>
using namespace std;

class Student
{
    char* name;
    int age;

public:
    // Прототип
    Student();
    Student(const char*, int); // Конструктор с 2 параметрами
    void Output();
    ~Student();
    void setAge(int a);
};

Student::Student()
{
    name = nullptr;
    age = 0;
}

Student::Student(const char* Name, int Age)
{
    name = new char[strlen(Name) + 1];
    strncpy(name, Name, strlen(Name) + 1);
    age = Age;
}

void Student::Output()
{
    cout << "Name: " << name << "\tAge: " << age << endl;
}

Student::~Student()
{
    delete[] name;
    cout << "Destruct\n";
}

void Student::setAge(int a)
{
    age = a;
}



