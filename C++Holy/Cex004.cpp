#include <iostream>
using namespace std;

class Person
{
public:
	void Sleep() {
		cout << "Sleep" << endl;
	}	
	virtual void Sleep1() {
		cout << "Sleep" << endl;
	}
};

class Student : public Person
{
public:
	void Study() {
		cout << "Study" << endl;
	}
};

class ScholarStd : public Student
{
public:
	void Receive_Scholar() {
		cout << "Work" << endl;
	}
};
class ScholarStd1 : public Student
{
public:
	 void Sleep()  {
		cout << "No Sleep" << endl;
	}
	 void Sleep1() {
		 cout << "No Sleep" << endl;
	 }
};