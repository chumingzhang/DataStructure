#include "Poly.cpp"

using namespace std;

int main()
{
//  12+1x^2+2x^1                ��һ��Ϊ������
//  12+1x^2+2x^1-x^2            �ϲ�Ϊ0
//  12+1x^2+2x^1-3x^2+3x^3      �Ͳ���Ϊ0
//  x+1x^2+2x^1+3x^2+3x^2       ��������ϲ�
//  x+1x^2+2x^1+3x^2+4x^5-10x^2 ��β������ϲ�
//  x+1x^2+2x^1+3x^2+4x^5+x^3   ��δ���˳��
//  x+1x^2+2x^1+3x^2-4x^2-3x    ��δ���˳���Һϲ���Ϊ0
	char *str = "x+1x^2+2x^1+3x^2+3x^2";
	Poly test(str);
	test.Display();

	Poly test2("x+1x^2+2x^1+3x^2+4x^5-10x^2");
	test2.Display();

//	if(test2 == test)
//        cout << "magic" << endl;

//	test2 = test;
//	test2.Display();

//    Poly t3;
//    t3 = test / test2;
//    t3.Display();

//    Poly t3;
//    t3 = test - test2;
//    t3.Display();

//    Poly t3;
//    t3 = test * test2;
//    t3.Display();

//    Poly t3;
//    t3 = test / test2;
//    t3.Display();

//	cout << test.Calculate(3.5);
//	test.Clear();
//	test.Display();
	return 0;
}

