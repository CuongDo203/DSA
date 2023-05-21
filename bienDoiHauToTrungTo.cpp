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
		stack<string> st;
		for(int i = 0; i < s.size(); i++){
			if(isalpha(s[i])){
				st.push(string(1, s[i]));
			}
			else{
				string t1 = st.top(); st.pop();
				string t2 = st.top(); st.pop();
				string res = "(" + t2 + s[i] + t1 + ")";
				st.push(res);
			}
		}
		cout << st.top() << endl;
	}	
	return 0;
}

