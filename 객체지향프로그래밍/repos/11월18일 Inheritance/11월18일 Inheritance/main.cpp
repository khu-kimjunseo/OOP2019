#include<iostream>
#include<string>
#include<vector>
using namespace std;
 
//�Լ� overriding: �θ�class�� method�� �ڽ�class���� ������
//	1) �θ�Ŭ���� method: virtual void f() {}
//	2) �ڽ�Ŭ���� method: void f() override {}

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
	FancyText(string _t, string _left, string _right, string _con) : Text(_t), left_bracket(_left), right_bracket(_right), connector(_con) {} //text������ private�̹Ƿ� �ʱ�ȭ �Ұ��� 
																																			  //-> Text�����ڸ� �̿��ؼ� text�� �ʱ�ȭ��
	//overriding: virtual �� override
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
	cout << t3.get() << endl << endl; //FixedType������ overriding�� �ȵ������Ƿ� �θ� class�� Test�� get()�Լ��� ���

	t1.append("A");
	t2.append("A");
	t3.append("A");

	cout << t1.get() << endl;
	cout << t2.get() << endl;
	cout << t3.get() << endl << endl;
	
	t1 = t2; // �ڽ�class ��ü�� �θ�class ��ü�� �Ҵ� ���� (�θ� <- �ڽ�) ---- t1.text == "fancy" (True)
//	t2 = t1;    ���� �Ұ��� (�ڽ� <- �θ�)

	//Static Bindin(g(�������ε�): �θ�class �����Ϳ� �θ�class ��ü�� �ּҰ��� �־� �θ�class�� method�� ���
	Text* pT;
	pT = &t1;//Text t1;
	pT->append("B"); //Text::append
	cout << pT->get() << endl; //Text::get()

	//Dynamic Binding(�������ε�): �θ�class �����Ϳ� �ڽ�class ��ü�� �ּҰ��� ������ �ڽ�class�� (virtual, override�� ���� ��)method�� ���
	pT = &t2;//FancyText t2;
	pT->append("B"); //FancyText::append
	cout << pT->get() << endl; //FancyText::get()  

	//Polymorphism(������): �θ�class �����ͷ� ��� �ڽ�class�� ���
	vector<Text*> texts{ new Text("Wow"),
		new FancyText("Whoa","(",")","-"),
		new FixedType
	};

	for (auto elem : texts)
		cout << elem->get() << endl;

	return 0;
}
/*
// Base type�� private: �ڽ� Ŭ�������� ��� �Ұ�
// Base type�� protected: �ڽ� Ŭ�������� private���� ���
// Base type�� public: 1)��� type�� public: �ڽ�Ŭ�������� public
//					   2)��� type �� protected/private: �ڽ�Ŭ�������� private


// �Ϲ������� Base class���� private�� protected��, ��� type�� �׻� public ���


class Base {
public: //Base type
	void f() { cout << "Base::f()" << endl; }
};

class Derived : public Base{//��� type
public:
	void g() { cout << "Derived::g()" << endl;
	Base::f();
	}
	
};

int main() {
	
	return 0;
}
*/