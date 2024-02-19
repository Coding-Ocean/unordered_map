#include<iostream>
#include<unordered_map>
using namespace std;

//pair�\��
template<typename T1, typename T2>
ostream& operator<<(ostream& s, const pair<T1, T2>& d) {
	return s << d.first << ":" << d.second;
}
//�S�v�f�\��
template <class C>
void show(const C& data) {
	for (const auto& d : data)
		cout << d << "\n";
	cout << "\n";
}

//���C��
int main() {
#if 1
	//�u���i�R�[�h�v�Ɓu���i���A�P���v�̃��j���[�}�b�v
	unordered_map< string, pair<string, int> > menu;
	//�f�[�^�\�z
	menu["a"] = { "�L�q",100 };
	menu["b"] = { "���[����",200 };
	menu["c"] = { "�`���[�n��",300 };
	menu.emplace("d", make_pair("�G�r�}��", 400));
	//�S�f�[�^�\��
	show(menu);

#else
	//����f�[�^
	struct SALE { string code; int num; };
	list<SALE>sales{ {"a",10},{"b",20},{"c",30},{"d",40} };
	for (const auto& sale : sales) {
		auto [name, price] = menu[sale.code];
		cout << name << ":" << price * sale.num << endl;
	}
#endif
	system("pause>0");
}