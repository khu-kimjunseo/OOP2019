class Account {
	string id;
	string name;
	int bal;
	static int total_Balance;
	Account(string _id, string _name, int _bal) : id(_id), name(_name), bal(_bal) {
		total_Balance += bal;
	}
};

Account::total_Balance = 0;

int main()