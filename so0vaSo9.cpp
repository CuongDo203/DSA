#include <bits/stdc++.h>
using namespace std;

vector<long long> res;
long long ans[101];

void init(){
	queue<long long> q;
	q.push(9);
	while(1){
		long long v = q.front();
		q.pop();
		if(v >= 1e18) 
			break;
		res.push_back(v);
		q.push(v*10);
		q.push(v*10 + 9);
	}
}

void process(){
	for(int i = 1; i <= 100; i++){
		for(auto x : res){
			if(x % i == 0){
				ans[i] = x;
				break;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	init();
	process();
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << ans[n] << endl;
	}
	return 0;
}

