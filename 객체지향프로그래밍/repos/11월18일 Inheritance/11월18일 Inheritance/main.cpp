#include<iostream>
#include<string>
#include<vector>
using namespace std;
 
//함수 overriding: 부모class의 method를 자식class에서 재정의
//	1) 부모클래스 method: virtual void f() {}
//	2) 자식클래스 method: void f() override {}

class Text {
private:
	string text;
public:
	Text(string _t) :text(_t) {}
	virtual string get() const { return text; }
	virtual void append(string _t) { text += _t; }
};

class FancyText : public Text {
private:
	string left_bracket;
	string right_bracket;
	string connector;
public:
	FancyText(string _t, string _left, string _right, string _con) : Text(_t), left_bracket(_left), right_bracket(_right), connector(_con) {} //text변수는 private이므로 초기화 불가능 
																																			  //-> Text생성자를 이용해서 text를 초기화함
	//overriding: virtual 과 override
	string get() const override { return left_bracket + Text::get() + right_bracket; }
	void append(string _t) override { Text::append(connector + _t); }
};

class FixedType : public Text {
public:
	FixedType() :Text("FIXED") {}
	void append(string _t) override {}
};

int main() {
	Text t1("plain");
	FancyText t2("fancy", "<<", ">>", "-");
	FixedType t3;

	cout << t1.get() << endl;
	cout << t2.get() << endl;
	cout << t3.get() << endl << endl; //FixedType에서는 overriding이 안되있으므로 부모 class인 Test의 get()함수를 사용

	t1.append("A");
	t2.append("A");
	t3.append("A");

	cout << t1.get() << endl;
	cout << t2.get() << endl;
	cout << t3.get() << endl << endl;
	
	t1 = t2; // 자식class 객체를 부모class 객체에 할당 가능 (부모 <- 자식) ---- t1.text == "fancy" (True)
//	t2 = t1;    역은 불가능 (자식 <- 부모)

	//Static Bindin(g(정적바인딩): 부모class 포인터에 부모class 객체의 주소값을 넣어 부모class의 method를 사용
	Text* pT;
	pT = &t1;//Text t1;
	pT->append("B"); //Text::append
	cout << pT->get() << endl; //Text::get()

	//Dynamic Binding(동적바인딩): 부모class 포인터에 자식class 객체의 주소값을 넣으면 자식class의 (virtual, override로 연결 된)method를 사용
	pT = &t2;//FancyText t2;
	pT->append("B"); //FancyText::append
	cout << pT->get() << endl; //FancyText::get()  

	//Polymorphism(다형성): 부모class 포인터로 모든 자식class를 사용
	vector<Text*> texts{ new Text("Wow"),
		new FancyText("Whoa","(",")","-"),
		new FixedType
	};

	for (auto elem : texts)
		cout << elem->get() << endl;

	return 0;
}
/*
// Base type이 private: 자식 클래스에서 사용 불가
// Base type이 protected: 자식 클래스에서 private으로 사용
// Base type이 public: 1)상속 type이 public: 자식클래스에서 public
//					   2)상속 type 이 protected/private: 자식클래스에서 private


// 일반적으로 Base class에서 private는 protected로, 상속 type은 항상 public 사용


class Base {
public: //Base type
	void f() { cout << "Base::f()" << endl; }
};

class Derived : public Base{//상속 type
public:
	void g() { cout << "Derived::g()" << endl;
	Base::f();
	}
	
};

int main() {
	
	return 0;
}
*/