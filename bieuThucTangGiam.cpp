#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n = s.size();
		stack<int> st;
		for(int i = 0; i <= n; i++){
			st.push(i+1);
			if(s[i] == 'I' || i == n){
				while(!st.empty()){
					cout << st.top();
					st.pop();
				}
			}
		}
		cout << endl;
	}
	return 0;
}

