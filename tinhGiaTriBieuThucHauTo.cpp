#include <bits/stdc++.h>
using namespace std;

int cal(int a, int b, char c){
	if(c == '+') return a + b;
	if(c == '-') return a - b;
	if(c == '*') return a * b;
	return a / b;
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
		stack<string> st;
		for(int i = 0; i < s.size(); i++){
			if(isalnum(s[i])){
				st.push(string(1, s[i]));
			}
			else{
				int t1 = stoi(st.top());
				st.pop();
				int t2 = stoi(st.top());
				st.pop();
				int res = cal(t2,t1, s[i]);
				st.push(to_string(res));
			}
		}
		cout << st.top() << endl;
	}	
	return 0;
}

