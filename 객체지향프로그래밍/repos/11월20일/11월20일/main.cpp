#include<iostream>
#include<string>
#include<vector>
#include"CFancyText.h"
#include"CFixedText.h"
using namespace std;

//Ŭ������ header(.h)�� .cpp���Ϸ� �и�: header(�޴���, ����), .cpp(������, ����)
// ->����: client���� ���� ������ interface ����
//override�� �����ο��� ��� �Ұ�

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
//�߻� Ŭ����(Abstract class): ���� ���� �Լ��� ��� �ϳ� ������ �ִ� Ŭ����
// -main�Լ����� ��ü�� ������ �� ����
// -���������� single interface(Base class�� pointer)�θ� ���
class Base {
public:
	void f() { cout << "Base::f()" << endl; }
	virtual void vf() = 0;//���� ���� �Լ�: �ݵ�� �ڽ� class���� overriding �ؾߵ�
};

class Derived :public Base {
public:
	void f() { cout << "Derived::f()" << endl; }
	void vf() override { cout << "Derived::vf()" << endl; }
};

int main() {
	Base* pBase;
	pBase = new Derived;

	pBase->f(); //�������ε�: method���� compile�� ������(pointer type�� ��ġ)
	pBase->vf();//�������ε�: method���� run-time(������) ������(virtual-override)




	return 0;
}
*/