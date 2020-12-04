#include<iostream>
using namespace std;


//private: 리모컨의 트랜지스터, 칩 --> class내부에서만 사용/ 외부에서 사용 못함
//public: 리모컨의 버튼 --> class 내/외부에서 사용가능
//setter: private 변수들의 값을 설정하는 함수
//getter: private 변수들을 외부로 반환
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
	
	// pt1.x = 10; x, y는 private 변수이므로 main에서 접근 불가
	// pt2.y = 20;
	pt1.setXY(10, 20);
	pt2.setXY(100, 200);

	pt1.print();
	cout << pt2.getX() << ", " << pt2.getY() << endl;
	
	return 0;
}