#include <bits/stdc++.h>
using namespace std;

vector<string> res;

void init(){
	queue<string> q;
	q.push("1");
	while(1){
		string v = q.front();
		q.pop();
		res.push_back(v);
		if(res.size() == 10001) break;
		q.push(v+"0");
		q.push(v+"1");
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	init();
	while(t--){
		int n;
		cin >> n;
		for(int i = 0; i < n; i++){
			cout << res[i] << ' ';
		}
		cout << endl;
	} 
	return 0;
}

