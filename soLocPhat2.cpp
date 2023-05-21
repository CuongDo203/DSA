#include <bits/stdc++.h>
using namespace std;

vector<string> res;

void solve(int n){
	res.clear();	
	queue<string> q;
	q.push("6");
	q.push("8");
	while(1){
		string top = q.front();
		q.pop();
		if(top.size() > n){
			break;
		} 
		res.push_back(top);
		q.push(top + "6");
		q.push(top + "8");
	}
	cout << res.size() << endl;
	for(auto x : res){
		cout << x << " ";
	}
	cout << endl;
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
		solve(n);
	}	
	return 0;
}

