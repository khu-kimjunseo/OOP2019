int main{
	User user[3];
string id, password, searchid, searchPassword;
for (int i = 0; i < 3; i++) {
	cout << "==" << i + 1 << "==" << endl;
	cout << "ID : ";
	cin >> id;
	for(int j = 0; j < i; j++)
		if (user[j].getId() == id) {

			cout << "이미 존재하는 ID입니다. \n종료합니다. \n";
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
	if (serchid == "종료") {
		cout << "종료하겠습니다.\n";
		return 0; // break; 도 가능
	}
	cout << "Password : ";
	cin >> searchPassword;
	for (int i = 0; i < 3; i++) {
		if ((user[i].getId() == searchId) && (user[i].getPassword() == searchPassword)) {
			cout << "로그인 되셨습니다." << endl;
			break;
		}
		else if (i == 2) // 마지막까지 찾았는데 없으면
			cout << "잘못된 Id거나 PASSWORD입니다." << endl;
	}
	cout << "=======" << endl;
}
}