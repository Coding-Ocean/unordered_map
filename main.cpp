#include<iostream>
#include<unordered_map>
using namespace std;

template<typename T1, typename T2>
ostream& operator<<(ostream& s, const pair<T1,T2>& p) {
	return s << p.first << ":" << p.second;
}

template<typename T>
void show(const T& data) {
	for (const auto& d : data) {
		cout << d << endl;
	}
	cout << endl;
}

template<class C, typename T>
void find(const C& data, const T& key) {
	auto it = data.find(key);
	if (it != data.end()) {
		cout << *it << endl;
	}
	else {
		cout << key << ":not found\n";
	}
}

int main()
{
	//�L�[��string,�l��int�̒P���}�b�v
	unordered_map<string, int> price;
	//�f�[�^�̒ǉ�
	price["�L�q"] = 100;
	price["���[����"] = 200;
	price["�`���[�n��"] = 300;
	//�f�[�^�̒T���ƕ\��
	cout << price["���[����"] << "�~�ł��B\n";
	cout << endl;

	//�L�[��int,�l��string�̃��j���[�}�b�v
	unordered_map<int, string> menu;
	//�f�[�^�̒ǉ�
	menu.emplace(1,"�L�q");
	menu.emplace(2,"���[����");
	menu.emplace(3,"�`���[�n��");
	//�f�[�^�̒T���ƕ\��
	cout << menu[3] << "�ł��B\n";
	cout << endl;

	//�e���v���[�g�\����"pair"�̐���
	pair<int, string> Pair;
	//��L�̏������Ŏ��̍\���̂��o���オ��
	//  struct pair {
	//    int first;
	//    string second;
	//  }Pair;
	Pair = { 48,"AKB" };
	cout << Pair.first << ":" << Pair.second << endl;
	cout << endl;

	//find �T��
	int key = 48;
	auto it = menu.find(key);
	if (it != menu.end()) {
		//�C�e���[�^��pair���w��
		cout << it->first << ":" << it->second << "\n";
	}
	else {
		cout << key << ":not found\n";
	}
	find(menu, 3);
	find(menu, 4);
	cout << endl;
	find(price, "�L�q");
	find(price, "���т܂�");
	cout << endl;

	//�S�f�[�^�\��
	show(menu);
	show(price);

	cin.get();
}