#include "Cex001.cpp"
#include "Cex004.cpp"
#include <iostream>
#include "Cex005.cpp"
#include "Cex006.cpp"
using namespace std;

Cex003 c3;
int (Cex003::* c3f)();

int main(int argc, char** argv) {

	// ==============================================  �޼ҵ�  ����Ʈ

	cout << &c3 << endl; // 005EB140
	cout << sizeof(c3f) << endl; // 8

	c3f = &Cex003::get_i;
	cout << (c3.*c3f)() << endl; // 8
	c3f = &Cex003::get_j;
	cout << (c3.*c3f)() << endl; // 8
	c3f = &Cex003::get_k;
	cout << (c3.*c3f)() << endl; // 8

	//======================================== Ŭ���� ��� ����Ʈ

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

	//======================================== Ŭ���� ��� ����Ʈ

	Shape* p; // �߻�Ŭ���� ����Ʈ�� ���� �� ���� 
	Rect r; // �߻� Ŭ������ ��ӹ��� Ŭ�������� ���� �����Լ��� �������� ������ error 
	p = new Rect;
	p->Draw();

	//======================================== 2���� �迭
	C006 c6 =  C006(7,3);
	
}

enum class Day { mon, tue, wed, thu, fri, sat, sun };

Day operator++(Day& d)
{
	return d == Day::sun ? Day::mon : Day{ ++d };
}

Day today = Day::sat;
Day tomorrow = ++today;