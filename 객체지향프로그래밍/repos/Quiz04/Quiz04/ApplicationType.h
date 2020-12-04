#pragma once
#include<iostream>
#include"Rectangle.h"
#include"Triangle.h"
#include<vector>
#include<string>
using namespace std;

class ApplicationType
{private:
	vector<Shape*> shapes;
public:
	void run();
	string getCommand();
	void input_item();
	void displayAllShapes();
};

