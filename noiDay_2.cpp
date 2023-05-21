#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		priority_queue<ll, vector<ll> , greater<ll>> q;
		for(int i = 0; i < n; i++){
			ll x;
			cin >> x;
			q.push(x);
		}
		long long cost = 0;
		while(q.size() > 1){
			ll a = q.top();
			q.pop();
			ll b = q.top();
			q.pop();
			cost = (cost%mod+(a+b)%mod)%mod;
			q.push((a+b)%mod);
		}
		cout << cost << endl;
	} 
	return 0;
}

