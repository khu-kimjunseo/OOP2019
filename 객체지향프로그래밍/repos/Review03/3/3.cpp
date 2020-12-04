#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"FoodItem.h"
#include"OfficeItem.h"
using namespace std;
int main() {
	vector<Item*> vItem;
	Item* pItem = new FoodItem;

	ifstream fin("fooditem.txt");

	while (pItem->readItemFromFile(fin))
		vItem.push_back(pItem);

	fin.close();

	pItem = new OfficeItem;

	fin.open("office.txt");

	while (pItem->readItemFromFile(fin))
		vItem.push_back(pItem);

	fin.close();

	for (auto elem : vItem)
		elem->displayItem();
}

