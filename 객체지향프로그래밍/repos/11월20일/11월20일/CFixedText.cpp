#include "CFixedText.h"
FixedText::FixedText() :Text("FIXED") {}

string FixedText::get() const { 
	return text; 
}

void FixedText::append(string _t) {}
