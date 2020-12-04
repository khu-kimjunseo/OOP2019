#include<iostream>
#include<string>
using namespace std;

class Avengers {
public:
	Avengers() {
		name = "";
		attack_point = 0;
		defense_point = 0;
		health = 0;
	}
	~Avengers() {}
	virtual void set(string _name, int _attack, int _defense, int _health) {}
	virtual int attack() { return 0; }
	virtual void defense(int _attack_point) {}
	virtual void print_info() {}
protected:
	string name;
	int attack_point;
	int defense_point;
	int health;
};

class Character : public Avengers {
public:
	void set(string _name, int _attack, int _defense, int _health) override {
		name = _name;
		attack_point = _attack;
		defense_point = _defense;
		health = _health;
	}

	int attack() override { return attack_point; }

	void defense(int _attack_point) override {
		health -= _attack_point - defense_point;
		if (health < 0)
			health = 0;
	}

	void print_info() override {
		cout << "Name: " << name << endl << "Attack_Point: " << attack_point << endl <<
			"Defense_Point: " << defense_point << endl<< "Health: " << health << endl;
	}

	int get_health() {
		return health;
	}
};

int main() {
	Character my_char;
	Character enemy_char;
	int my_attack, enemy_attack;
	string chr;

	cout << "Choose your character(IronMan, CaptainAmerica, Thor): ";
	cin >> chr;
	if (chr == "IronMan")
		my_char.set("IronMan", 70, 40, 100);
	else if (chr == "CaptainAmerica")
		my_char.set("CaptainAmerica", 60, 50, 100);
	else if (chr == "Thor")
		my_char.set("Thor", 80, 30, 100);

	int n = rand() % 3;

	if (n == 0)
		enemy_char.set("IronMan", 70, 40, 100);
	else if (n == 1)
		enemy_char.set("CaptainAmerica", 60, 50, 100);
	else if (n == 2)
		enemy_char.set("Thor", 80, 30, 100);
	cout << "--My Character--" << endl;
	my_char.print_info();
	cout << "--Enemy Character--" << endl;
	enemy_char.print_info();

	cout << endl << "--Battle--" << endl;
	cout << "My Life: " << my_char.get_health() << "\t" << "Enemy Life: " << enemy_char.get_health() << endl;
	my_attack = my_char.attack();
	enemy_attack = enemy_char.attack();
	while (1) {
		

		enemy_char.defense(my_attack);
		cout << "My Life: " << my_char.get_health() << "\t" << "Enemy Life: " << enemy_char.get_health() << endl;
		if (my_char.get_health() <= 0) {
			cout << "You Win!" << endl;
			exit(100);
		}

		if (enemy_char.get_health() <= 0) {
			cout << "You Lose!" << endl;
			exit(100);
		}

		my_char.defense(enemy_attack);
		cout << "My Life: " << my_char.get_health() << "\t" << "Enemy Life: " << enemy_char.get_health() << endl;

		if (my_char.get_health() <= 0) {
			cout << "You Win!" << endl;
			exit(100);
		}

		if (enemy_char.get_health() <= 0) {
			cout << "You Lose!" << endl;
			exit(100);
		}
	}

}
