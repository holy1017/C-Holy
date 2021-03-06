#include <stdlib.h>
#include <stdio.h>


class C006
{
public:
	
	int locX = 0, locY = 0,lenW=0, lenH = 0;
	int minX = 0, minY = 0, maxX = 0, maxY = 0;
	bool** arr=NULL; // 기본값 true
	

	C006(int lenW, int lenH)
	{
		arrMake(lenW, lenH);
	}

	void line(int x1, int y1, int x2, int y2) {


		// H = y2 - y1 // 1번
		// W = x2 - x1 // 2번
		// W*y2 - W*y1 = H*x2 - H*x1 // 1*2
		// F = 0 = H*x2 - H*x1 - ( W*y2 - W*y1)
		// F = H*(x2 - x1) - W*(y2 - y1)
		
		// 현제 F값에 따라 다음 F 값 설정(Fu , Fd , Fm)
		// Fu= H*(x2+1 - x1) - W*(y2+1  - y1)
		// Fd= H*(x2+1 - x1) - W*(y2    - y1)
		// Fm= H*(x2+1 - x1) - W*(y2+0.5- y1)=(Fu+Fm)/2  // 이게 프로그램에서의 F

		// if Fm>0 경우 다음 F 기준값
		//dFu= H*(x2+2 - x1) - W*(y2+0.5- y1)
		//dFu= Fm + H // dF1
		//
		// if Fm<0
		//dFd= H*(x2+2 - x1) - W*(y2+1.5- y1)
		//dFd= Fm + H + W // dF2

		// 단순 판정판을 위한 용도라서
		// 정수형으로 처리하기 위해 Fm , dFu , dFd 전부 2식 곱함
		int W = x2 - x1, H = y2 - y1;
		int x = x1, y = y1;
		
		if (W > H) {		
			int F = 2 * H - W, dF1 = 2 * H, dF2 = 2 * (H - W);
			for (; x <= x2; x++)
			{
				setTrue(x, y);
				if (F < 0) // 선분 위
				{
					F += dF1;
				}
				else { // 선분 아래
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
				if (F < 0) // 선분 위
				{
					F += dF1;
				}
				else { // 선분 아래
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
		// 원출처가 헷갈리게 해놔서 제대로 수정
		// arr = new bool* [lenH];
		// for (int i = 0; i < lenH; ++i) {
		// 	arr[i] = new bool[lenW] ;
		// }

		// 하지만 이거 쓸거. 관리 측면
		int height = lenH, width = lenW;
		//int** arr;
		arr = (bool**)malloc(sizeof(bool*) * height);
		arr[0] = (bool*)malloc(sizeof(bool) * width * height);
		for (int i = 1; i < height; i++) {
			arr[i] = arr[i - 1] + width;
		}

		//출처: https://codeng.tistory.com/8 [도전!]

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
				printf(arr[y][x] ? "■" : "□");
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
				printf(arr[y][x] ? "■" : "□");
				//if (arr[y][x]) {
				//	printf("■");
				//}
				//else {
				//	printf("□");
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
