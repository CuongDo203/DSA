#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> res;

void init(){
	queue<ll> q;
	q.push(1);
	while(1){
		ll top = q.front();
		q.pop();
		res.push_back(top);
		if(top >= 1e18){
			break;
		} 
		q.push(top*10);
		q.push(top*10 + 1);
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
		ll n;
		cin >> n;
		int cnt = 0;
		for(ll x : res){
			if(x <= n){
				cnt++;
			}
			else break;
		}
		cout << cnt << endl;
	}	
	return 0;
}

