#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"Item.h"
#include<iomanip>
using namespace std;

class FoodItem : public Item
{private:
	int dueDate;
public:
	int getDueDate();
	void displayItem() const override ;
	int readItemFromFile  (ifstream& _fin) override;
	void writeItemToFile (ofstream& _fout) override;
};

