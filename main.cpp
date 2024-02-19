#include<iostream>
#include<unordered_map>
using namespace std;

//pair表示
template<typename T1, typename T2>
ostream& operator<<(ostream& s, const pair<T1, T2>& d) {
	return s << d.first << ":" << d.second;
}
//全要素表示
template <class C>
void show(const C& data) {
	for (const auto& d : data)
		cout << d << "\n";
	cout << "\n";
}

//メイン
int main() {
#if 1
	//「商品コード」と「商品名、単価」のメニューマップ
	unordered_map< string, pair<string, int> > menu;
	//データ構築
	menu["a"] = { "餃子",100 };
	menu["b"] = { "ラーメン",200 };
	menu["c"] = { "チャーハン",300 };
	menu.emplace("d", make_pair("エビマヨ", 400));
	//全データ表示
	show(menu);

#else
	//売上データ
	struct SALE { string code; int num; };
	list<SALE>sales{ {"a",10},{"b",20},{"c",30},{"d",40} };
	for (const auto& sale : sales) {
		auto [name, price] = menu[sale.code];
		cout << name << ":" << price * sale.num << endl;
	}
#endif
	system("pause>0");
}