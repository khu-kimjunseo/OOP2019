#pragma once
#include <iostream>
#include <string>
#include "CText.h"
using namespace std;

class FixedText :public Text {
public:
	FixedText();
	string get() const override;
	void append(string _t) override;
};



