#include <bits/stdc++.h> 
using namespace std;
typedef long long LL;
const LL P = 1e6+3;

vector < pair<string,string> >p[1000];
vector < pair<string,string> >phone_book;

void input() {
	//freopen("list.txt", "r", stdin);
	string phone_number;
	while (cin >> phone_number){
		string name;
		cin >> name;
		phone_book.push_back(make_pair(name,phone_number));
	}
}
int convert_string(string key) {
	LL answer = 0;
	for (auto i : key) {
	   answer+= int(i);
	}
	return answer;
}

int get_hashkey(LL key) {
	return (key % 997);
}

void insert (string key, string value) {
	LL hash_key = get_hashkey(convert_string(key));
	for (auto i : p[hash_key]) {
		if 	( value == i.second ) {
			return;
		}
	}
	p[hash_key].push_back(make_pair(key,value));
}

void find (string key) {
	LL hash_key = get_hashkey(convert_string(key));
	for (auto i : p[hash_key]) {
		if ( key == i.first ){
			cout <<i.first <<" Number Phone : " << i.second << endl;
		}
	}
}



int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	input();
	for ( auto i : phone_book) {
		insert(i.first, i.second);
	}
	for ( int i = 1; i<= phone_book.size(); i++) {
		cout << i << ". " << phone_book[i-1].first << endl;
	}
                        
	find(phone_book[8].first); //tim du lieu
	
}

