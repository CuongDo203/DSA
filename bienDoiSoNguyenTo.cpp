#include <bits/stdc++.h>
using namespace std;

int p[10001];

void sieve(){
	for(int i = 1; i <= 10000; i++){
		p[i] = 1;
	}
	p[0] = p[1] = 0;
	for(int i = 2; i <= sqrt(10000); i++){
		for(int j = i*i; j <= 10000; j+=i){
			if(p[j]) p[j] = 0;
		}
	}
}

void solve(int a, int b){
	queue<pair<int,int>>q;
	q.push({a,0});
	set<int> se;
	se.insert(a);
	while(!q.empty()){
		pair<int, int> top = q.front();
		q.pop();
		if(top.first == b){
			cout << top.second << endl;
			return;
		}
		string tmp = to_string(top.first);
		for(int i = 0; i < 4; i++){
			char c = tmp[i];
			for(char j = '0'; j <= '9'; j++){
				if(tmp[i] != j){
					tmp[i] = j;
					int val = stoi(tmp);
					if(val >= 1000 && p[val] && !se.count(val)){
						q.push({val, top.second+1});
						se.insert(val);
					}
				}
			}
			tmp[i] = c;
		}
	}	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	sieve();
	while(t--){
		int a, b;
		cin >> a >> b;
		solve(a,b);
	}	
	return 0;
}

