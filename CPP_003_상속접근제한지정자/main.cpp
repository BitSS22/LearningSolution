#include <iostream>

class A
{
public:
	int publicA = {};
protected:
	int protectedA = {};
private:
	int privateA = {};

public:
	void FuncA()
	{
		publicA = 0;
		protectedA = 0;
		privateA = 0;
	}

	virtual void MyFunc()
	{
		std::cout << "상속 테스트" << std::endl;
	}
};

class B : private A
{
public:
	void FuncA()
	{
		publicA = 0;
		protectedA = 0;
		// privateA = 0; // error
	}

	virtual void MyFunc() override
	{
		A::MyFunc(); // 문제 없다.
	}
};

class C : public B
{
public:
	void FuncA()
	{
		// publicA = 0; // error
		// protectedA = 0; // error
		// privateA = 0; // error
	}

	virtual void MyFunc() override
	{
		// A::MyFunc(); // error.
		// static_cast<A*>(this)->MyFunc(); // error.

		B::MyFunc(); // ok.
	}
};

int main()
{
	B* b = new B();
	// A* a = b; // E0269 액세스할 수 없는 기본 클래스 "A"(으)로의 변환은 허용되지 않습니다.
	// b->A::MyFunc(); // error.
	b->MyFunc(); // ok.

	delete b;

	C* c = new C();
	b = c; // ok.
	// a = c; // E0269 액세스할 수 없는 기본 클래스 "A"(으)로의 변환은 허용되지 않습니다.
	c->MyFunc(); // ok.
	c->B::MyFunc(); // ok.
	// c->A::MyFunc(); // error.

	delete c;

	// c++에는 상속 접근 제한 지정자가 존재한다.
	// 다른 언어에서는 대부분 지원하지 않는걸로 알지만, c++은 정말 별의 별 기능이 다 있다.
	// 멤버 접근 제한 지정자처럼 public, protected, private가 존재한다.
	// class의 기본 상속 접근 제한 지정자는 private, struct는 public이다.
	// 따라서 c++에서 class 상속을 할 때 class B : A 와 같이 하면 private 상속이 돼 버린다.
	// 접근 제한 지정자와 관계 없이 모든 상속은 기능을 온전히 물려 받는다.
	// 차이가 나는 부분은 어디서 어디까지 접근이 가능하냐다.
	// 접근 제한 지정자와 상관 없이 직접적으로 상속 받은 class는 부모의 모든 기능을 사용할 수 있다.
	// 상속 접근 제한 지정자가 차이가 나는 부분은 이 class를 class 외부에서 사용할 때 나타난다.
	// 즉 private 상속은 B is A가 아닌, B has A 관게가 된다.

	return 0;
}

