#include<iostream>
using namespace std;


//private: �������� Ʈ��������, Ĩ --> class���ο����� ���/ �ܺο��� ��� ����
//public: �������� ��ư --> class ��/�ܺο��� ��밡��
//setter: private �������� ���� �����ϴ� �Լ�
//getter: private �������� �ܺη� ��ȯ
class Point {
private:
	int x;
	int y;
public:
	void setXY(int _x, int _y) {
		x = _x;
		y = _y;
	}
	int getX() { return x; }
	int getY() { return y; }
	void print() {
		cout << "(" << x << ", " << y << ")" << endl;
	}
};

int main() {
	Point pt1, pt2;
	
	// pt1.x = 10; x, y�� private �����̹Ƿ� main���� ���� �Ұ�
	// pt2.y = 20;
	pt1.setXY(10, 20);
	pt2.setXY(100, 200);

	pt1.print();
	cout << pt2.getX() << ", " << pt2.getY() << endl;
	
	return 0;
}