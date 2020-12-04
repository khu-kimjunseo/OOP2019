#include<iostream>
using namespace std;

// this pointer: ��ü �ڱ��ڽ��� �ּҰ��� ������ �ִ� ������
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
	int getX() const; // �� ��, const�� �Լ����� ��ü�� const�� �Է¹��� �� ����� �� �ִ� method���� �ǹ�.
	int getY() const;
	static int getcountCreatedObjects() { return countCreatedObjects; }
	friend ostream& operator<<(ostream& cout, const Point& pt);
	friend class spyPoint;

	// 2) class ����
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
int Point::countCreatedObjects = 0; //static ��������� class ���ο��� �ʱ�ȭ�ϸ� ��ü�� ������ �� ���� �ʱ�ȭ�ǹǷ� �ǹ̰� ��������. ���� �׻� class �ܺο��� �ʱ�ȭ�Ұ�.

// method�� class �ܺο��� ������ ���� ��ü�̸�:: �� �����ָ� ��
void Point:: setXY(int x, int y) {
	this->x = getX(); //��� ���� x�� �Է� ���� x�� �����ϱ� ���� �⺭���� x���� ǥ���ϱ� ���� this->x�� ���
	this->y = getY();
}

int Point:: getX() const { return x; }
int Point::getY() const { return y; }



//pass by reference : ��ü�� �Լ��� �Է��� �� �� pass by ref. ��õ
// const : �Լ� ���ο��� ��ü�� ��� ������ �ٲ��� ������ ���
// -> Class �� method �鿡 const �� �����ؾ� �� ( �Լ��̸� const {})
//	��) int getX() const { return x; }
//		int getY() const { retrun y; }

void print_pt(const Point& pt) {
	cout << pt.getX() << ", " << pt.getY() << endl;
}

//������ �����ε�: +, -, *, ==, !=, >=, =, += ���� ��ü�� �°� ������
//		1) class �ܺ�: operator+(���� �ǿ�����, �����ǿ�����)
//		2) class ����: operator+(�����ǿ�����)->���� �ǿ����ڴ� �ڱ��ڽ�
// result = pt1 + pt2

// 1) class �ܺ� 
/*
��ȯ���� Point��ü �̱⶧���� Point operator+
Point operator+(const Point& pt1, const Point& pt2) {
	Point result(pt1.getX() + pt2.getX(), pt1.getY() + pt2.getY());
	return result;
}
*/

// cout<< pt.getX() << ", " << pt.getY() << endl;
// cout << pt --> <<(cout, pt)


ostream& operator<<(ostream& cout, const Point& pt) {//���ۿ� return by reference �˻�
	cout << pt.x << ", " << pt.y << endl;
	return cout;

//	reutrn cout�� �־�� �ϴ� ���� -> ��ȯ���� cout�̱� ������ ostream& operator<<
//	cout << x << y;
//	cout << x -> return cout
//	cout << y 
}

int main() {
	Point pt1(1, 2);
	print_pt(pt1);
	cout << "countCreatedObjects: " << pt1.getcountCreatedObjects() << endl;

	Point* pPt = &pt1; // pPt�� ��ü�� �ƴ� ������ ������
	cout << (*pPt).getX() << ", " << (*pPt).getY() << endl;
	cout << pPt->getX() << ", " << pPt->getY() << endl; 
	//��ü �����͸� ���ÿ��� (*pPt).getX() ��� pPt->getX() ��� ����. ���� ������ ������

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
	pt1 = pt2 + pt3; // operator overloadding�� ���� result ��ü�� �����Ǿ��� ������ countCreatedObjects�� 9�� �ȴ�.
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