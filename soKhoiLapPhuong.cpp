#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int x[100001];
string s;
priority_queue<ll> pq;

void Dq(int i, int n){
	for(int j = 1; j >= 0; j--){
		x[i] = j;
		if(i == n-1){
			string res = "";
			for(int k = 0; k < n; k++){
				if(x[k] == 1){
					res += s[k];
				}
			}
			if(res.size())
				pq.push(stoll(res));
		}
		else
			Dq(i+1, n);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> s;
		map<ll,int> mp;
		for(int i = 0; i <= 100; i++){
			mp[1ll*i*i*i] = 1;
		}	
		int n = s.size();
		Dq(0,n);
		bool ok = false;
		while(!pq.empty()){
			ll top = pq.top();
			pq.pop();
			if(mp[top]){
				cout << top << endl;
				ok = true;
				break;
			}
		}
		if(!ok){
			cout << "-1\n";
		}
		while(!pq.empty()){
			pq.pop();
		}
	}
	return 0;
}

