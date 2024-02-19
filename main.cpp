#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
	//キーがstring,値がintの単価マップ
	unordered_map<string, int> price;

	//データの追加
	price["餃子"] = 100;
	price["ラーメン"] = 200;
	price["チャーハン"] = 300;

	//データの表示
	cout << price["餃子"] << endl;
	cout << price["ラーメン"] << endl;
	cout << price["チャーハン"] << endl;

	system("pause>0");
}