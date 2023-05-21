#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;


void solve(int s, int t){
	queue<pii> q;
	set<int> se;
	q.push({s,0});
	se.insert(s);
	while(!q.empty()){
		pii top = q.front();
		q.pop();
		if(top.first == t){
			cout << top.second << endl;
			return;
		}
		if(top.first > 1 && !se.count(top.first - 1)){
			q.push({top.first - 1, top.second + 1});
			se.insert(top.first - 1);
		}
		if(top.first < t && !se.count(top.first * 2)){
			q.push({top.first * 2, top.second + 1});
			se.insert(top.first * 2);
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
		int a, b;
		cin >> a >> b;
		solve(a, b);
	}
	return 0;
}

