#include<iostream>
#include<string>
#include<vector>
#include"CFancyText.h"
#include"CFixedText.h"
using namespace std;

//클래스를 header(.h)와 .cpp파일로 분리: header(메뉴판, 선언), .cpp(조리법, 구현)
// ->목적: client에게 높은 가독성 interface 제공
//override는 구현부에서 사용 불가

void print(Text* pText) {
	cout << pText->get() << endl;
}

int main() {
	FancyText t1("fancy", "<<", ">>", "***");
	FixedText t2;
	print(&t1);
	print(&t2);
	cout << endl;

	vector<Text*> texts{ new FancyText("AAA","@","@","**"),
						new FixedText,
						new FancyText("BBB","%%","%%","---") };

	for (auto elem : texts)
		elem->append("append");

	for (auto elem : texts)
		print(elem);

	for (auto elem : texts)
		delete elem;
}
/*
//추상 클래스(Abstract class): 순수 가상 함수를 적어도 하나 가지고 있는 클래스
// -main함수에서 객체로 선언할 수 없음
// -다형성에서 single interface(Base class의 pointer)로만 사용
class Base {
public:
	void f() { cout << "Base::f()" << endl; }
	virtual void vf() = 0;//순수 가상 함수: 반드시 자식 class에서 overriding 해야됨
};

class Derived :public Base {
public:
	void f() { cout << "Derived::f()" << endl; }
	void vf() override { cout << "Derived::vf()" << endl; }
};

int main() {
	Base* pBase;
	pBase = new Derived;

	pBase->f(); //정적바인딩: method들이 compile시 결정됨(pointer type과 일치)
	pBase->vf();//동적바인딩: method들이 run-time(실행중) 결정됨(virtual-override)




	return 0;
}
*/