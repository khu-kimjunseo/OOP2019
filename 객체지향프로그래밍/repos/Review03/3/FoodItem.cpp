#include "FoodItem.h"

int FoodItem::getDueDate() { return dueDate; }
void FoodItem::displayItem() const {
	cout << this->code << setw(10) << this->name << setw(10) << this->price << setw(10) << this->dueDate << endl;
}
int FoodItem:: readItemFromFile(ifstream & _fin) {
	string code, name, price;
	int dueDate;
	if (_fin) {
		_fin >> code;
		_fin >> name;
		_fin >> price;
		_fin >> dueDate;
	}
	return bool(_fin);

}
void FoodItem::writeItemToFile(ofstream& _fout) {}