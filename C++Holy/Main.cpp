#include "Cex001.cpp"
#include "Cex004.cpp"
#include <iostream>
#include "Cex005.cpp"
#include "Cex006.cpp"
using namespace std;

Cex003 c3;
int (Cex003::* c3f)();

int main(int argc, char** argv) {

	// ==============================================  메소드  포인트

	cout << &c3 << endl; // 005EB140
	cout << sizeof(c3f) << endl; // 8

	c3f = &Cex003::get_i;
	cout << (c3.*c3f)() << endl; // 8
	c3f = &Cex003::get_j;
	cout << (c3.*c3f)() << endl; // 8
	c3f = &Cex003::get_k;
	cout << (c3.*c3f)() << endl; // 8

	//======================================== 클래스 상속 포인트

	Person* p1 = new Person;
	Person* p2 = new Student;
	Person* p3 = new ScholarStd;
	Person* p4 = new ScholarStd1;


	p1->Sleep();
	p2->Sleep();
	p3->Sleep();
	p4->Sleep();

	p1->Sleep1();
	p2->Sleep1();
	p3->Sleep1();
	p4->Sleep1();

	//======================================== 클래스 상속 포인트

	Shape* p; // 추상클래스 포인트는 만들 수 있음 
	Rect r; // 추상 클래스를 상속받은 클래스에서 순수 가상함수를 구현하지 않으면 error 
	p = new Rect;
	p->Draw();

	//======================================== 2차원 배열
	C006 c6 =  C006(7,3);
	
}

enum class Day { mon, tue, wed, thu, fri, sat, sun };

Day operator++(Day& d)
{
	return d == Day::sun ? Day::mon : Day{ ++d };
}

Day today = Day::sat;
Day tomorrow = ++today;