#include "OfficeItem.h"

string OfficeItem::getCompany() { return company; }
void OfficeItem::displayItem() const {
	cout << this->code << setw(10) << this->name << setw(10) << this->price << setw(10) << this->company << endl;
}
int OfficeItem::readItemFromFile(ifstream& _fin) {
	string code, name, price, company;
	if (_fin) {
		_fin >> code;
		_fin >> name;
		_fin >> price;
		_fin >> company;
	}
	return bool(_fin);
}

void OfficeItem::writeItemToFile(ofstream& _fout) {}

