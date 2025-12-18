#include <iostream>

class MyClass
{
public:
	// 일반적인 멤버 함수의 형태
	// int MyFunc() {} 
	// int MyFunc() const {}
	// 참조 한정자와 동시에 사용할 수 없다.

	// l-value 참조 한정사
	void MyFunc()&
	{
		std::cout << "L-value" << std::endl;
	}
	void MyFunc() const&
	{
		std::cout << "L-value Const" << std::endl;
	}

	// r-value 참조 한정사
	void MyFunc()&&
	{
		std::cout << "R-value" << std::endl;
	}
	void MyFunc() const&&
	{
		std::cout << "R-value Const" << std::endl;
	}

};

int main()
{
	MyClass myClass = {};
	const MyClass& myClassC = myClass;

	myClass.MyFunc(); // l-value
	myClassC.MyFunc(); // const l-value
	MyClass().MyFunc(); // x-value
	const MyClass().MyFunc(); // const x-value

	/*
	실행 결과
	L-value
	L-value Const
	R-value
	R-value Const
	*/

	return 0;
}