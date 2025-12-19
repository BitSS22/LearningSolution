#include <iostream>

int main()
{
	// 일반 변수.
	{
		int a; // ok.
		a = 1; // ok.
		a = 3;

		// 전부 문제 없다.
	}

	// 상수.
	{
		// const int a; // error
		// 값 선언시 초기화 필요.

		const int a = 1;
		int const b = 1; // ok
		// 두 코드는 완전히 같은 의미다.
		// 실제 문법적 의미는 int const 쪽이 더 적절하다 보이지만(const pointer 때문에.), 실제로 사용 빈도는 const int 형식이 압도적인듯.

		// a = 3; // error
		// 값 변경 불가능.

		// const_cast<int&>(a) = 3; // 정신 나간 미친 코드!!!!!
		// 캐스팅 된 const 변수(원본이 non-const)가 아닌 선언 자체가 const인 변수에 const cast로 값 변경은 UB다.

		int input = 0;
		std::cin >> input;
		const int c = input; // ok.
		// 중요한 점은 const가 컴파일 타임에 값이 초기화 됨을 보장하진 않는다는 것이다.

		int arr[b] = {}; // ok.
		// b의 값은 이미 컴파일 타임에 결정 될 수 있음.
		
		// int arr[c] = {}; // error.
		// 컴파일 타임에 c의 값이 결정 될 수 없음.
		
		// 컴파일 타임에 결정 된 값이 필요하다면 constexpr(옛날 스타일이라면 #define을..)을 사용해야 한다.
	}

	// 일반 포인터
	{
		int a = 0;
		int b = 0;

		int* ptr = &a;
		*ptr = 3;
		ptr = &b;

		// 전부 문제 없다.
		// ptr은 접근해 값을 변경 할 수도 있고, 다른 주소를 넣는 것도 문제 없음.
	}

	// const 포인터
	{
		int a = 0;
		int b = 0;

		const int* ConstPtr = &a;
		// *ConstPtr = 3; // error.
		ConstPtr = &b; // ok.
		// 가리키는 대상을 const int로 본다.
		// 즉, 주소로 접근해서 읽을 대상을 const int로 취급한다.

		int* const PtrConst = &a;
		*PtrConst = 3; // ok.
		// PtrConst = &b; // error.
		// 가리키는 대상은 여전히 int로 본다.
		// 하지만 포인터 변수 자체가 const.
		// 포인터 또한 주소라는 값을 들고 있으니, 그에 대한 상수성을 부여한다.

		const int* const ConstPtrConst = &a;
		// *ConstPtrConst = 3; // error.
		// ConstPtrConst = &b; // error.
		// 가리키는 대상을 const int로 보고, 포인터 변수 자체도 const 취급.
		// 따라서 둘 다 불가능하다.

		int const* const WaitWHAT = &a;
		// *WaitWHAT = 3; // error.
		// WaitWHAT = &b; // error.
		// int const, const int는 동일하다고 했다.
		// 가리키는 대상을 int const, const int로 보는 것의 차이인데, 둘 다 같은거잖아.
		// 따라서 int const* const, const int* const은 완전히 같은 표현이다.

		const const const const int* Huh = &a;
		// 재밌는건 MSVC에서만인지, 언어 자체가 그런지 const는 계속 써도 문법적으로 아무런 문제가 없다.
		// const const const const int* 는 그냥 const int*다.

		const const const int const const const const const const* const const const const const const WTF = &a; // ?????????
		// 어이 없지만 문제 없는 코드.
		// 그냥 const int* const 타입이다..

		int* ptr = &a;
		int* Otherptr = &b;
		const int* const* const ConstPtrConstPtrConst = &ptr; // ok.
		// 그럼 이 자료형 또한 문제 없이 추론 가능하다.
		// const int* const 타입을 가리키며 const 포인터 자료형이다.
		// 따라서 가리키는 대상을 수정할 수 없으며, 대상에 접근해 값을 바꿀수도 없다.
		// 만약 *ConstPtrConstPtrConst로 접근한다면, 해당 타입은 const int* const가 되며,
		// 마찬가지로 대상을 const int로 해석하며, 값을 변경할 수 없는 const 포인터 자료형이 된다.
		
		const int** const ConstPtrPtrConst = &ptr; // ok.

		// *ConstPtrConstPtrConst = Otherptr; // error!
		*ConstPtrPtrConst = Otherptr; // ok!
		// 따라서 두 자료형은 상수성에 관해서는 엄연히 다른 타입이 된다.

		int* const* const MutablePtr = &ptr; // ok.
		// *MutablePtr = &Otherptr; // error.
		**MutablePtr = 3; // ok!
		// 그렇다.
	}

	return 0;
}