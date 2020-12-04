#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Item
{
protected:
	string code;
	string name;
	string price;
public:
	Item() ;
	Item(string _code, string _name, string _price) ;

	void setCode(string _code) ;
	void setName(string _name) ;
	void setPrice(string _price) ;

	string getCode() ;
	string getName() ;
	string getPrice() ;

	virtual void displayItem() const = 0;
	virtual int readItemFromFile(ifstream& _fin) = 0;
	virtual void writeItemToFile(ofstream& _fout) = 0;
};

