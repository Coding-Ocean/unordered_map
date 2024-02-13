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
	//キーがstring,値がintの単価マップ
	unordered_map<string, int> price;
	//データの追加
	price["餃子"] = 100;
	price["ラーメン"] = 200;
	price["チャーハン"] = 300;
	//データの探索と表示
	cout << price["ラーメン"] << "円です。\n";
	cout << endl;

	//キーがint,値がstringのメニューマップ
	unordered_map<int, string> menu;
	//データの追加
	menu.emplace(1,"餃子");
	menu.emplace(2,"ラーメン");
	menu.emplace(3,"チャーハン");
	//データの探索と表示
	cout << menu[3] << "です。\n";
	cout << endl;

	//テンプレート構造体"pair"の説明
	pair<int, string> Pair;
	//上記の書き方で次の構造体が出来上がる
	//  struct pair {
	//    int first;
	//    string second;
	//  }Pair;
	Pair = { 48,"AKB" };
	cout << Pair.first << ":" << Pair.second << endl;
	cout << endl;

	//find 探索
	int key = 48;
	auto it = menu.find(key);
	if (it != menu.end()) {
		//イテレータはpairを指す
		cout << it->first << ":" << it->second << "\n";
	}
	else {
		cout << key << ":not found\n";
	}
	find(menu, 3);
	find(menu, 4);
	cout << endl;
	find(price, "餃子");
	find(price, "えびまよ");
	cout << endl;

	//全データ表示
	show(menu);
	show(price);

	cin.get();
}