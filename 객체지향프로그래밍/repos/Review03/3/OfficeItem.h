#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"Item.h"
#include<iomanip>
using namespace std;
class OfficeItem:public Item
{private:
	string company;
public:
	string getCompany();
	void displayItem() const override;
	int readItemFromFile(ifstream& _fin) override;
	void writeItemToFile(ofstream& _fout) override;
};

