#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(string s, int a){
	ll tmp = 0;
	for(int i = 0; i < s.size(); i++){
		tmp = (tmp * 10 + (s[i] - '0')) % a;
	}
	return tmp == 0;
}

void solve(){
	int n; 
	cin >> n;
	queue<string> q;
	q.push("1");
	while(1){
		string top = q.front();
		q.pop();
		if(check(top, n)){
			cout << top << endl;
			return;
		} 
		q.push(top + "0");
		q.push(top + "1");
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
