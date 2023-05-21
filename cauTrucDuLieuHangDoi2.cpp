#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	queue<int> q;
	while(t--){
		string s;
		cin >> s;
		if(s == "PUSH"){
			int x; cin >> x;
			q.push(x);
		}
		else if(s == "POP"){
			if(!q.empty()) q.pop();
		}
		else{
			if(q.empty()) cout << "NONE\n";
			else cout << q.front() << endl;
		}
	}
	return 0;
}

