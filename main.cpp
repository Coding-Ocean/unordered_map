#include<iostream>
#include<unordered_map>
using namespace std;

//pair�^�\���p�A�}�����Z�q�̃I�[�o�[���[�h
template<typename T1, typename T2>
ostream& operator<<(ostream& s, const pair<T1, T2>& p) {
	return s << p.first << ":" << p.second;
}

//�ǂ̃R���e�i������őS���\���ł���
template<class C>
void show(const C& data) {
	for (const auto& d : data) {
		cout << d << endl;
	}
	cout << endl;
}

int main()
{
#if 1
	//�L�[��string,�l��int�̒P���}�b�v
	unordered_map<string, int> price;
	//insert�ɂ��f�[�^�̒ǉ�
	price.insert(make_pair("�L�q", 100));
	show(price);
#else
	//emplace�ɂ��f�[�^�̒ǉ�
	price.emplace("���[����", 200);
	//�m�n�ɂ��f�[�^�̒ǉ�
	price["�`���[�n��"] = 300;
	//�d�������L�[���w�肷��ƁA�f�[�^�͍X�V�ƂȂ�
	price["�L�q"] = 150;
	//�L�[�ɑΉ�����f�[�^�̕\��
	cout << price["�L�q"] << "�~\n\n";
	//�L�[���o�^����Ă��Ȃ��f�[�^��\������ƂO�~�f�[�^�Ƃ��Ēǉ������
	cout << price["�}�[�{����"] << "�~\n\n";
	//find �T��
	string key = "�}�[�{����";
	cout << key << "�̒T��\n";
	auto it = price.find(key);
	if (it != price.end()) {
		cout << it->second << "�~�ł�\n";
	}
	else {
		cout << "����܂���\n";
	}
	cout << endl;

#endif
	system("pause>0");
}