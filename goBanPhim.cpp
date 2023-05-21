#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	string res = "";
	stack<char> st;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '-'){
			if(!res.empty()){
				res.pop_back();
			}
		}
		else if(s[i] == '<'){
			if(!res.empty()){
				st.push(res.back());
				res.pop_back();
			}
		}
		else if(s[i] == '>'){
			if(!st.empty()){
				res += st.top();
				st.pop();
			}
		}
		else{
			res += s[i];
		}
	}
	while(!st.empty()){
		res += st.top();
		st.pop();
	}
	cout << res << endl;
	return 0;
}

