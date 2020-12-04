#include<iostream>
#include<fstream>
using namespace std;

int main() {
	string data = "사랑,프로그래밍,의자,사랑의바보,영통역,천년의사랑,냉장고,객체지향";
	string delimeter = ",";//","로 단어를 구분하기 위함
	string keyword;
	string word;
	int pos = 0;

	cout << "키워드 : ";
	cin >> keyword;

	cout << endl << "검색결과 : ";

	while ((pos = data.find(delimeter)) != string::npos) {
					//쉼표 위치를 찾아 pos에 저장하고, 존재한다면 while문을 실행
		word = data.substr(0, pos);
					//한 단어를 word에 저장 (첫번째 위치 0 ~ 쉼표 위치 pos)
		if(word.find(keyword)!=string::npos){//한 단어에 keyword가 존재한다면
			cout << word << "	";//출력
		}
		data = data.substr(pos + delimeter.length());
					//검색이 끝난 단어는 지움.
					//(현재 쉼표 다음 위치부터 data 끝까지 substr)
	}
	cout << "\n";

	return 0;
}