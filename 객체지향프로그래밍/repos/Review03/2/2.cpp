#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<iomanip>
using namespace std;

class Item {
private:
	string code;
	string name;
	int price;
public:
	Item() : code(""), name(""), price(0) {}
	Item(string _code, string _name, int _price) :code(_code), name(_name), price(_price) {}

	void setCode(string _code) {
		code = _code;
	}
	void setName(string _name) {
		name = _name;
	}
	void setPrice(int _price) {
		price = _price;
	}
	void setItem(string _code, string _name ,int _price) {
		code = _code;
		name = _name;
		price = _price;
	}

	string getCode() { return code; }
	string getName() { return name; }
	int getPrice() { return price; }

	int reaItemFromFile(ifstream& fin) {
		string _code, _name;
		int _price;
		fin >> _code;
		fin >> _name;
		fin >> _price;

		this->setItem(_code, _name, _price);

		if (!fin)
			return 0;
		else return 1;
	}
	void writeItemToFile(ofstream& fout) {
		fout << this->getCode() << setw(10) << this->getName() << setw(10) << this->getPrice() << endl;
	}
};

int main() {
	Item temp;
	vector<Item> vItem;
	string inFleName = "item.txt";
	string outFleName = "item_output.txt";

	ifstream fin(inFleName);

	while (temp.reaItemFromFile(fin)) 
	vItem.push_back(temp);

	fin.close();

	temp.setItem("E1002", "¹ÚÄ«½º", 1000);
	vItem.push_back(temp);


	ofstream fout(outFleName);

	for (auto elem : vItem) 
		elem.writeItemToFile(fout);
	
	fout.close();

	return 0;
}
