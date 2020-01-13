#include "Poly.cpp"

using namespace std;

int main()
{
//  12+1x^2+2x^1                第一项为常数项
//  12+1x^2+2x^1-x^2            合并为0
//  12+1x^2+2x^1-3x^2+3x^3      和并不为0
//  x+1x^2+2x^1+3x^2+3x^2       多次连续合并
//  x+1x^2+2x^1+3x^2+4x^5-10x^2 多次不连续合并
//  x+1x^2+2x^1+3x^2+4x^5+x^3   多次打乱顺序
//  x+1x^2+2x^1+3x^2-4x^2-3x    多次打乱顺序且合并后为0
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

