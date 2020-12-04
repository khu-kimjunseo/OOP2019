#include<iostream>
using namespace std;

// this pointer: 객체 자기자신의 주소값을 가지고 있는 포인터
// Point pt; pt.x ( == this->x)
class Point {
private:
	int x;
	int y;
	static int countCreatedObjects;
//1	int* list;
//2	ofstream fout;

public:
	Point() : x(0), y(0) {
//1		list = new int[100];
//2		fout.open("file.txt.");
		countCreatedObjects++;
	}
	Point(int _x, int _y) : x(_x), y(_y) {
//1		list = new int[100];
//2		fout.open("file.txt.");
		countCreatedObjects++;
	}
	~Point() {
//1		delete[] list;
//2		fout.close();
		cout << "Destructed.." << endl;
	}

	void setXY(int x, int y);
	int getX() const; // 이 때, const는 함수에서 객체를 const로 입력받을 때 사용할 수 있는 method임을 의미.
	int getY() const;
	static int getcountCreatedObjects() { return countCreatedObjects; }
	friend ostream& operator<<(ostream& cout, const Point& pt);
	friend class spyPoint;

	// 2) class 내부
	Point operator+(const Point& pt) { // pt1 + pt2 --> pt1.+(pt2)
		Point result(this->x + pt.getX(), this->y + pt.getY());
		return result;
	}
//	Point& operator=(			   ) { // pass by reference }
	Point operator=(const Point& pt) { // pass by value
		this->x = pt.x;
		this->y = pt.y;
		return (*this);
	}
};

class spyPoint {
public:
	void hacking(const Point& pt) {
		cout << "x: " << pt.x << endl;
		cout << "y: " << pt.y << endl;
		cout << "countCreatedObjects: " << pt.countCreatedObjects << endl << endl;
	}
};
int Point::countCreatedObjects = 0; //static 멤버변수를 class 내부에서 초기화하면 객체를 생성할 때 마다 초기화되므로 의미가 없어진다. 따라서 항상 class 외부에서 초기화할것.

// method를 class 외부에서 정의할 때는 객체이름:: 을 적어주면 됨
void Point:: setXY(int x, int y) {
	this->x = getX(); //멤버 변수 x와 입력 변수 x를 구분하기 위해 멤벼변수 x임을 표기하기 위해 this->x를 사용
	this->y = getY();
}

int Point:: getX() const { return x; }
int Point::getY() const { return y; }



//pass by reference : 객체는 함수의 입력이 될 때 pass by ref. 추천
// const : 함수 내부에서 객체의 멤버 변수가 바뀌지 않음을 명시
// -> Class 의 method 들에 const 를 삽입해야 함 ( 함수이름 const {})
//	예) int getX() const { return x; }
//		int getY() const { retrun y; }

void print_pt(const Point& pt) {
	cout << pt.getX() << ", " << pt.getY() << endl;
}

//연산자 오버로딩: +, -, *, ==, !=, >=, =, += 등을 객체에 맞게 재정의
//		1) class 외부: operator+(좌측 피연산자, 우측피연산자)
//		2) class 내부: operator+(우측피연산자)->좌측 피연산자는 자기자신
// result = pt1 + pt2

// 1) class 외부 
/*
반환값이 Point객체 이기때문에 Point operator+
Point operator+(const Point& pt1, const Point& pt2) {
	Point result(pt1.getX() + pt2.getX(), pt1.getY() + pt2.getY());
	return result;
}
*/

// cout<< pt.getX() << ", " << pt.getY() << endl;
// cout << pt --> <<(cout, pt)


ostream& operator<<(ostream& cout, const Point& pt) {//구글에 return by reference 검색
	cout << pt.x << ", " << pt.y << endl;
	return cout;

//	reutrn cout이 있어야 하는 이유 -> 반환값이 cout이기 때문에 ostream& operator<<
//	cout << x << y;
//	cout << x -> return cout
//	cout << y 
}

int main() {
	Point pt1(1, 2);
	print_pt(pt1);
	cout << "countCreatedObjects: " << pt1.getcountCreatedObjects() << endl;

	Point* pPt = &pt1; // pPt는 객체가 아닌 포인터 변수임
	cout << (*pPt).getX() << ", " << (*pPt).getY() << endl;
	cout << pPt->getX() << ", " << pPt->getY() << endl; 
	//객체 포인터를 사용시에는 (*pPt).getX() 대신 pPt->getX() 사용 가능. 둘은 완전히 동일함

	Point* list = new Point[5];
	for (int i = 0; i < 5; i++) {
		cout << list[i].getX() << ", " << list[i].getY() << endl;
	}
	cout << endl;
	cout << "countCreatedObjects: " << list[0].getcountCreatedObjects() << endl;
	cout << "Befor delete[]" << endl;
	delete[] list;
	cout << "After delete[]" << endl;

	Point pt2(10, 20);
	Point pt3(100, 200);
	pt1 = pt2 + pt3; // operator overloadding에 의해 result 객체가 생성되었기 때문에 countCreatedObjects는 9가 된다.
	cout << "countCreatedObjects: " << pt1.getcountCreatedObjects() << endl;
//	cout << pt1.getX() << ", " << pt1.getY() << endl;
	cout << pt1;
	cout << pt2;
	cout << pt3;

	spyPoint spy;
	spy.hacking(pt1);
	spy.hacking(pt2);
	spy.hacking(pt3);

	cout << "Exit progream" << endl;
	return 0;
}