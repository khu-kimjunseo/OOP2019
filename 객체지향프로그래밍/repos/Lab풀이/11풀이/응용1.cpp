int main{
	User user[3];
string id, password, searchid, searchPassword;
for (int i = 0; i < 3; i++) {
	cout << "==" << i + 1 << "==" << endl;
	cout << "ID : ";
	cin >> id;
	for(int j = 0; j < i; j++)
		if (user[j].getId() == id) {

			cout << "�̹� �����ϴ� ID�Դϴ�. \n�����մϴ�. \n";
			return 0;
		}
}
user[i].setId(id);
cout << "password : ";
cin >> password;
user[i].setPassword(password);
cout << "======" << endl;

while (1) {
	cout << "==Login==" << endl;
	cout << "ID : ";
	cin >> searchid;
	if (serchid == "����") {
		cout << "�����ϰڽ��ϴ�.\n";
		return 0; // break; �� ����
	}
	cout << "Password : ";
	cin >> searchPassword;
	for (int i = 0; i < 3; i++) {
		if ((user[i].getId() == searchId) && (user[i].getPassword() == searchPassword)) {
			cout << "�α��� �Ǽ̽��ϴ�." << endl;
			break;
		}
		else if (i == 2) // ���������� ã�Ҵµ� ������
			cout << "�߸��� Id�ų� PASSWORD�Դϴ�." << endl;
	}
	cout << "=======" << endl;
}
}