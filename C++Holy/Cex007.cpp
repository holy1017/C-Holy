#include <stdio.h>

class Cex007
{
public:
	Cex007()
	{
	}

	~Cex007()
	{
	}
    // http://blog.naver.com/PostView.nhn?blogId=clown7942&logNo=110113591261
	void printInt() {
        int a = -5, b = 23, c = 5376;


        long d = 325678;


        printf("정수형숫자format ");


        printf(" 1. a=%d", a);


        printf(" 2. a=%6d", a);      // 오른쪽맞춤


        printf(" 3. a=%06d", a);     // 오른쪽맞춤


        printf(" 4. b=%6d", b);


        printf(" 5. b=%+6d", b);     // 부호표시


        printf(" 6. c=%6d", c);


        printf(" 7. c=%-6d", c);     // 왼쪽맞춤


        printf(" 8. d=%6ld ", d);   // 오른쪽맞춤
//        [출처] [♠ C언어 ♠] printf - 자릿수를 맞추어 출력 | 작성자 kaka
	}

    void printFloat() {
        float a = -437.46, b = 1278.9;


        double c = 5.567;


        printf("실수형숫자format ");


        printf(" 1. a=%8.3f", a);


        printf(" 2. b=%8.3f", b);    // 오른쪽맞춤


        printf(" 3. c=%8.3f", c);


        printf(" 4. c=%8.f", c);     // 오른쪽맞춤


        printf(" 5. c=%8.1f", c);


        printf(" 6. c=%.2f", c);     // 왼쪽맞춤


        printf(" 7. a=%+.2f", a);


        printf(" 8. b=%+.2f ", b);  // 부호표시
       // [출처] [♠ C언어 ♠] printf - 자릿수를 맞추어 출력 | 작성자 kaka
    }

    void printchar() {
        //char* name1 = "string"; static 메소드 에서만 가능. "" 방식은 static 에서 쓰는 상수값이기때문
        char name1[] = "string";


        char name2[] = "chapter";


        printf("문자열format ");


        printf(" 1. name1=%10s", name1);     // 오른쪽맞춤


        printf(" 2. name2=%10s", name2);


        printf(" 3. name2=%-10s", name2);    // 왼쪽맞춤


        printf(" 4. name1=%.3s", name1);     // 세자리까지만왼쪽맞춤출력


        printf(" 5. name2=%.4s ", name2);
        //[출처] [♠ C언어 ♠] printf - 자릿수를 맞추어 출력 | 작성자 kaka
    }
    void printbase() {
        int a = 32, b = 512;


        long c = 4874;


        printf("진법및주소format ");


        printf(" 1. base 16 of a = %5x", a);


        printf(" 2. base 16 of a = %-5x", a);


        printf(" 3. base 8 of a = %5o", b);


        printf(" 4. base 8 of a = %-5o", b);


        printf(" 5. address of a = %p", &c);


        printf(" 6. address of a = %u ", &c);
        //[출처] [♠ C언어 ♠] printf - 자릿수를 맞추어 출력 | 작성자 kaka
    }

private:

};
