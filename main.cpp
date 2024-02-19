#include<iostream>
#include<unordered_map>
using namespace std;

//pair型表示用、挿入演算子のオーバーロード
template<typename T1, typename T2>
ostream& operator<<(ostream& s, const pair<T1, T2>& p) {
	return s << p.first << ":" << p.second;
}

//どのコンテナもこれで全部表示できる
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
	//キーがstring,値がintの単価マップ
	unordered_map<string, int> price;
	//insertによるデータの追加
	price.insert(make_pair("餃子", 100));
	show(price);
#else
	//emplaceによるデータの追加
	price.emplace("ラーメン", 200);
	//［］によるデータの追加
	price["チャーハン"] = 300;
	//重複したキーを指定すると、データは更新となる
	price["餃子"] = 150;
	//キーに対応するデータの表示
	cout << price["餃子"] << "円\n\n";
	//キーが登録されていないデータを表示すると０円データとして追加される
	cout << price["マーボ豆腐"] << "円\n\n";
	//find 探索
	string key = "マーボ豆腐";
	cout << key << "の探索\n";
	auto it = price.find(key);
	if (it != price.end()) {
		cout << it->second << "円です\n";
	}
	else {
		cout << "ありません\n";
	}
	cout << endl;

#endif
	system("pause>0");
}