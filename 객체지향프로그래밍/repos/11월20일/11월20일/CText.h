#pragma once// library가 여러번 include되는것을 방지
// (예: int a;가 여러번 수행되면 오류)
#include<iostream>
#include<string>
using namespace std;

class Text {
protected: //부모 class, 자식 class에서 모두 private
	string text;
public:
	Text(string _t) :text(_t) {}
	virtual string get() const = 0;
	virtual void append(string _t) = 0;
};

