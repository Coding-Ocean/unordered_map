#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
	//�L�[��string,�l��int�̒P���}�b�v
	unordered_map<string, int> price;

	//�f�[�^�̒ǉ�
	price["�L�q"] = 100;
	price["���[����"] = 200;
	price["�`���[�n��"] = 300;

	//�f�[�^�̕\��
	cout << price["�L�q"] << endl;
	cout << price["���[����"] << endl;
	cout << price["�`���[�n��"] << endl;

	system("pause>0");
}