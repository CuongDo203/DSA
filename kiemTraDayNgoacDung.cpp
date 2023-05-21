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
		stack<char> st;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '{' || s[i] == '(' || s[i] == '['){
				st.push(s[i]);
			}
			else{
				if(!st.empty()){
					if(s[i] == ')' && st.top() == '('){
						st.pop();
					}
					else if(s[i] == ']' && st.top() == '['){
						st.pop();
					}	
					else if(s[i] == '}' && st.top() == '{'){
						st.pop();
					}
				}
			}
		}
		if(st.empty()){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}

