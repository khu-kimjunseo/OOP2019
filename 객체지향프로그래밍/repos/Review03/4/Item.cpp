#include"Item.h"

Item::Item(string _code, string _name, string _price) :code(_code), name(_name), price(_price) {}

void Item :: setCode(string _code) {
	code = _code;
}
void Item:: setName(string _name) {
	name = _name;
}
void Item:: setPrice(string _price) {
	price = _price;
}

string Item::getCode() { return code; }
string Item:: getName() { return name; }
string Item::getPrice() { return price; }
