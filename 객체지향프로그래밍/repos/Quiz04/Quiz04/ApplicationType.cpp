#include "ApplicationType.h"

void ApplicationType::run() {
	string sOption;
	while (1) {
		sOption = getCommand();
		if (sOption == "1")
			input_item();
		else if (sOption == "2")
			displayAllShapes();
		else if (sOption == "3")
			break;
	}
	cout << "Exit the program..." << endl;
}
string ApplicationType::getCommand() {
	string cmd;
	cout << "1. Input Item" << endl << "2. Display Items" << endl << "3. Quit" << endl << "Input>";
	cin >> cmd;
	return cmd;
}
void ApplicationType::input_item() {
	string num;
	Shape* pShape;
	cout << "Enter the number of sides( 3:triangle of 4:rectangle ): ";
	cin >> num;
	if (num == "3") {
		int side1, side2, side3;
		cout << "Enter three sides: ";
		cin >> side1 >> side2 >> side3;
		pShape = new Triangle(3, side1, side2, side3);
		shapes.push_back(pShape);
		cout << endl;
	}
	else if (num == "4") {
		int length, width;
		cout << "Enter width and height: ";
		cin >> length >> width;
		pShape = new Rectangle(4, length, width);
		shapes.push_back(pShape);
		cout << endl;
	}
	else
		cout << "Error: please enter 3 or 4" << endl << endl;
}
void ApplicationType::displayAllShapes() {
	for (auto elem : shapes)
		elem->print();
}
