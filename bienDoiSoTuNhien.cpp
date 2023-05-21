#include <bits/stdc++.h>
using namespace std;

int solve(int n){
	queue<pair<int,int>> q;
	q.push({n,0});
	set<int> se;
	se.insert(n);
	while(!q.empty()){
		pair<int,int> top = q.front();
		q.pop();
		if(top.first == 2) return top.second+1;
		if(top.first > 1 && !se.count(top.first-1)){
			q.push({top.first-1, top.second+1});
			se.insert(top.first-1);
		}
		for(int i = 2; i <= sqrt(top.first); i++){
			if(top.first%i==0 && !se.count(top.first/i)){
				se.insert(top.first/i);
				q.push({top.first/i, top.second+1});
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << solve(n) << endl;	
	}
	return 0;
}

