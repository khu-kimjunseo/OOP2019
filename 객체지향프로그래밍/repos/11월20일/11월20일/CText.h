#pragma once// library�� ������ include�Ǵ°��� ����
// (��: int a;�� ������ ����Ǹ� ����)
#include<iostream>
#include<string>
using namespace std;

class Text {
protected: //�θ� class, �ڽ� class���� ��� private
	string text;
public:
	Text(string _t) :text(_t) {}
	virtual string get() const = 0;
	virtual void append(string _t) = 0;
};

