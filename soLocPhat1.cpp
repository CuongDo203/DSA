#include <bits/stdc++.h>
using namespace std;
stack<string> st;
void solve(int n){
	queue<string> q;
	q.push("6");
	q.push("8");
	while(1){
		string top = q.front();
		q.pop();
		if(top.size() > n) break;
		st.push(top);
		q.push(top + "6");
		q.push(top + "8");
	}
	while(!st.empty()){
		cout << st.top() << " ";
		st.pop();
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

