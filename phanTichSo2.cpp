#include <bits/stdc++.h>
using namespace std;

int n, a[100];

vector<string> v;

void solve(int n){
	string tmp = "(";
	for(int i = 1; i <= n; i++){
		tmp += to_string(a[i]);
		if(i != n)
			tmp += " ";
		else 
			tmp += ")";
	}
	v.push_back(tmp);
}

void Dq(int x, int i, int s){
	for(int j = x; j >= 1; j--){
		a[i] = j;
		if(j == s) solve(i);
		else if(j < s) Dq(j, i+1, s-j);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		Dq(n,1,n);
		cout << v.size() << endl;
		for(auto x : v){
			cout << x << " ";
		}
		cout << endl;
		memset(a,0,sizeof(a));
		v.clear();
	}
	return 0;
}

