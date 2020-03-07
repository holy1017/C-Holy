#include <stdlib.h>
#include <stdio.h>


class C006
{
public:
	
	int locX = 0, locY = 0,lenW=0, lenH = 0;
	int minX = 0, minY = 0, maxX = 0, maxY = 0;
	bool** arr=NULL; // �⺻�� true
	

	C006(int lenW, int lenH)
	{
		arrMake(lenW, lenH);
	}

	void line(int x1, int y1, int x2, int y2) {


		// H = y2 - y1 // 1��
		// W = x2 - x1 // 2��
		// W*y2 - W*y1 = H*x2 - H*x1 // 1*2
		// F = 0 = H*x2 - H*x1 - ( W*y2 - W*y1)
		// F = H*(x2 - x1) - W*(y2 - y1)
		
		// ���� F���� ���� ���� F �� ����(Fu , Fd , Fm)
		// Fu= H*(x2+1 - x1) - W*(y2+1  - y1)
		// Fd= H*(x2+1 - x1) - W*(y2    - y1)
		// Fm= H*(x2+1 - x1) - W*(y2+0.5- y1)=(Fu+Fm)/2  // �̰� ���α׷������� F

		// if Fm>0 ��� ���� F ���ذ�
		//dFu= H*(x2+2 - x1) - W*(y2+0.5- y1)
		//dFu= Fm + H // dF1
		//
		// if Fm<0
		//dFd= H*(x2+2 - x1) - W*(y2+1.5- y1)
		//dFd= Fm + H + W // dF2

		// �ܼ� �������� ���� �뵵��
		// ���������� ó���ϱ� ���� Fm , dFu , dFd ���� 2�� ����
		int W = x2 - x1, H = y2 - y1;
		int x = x1, y = y1;
		
		if (W > H) {		
			int F = 2 * H - W, dF1 = 2 * H, dF2 = 2 * (H - W);
			for (; x <= x2; x++)
			{
				setTrue(x, y);
				if (F < 0) // ���� ��
				{
					F += dF1;
				}
				else { // ���� �Ʒ�
					y++;
					F += dF2;
				}
			}
		}
		else {
			int F = 2 * W - H, dF1 = 2 * W, dF2 = 2 * (W - H);
			for (; y <= y2; y++)
			{
				setTrue(x, y);
				if (F < 0) // ���� ��
				{
					F += dF1;
				}
				else { // ���� �Ʒ�
					x++;
					F += dF2;
				}
			}
		}


	}

	void circleSet(int x, int y, int xr, int yr) {
		setTrue(x + xr, y + yr);
		setTrue(x - xr, y + yr);
		setTrue(x + xr, y - yr);
		setTrue(x - xr, y - yr);
		setTrue(x + yr, y + xr);
		setTrue(x - yr, y + xr);
		setTrue(x + yr, y - xr);
		setTrue(x - yr, y - xr);
	}

	void circle(int x, int y, int r) {
		int F = 1 - r , xr=0 , yr=r;

		circleSet(x,y,xr,yr);
		while (yr>=xr) {
			if (F < 0)
				F += xr * 2 +3 ;
			else {
				F += (xr - yr) * 2 + 5;
				yr--;
			}
			xr++;
			circleSet(x, y, xr, yr);
		}
	}


	void setTrue(int x, int y) {
		if (x< minX || x > maxX || y< minY || y > maxY) {
			return;
		}
		arr[y][x] = true;
	}

	void arrMake(int lenW, int lenH)
	{
		this->lenW = lenW;
		this->lenH = lenH;
		this->locX = 0;
		this->locY = 0;
		this->minX = 0;
		this->minY = 0;
		this->maxX = lenW-1;
		this->maxY = lenH-1;
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
