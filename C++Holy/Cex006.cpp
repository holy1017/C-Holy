#include <stdlib.h>
#include <stdio.h>


class C006
{
public:
	
	int lenW=0, lenH = 0;
	int minX = 0, minY = 0, maxX = 0, maxY = 0;
	bool** arr=NULL; // �⺻�� true
	

	C006(int lenW, int lenH)
	{
		arrMake(lenW, lenH);
	}




	void arrMake(int lenW, int lenH)
	{
		this->lenW = lenW;
		this->lenH = lenH;

		// ����ó�� �򰥸��� �س��� ����� ����
		// arr = new bool* [lenH];
		// for (int i = 0; i < lenH; ++i) {
		// 	arr[i] = new bool[lenW] ;
		// }

		// ������ �̰� ����. ���� ����
		int height = lenH, width = lenW;
		//int** arr;
		arr = (bool**)malloc(sizeof(bool*) * height);
		arr[0] = (bool*)malloc(sizeof(bool) * width * height);
		for (int i = 1; i < height; i++) {
			arr[i] = arr[i - 1] + width;
		}

		//��ó: https://codeng.tistory.com/8 [����!]

		reset();
	}

	void test()
	{
		for (int y = lenH - 1; y >= 0; --y) {
			printf("%2d:", y);
			for (int x = 0; x < lenW; ++x) {
				//printf("%d\n", x % 2);
				if (x%2==0)
				{
					arr[y][x] = false;
				}
				//printf("%d", arr[y][x]);
				printf(arr[y][x] ? "��" : "��");
			}
			printf("\n");
		}
	}
	
	void reset() {
		for (int y = lenH - 1; y >= 0; --y) {
			
			for (int x = 0; x < lenW; ++x) {

				arr[y][x] = false;

			}

		}
	}

	void print()
	{
		for (int y = lenH - 1; y >= 0; --y) {
			printf("%2d:", y);
			for (int x = 0; x < lenW; ++x) {
				//printf("%d", arr[y][x]);
				printf(arr[y][x] ? "��" : "��");
				//if (arr[y][x]) {
				//	printf("��");
				//}
				//else {
				//	printf("��");
				//}
			}
			printf("\n");
		}
		printf("x:");
		for (int x = 0; x < lenW; ++x) {
			printf("%2d", x);
		}
		printf("\n");
	}



	C006()
	{

	}

	~C006()
	{

	}


private:

};
