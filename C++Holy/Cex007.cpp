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


        printf("����������format ");


        printf(" 1. a=%d", a);


        printf(" 2. a=%6d", a);      // �����ʸ���


        printf(" 3. a=%06d", a);     // �����ʸ���


        printf(" 4. b=%6d", b);


        printf(" 5. b=%+6d", b);     // ��ȣǥ��


        printf(" 6. c=%6d", c);


        printf(" 7. c=%-6d", c);     // ���ʸ���


        printf(" 8. d=%6ld ", d);   // �����ʸ���
//        [��ó] [�� C��� ��] printf - �ڸ����� ���߾� ��� | �ۼ��� kaka
	}

    void printFloat() {
        float a = -437.46, b = 1278.9;


        double c = 5.567;


        printf("�Ǽ�������format ");


        printf(" 1. a=%8.3f", a);


        printf(" 2. b=%8.3f", b);    // �����ʸ���


        printf(" 3. c=%8.3f", c);


        printf(" 4. c=%8.f", c);     // �����ʸ���


        printf(" 5. c=%8.1f", c);


        printf(" 6. c=%.2f", c);     // ���ʸ���


        printf(" 7. a=%+.2f", a);


        printf(" 8. b=%+.2f ", b);  // ��ȣǥ��
       // [��ó] [�� C��� ��] printf - �ڸ����� ���߾� ��� | �ۼ��� kaka
    }

    void printchar() {
        //char* name1 = "string"; static �޼ҵ� ������ ����. "" ����� static ���� ���� ������̱⶧��
        char name1[] = "string";


        char name2[] = "chapter";


        printf("���ڿ�format ");


        printf(" 1. name1=%10s", name1);     // �����ʸ���


        printf(" 2. name2=%10s", name2);


        printf(" 3. name2=%-10s", name2);    // ���ʸ���


        printf(" 4. name1=%.3s", name1);     // ���ڸ����������ʸ������


        printf(" 5. name2=%.4s ", name2);
        //[��ó] [�� C��� ��] printf - �ڸ����� ���߾� ��� | �ۼ��� kaka
    }
    void printbase() {
        int a = 32, b = 512;


        long c = 4874;


        printf("�������ּ�format ");


        printf(" 1. base 16 of a = %5x", a);


        printf(" 2. base 16 of a = %-5x", a);


        printf(" 3. base 8 of a = %5o", b);


        printf(" 4. base 8 of a = %-5o", b);


        printf(" 5. address of a = %p", &c);


        printf(" 6. address of a = %u ", &c);
        //[��ó] [�� C��� ��] printf - �ڸ����� ���߾� ��� | �ۼ��� kaka
    }

private:

};
