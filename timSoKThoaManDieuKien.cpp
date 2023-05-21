#include <bits/stdc++.h>
using namespace std;

vector<int> res;

bool check(int n){
	string s = to_string(n);
	set<char> se;
	for(int i = 0; i < s.size(); i++){
		if(!se.insert(s[i]).second) return false;
		se.insert(s[i]);
	}
	return true;
}

void init(){
	queue<int> q;
	for(int i = 1; i <= 5; i++){
		q.push(i);
		res.push_back(i);
	}
	while(1){
		int u = q.front();
		q.pop();
		if(u > 1e5) return;
		for(int i = 0; i <= 5; i++){
			int tmp = u*10 + i;
			if(check(tmp)){
				q.push(tmp);
				res.push_back(tmp);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	init();
	int t;
	cin >> t;
	while(t--){
		int l, r;
		cin >> l >> r;
		int cnt = 0;
		for(auto x : res){
			if(l <= x && x <= r){
				cnt++;
			}
			if(x > r) break;
		}
		cout << cnt << endl;
	}
	return 0;
}

