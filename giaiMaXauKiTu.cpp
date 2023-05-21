#include <bits/stdc++.h>
using namespace std;

bool isNum(string s){
	return (s == "0" || s == "1" || s == "2" || s == "3" || s == "4" || 
			s == "5" || s == "6" || s == "7" || s == "8" || s == "9");
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
		for(auto c : s){
			if(c != ']'){
				st.push(string(1,c));
			}
			else{
				string res = "";
				while(!st.empty() && st.top() != "["){
					res = st.top() + res;
					st.pop();
				}
				st.pop();
				string so = "";
				while(!st.empty() && isNum(st.top())){
					so = st.top() + so;
					st.pop();
				}
				if(so == ""){
					st.push(res);
				}
				else{
					string tmp = "";
					for(int i = 1; i <= stoi(so); i++){
						tmp += res;
					}
					st.push(tmp);
				}
			}
		}
		string ans = "";
		while(!st.empty()){
			ans = st.top() + ans;
			st.pop();
		}
		cout << ans << endl;
	}
	return 0;
}

