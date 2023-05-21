#include <bits/stdc++.h>
using namespace std;

bool check(string s){
	stack<char> st;
	for(char c : s){
		if(c != ')'){
			st.push(c);
		}
		else{
			bool du = 1;
			while(st.top() != '('){
				char x = st.top();
				if(x == '+' || x == '-' || x == '*' || x == '/'){
					du = 0;
				}
				st.pop();
			}
			st.pop();
			if(du) return 1;
		}	
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		if(check(s)) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}

