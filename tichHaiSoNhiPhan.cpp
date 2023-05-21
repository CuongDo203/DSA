#include <bits/stdc++.h>
using namespace std;

void solve(string a, string b){
	long long x = 0;
	long long y = 0;
	for(int i = 0; i < a.size(); i++){
		x = x*2 + (a[i]-'0');
	}
	for(int i = 0; i < b.size(); i++){
		y = y*2 + (b[i]-'0');
	}
	long long ans = x*y;
	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		string a, b;
		cin >> a >> b;
		solve(a,b);
	}
	return 0;
}

