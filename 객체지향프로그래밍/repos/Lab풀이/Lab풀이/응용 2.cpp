#include<iostream>
#include<fstream>
using namespace std;

int main() {
	string data = "���,���α׷���,����,����ǹٺ�,���뿪,õ���ǻ��,�����,��ü����";
	string delimeter = ",";//","�� �ܾ �����ϱ� ����
	string keyword;
	string word;
	int pos = 0;

	cout << "Ű���� : ";
	cin >> keyword;

	cout << endl << "�˻���� : ";

	while ((pos = data.find(delimeter)) != string::npos) {
					//��ǥ ��ġ�� ã�� pos�� �����ϰ�, �����Ѵٸ� while���� ����
		word = data.substr(0, pos);
					//�� �ܾ word�� ���� (ù��° ��ġ 0 ~ ��ǥ ��ġ pos)
		if(word.find(keyword)!=string::npos){//�� �ܾ keyword�� �����Ѵٸ�
			cout << word << "	";//���
		}
		data = data.substr(pos + delimeter.length());
					//�˻��� ���� �ܾ�� ����.
					//(���� ��ǥ ���� ��ġ���� data ������ substr)
	}
	cout << "\n";

	return 0;
}