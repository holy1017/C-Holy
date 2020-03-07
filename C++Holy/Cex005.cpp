#include <iostream>
#include <vector> 
using namespace std;
// 추상 클래스 
class Shape { 
	public: virtual void Draw() = 0; // 순수 가상함수 
}; 

// 구체 클래스 (concerect class) 
class Rect : public Shape 
{ 
public: 
	virtual void Draw() override { 
		cout << "Draw" << endl;
	} 
}; 
