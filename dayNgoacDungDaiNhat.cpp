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
		for (int i = 0; i < s.length(); ++i) {
	        if (s[i] == ')' && !st.empty() && st.top() == '(') {
	            st.pop();
	        }
	        else st.push(s[i]);
	    }
	    cout << s.size() - st.size() << endl;
	}	
	return 0;
}

