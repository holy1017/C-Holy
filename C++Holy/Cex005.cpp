#include <iostream>
#include <vector> 
using namespace std;
// �߻� Ŭ���� 
class Shape { 
	public: virtual void Draw() = 0; // ���� �����Լ� 
}; 

// ��ü Ŭ���� (concerect class) 
class Rect : public Shape 
{ 
public: 
	virtual void Draw() override { 
		cout << "Draw" << endl;
	} 
}; 
