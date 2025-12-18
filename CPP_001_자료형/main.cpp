
#include <iostream>

int main()
{
	// MSVC 기준

	{ bool a; std::cout << sizeof(a) << std::endl;; }
	// sizeof(1)

	{ signed a; std::cout << sizeof(a) << std::endl;; }
	// sizeof(4)

	{ unsigned a; std::cout << sizeof(a) << std::endl;; }
	// sizeof(4)

	{ char a; std::cout << sizeof(a) << std::endl;; }
	// sizeof(1)

	{ short a; std::cout << sizeof(a) << std::endl;; }
	// sizeof(2)

	{ short int a; std::cout << sizeof(a) << std::endl;; }
	// sizeof(2)

	{ short a; std::cout << sizeof(a) << std::endl;; }
	// sizeof(2)

	{ int long a; std::cout << sizeof(a) << std::endl;; }
	// sizeof(4)

	{ long int a; std::cout << sizeof(a) << std::endl;; }
	// sizeof(4)

	{ unsigned long int a; std::cout << sizeof(a) << std::endl;; }
	// sizeof(4)

	{ signed long long a; std::cout << sizeof(a) << std::endl;; }
	// sizeof(8)

	{ long a; std::cout << sizeof(a) << std::endl;; }
	// sizeof(4)

	{ float a; std::cout << sizeof(a) << std::endl;; }
	// sizeof(4)

	{ long float a; std::cout << sizeof(a) << std::endl;; }
	// sizeof(8) (비 표준 확장)

	{ double a; std::cout << sizeof(a) << std::endl;; }
	// sizeof(8)

	{ long double a; std::cout << sizeof(a) << std::endl;; }
	// sizeof(8)

	{ double a; std::cout << sizeof(a) << std::endl;; }
	// sizeof(8)

	// int 는 사실상 정수형 타입에 대한 통칭이라고 볼 수 있다.
	// int == signed int == signed
	// long 또한 수식어의 개념에 가깝다.
	// signed, unsigned, int, long은 수식어의 개념에 가깝다고 정리할 수 있을 것 같다.
	// 실제로 다른 컴파일러에서 long double은 8바이트가 아닌 다른 크기를 가진다고 한다.

	return 0;
}