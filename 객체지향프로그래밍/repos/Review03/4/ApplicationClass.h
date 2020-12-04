#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include"FoodItem.h"
#include"OfficeItem.h"
using namespace std;
class ApplicationClass
{
private:
	vector<Item*> vItem;
	string officeItemFileName;
	string foodItemFileName;
	ifstream fin;
public:
	ApplicationClass(string office, string food);
	void run();
	void displayAllItems();
	void displayFoodItems();
	void displayOfficeItems();
	void searchItemByCode();
	string getCommand();
	
};

