#include "ApplicationClass.h"

ApplicationClass::ApplicationClass(string officetxt, string foodtxt) : officeItemFileName(officetxt), foodItemFileName(foodtxt) {
	fin.open(foodItemFileName);
	Item* pItem = new FoodItem;
	while (pItem->readItemFromFile(fin))
		vItem.push_back(pItem);
	fin.close();

	fin.open(officeItemFileName);
	pItem = new OfficeItem;
	while (pItem->readItemFromFile(fin))
		vItem.push_back(pItem);
	fin.close();
};

string ApplicationClass::ApplicationClass::getCommand() {
	string cmd;
	cout << "Input>";
	cin >> cmd;
	return cmd;
}
void ApplicationClass::displayAllItems() {
	for (auto elem : vItem)
		elem->displayItem();
}
void ApplicationClass::displayFoodItems() {
	for (auto elem : vItem) {
		if (elem->getCode().find("F") != -1)
			elem->displayItem();
	}
}
void ApplicationClass::displayOfficeItems() {
	for (auto elem : vItem) {
		if (elem->getCode().find("C") != -1)
			elem->displayItem();
	}
}

void ApplicationClass::searchItemByCode() {
	string _code;
	cout << "Enter the code: ";
	cin >> _code;
	for (auto elem : vItem) {
		if (elem->getCode().find(_code) != -1) {
			elem->displayItem();
		}
		else
			cout << "No items found" << endl;
	}
}

void ApplicationClass::ApplicationClass::run() {
	string sOption;
	while (1) {
		sOption = getCommand();
		if (sOption == "1")	displayAllItems();
		else if (sOption == "2") displayFoodItems();
		else if (sOption == "3") displayOfficeItems();
		else if (sOption == "4") searchItemByCode();
		else if (sOption == "5") break;
	}
	cout << "Exit the program..." << endl;
}