#include <bits/stdc++.h>
using namespace std;

bool isSign(string s){
	return (s == "+" || s=="-");
}

string handle(string s){
	stack<string> st;
	for(auto c : s){
		if(c != ')'){
			st.push(string(1, c));
		}
		else{
			string res = "";
			while(!st.empty() && st.top() != "("){
				res = st.top() + res;
				st.pop();
			}
			st.pop();
			string tmp = "";
			while(!st.empty() && isSign(st.top())){
				tmp+=st.top();
				st.pop();
			}
			if(tmp == ""){
				st.push(res);
			}
			else{
				if(tmp=="-"){
					for(int i = 0; i < res.size(); i++){
						if(res[i] == '+') res[i] = '-'; 
						else if(res[i] == '-') res[i] = '+';
					}
				}
				res = tmp+res;
				st.push(res);
			}
		}
	}
	string ans = "";
	while(!st.empty()){
		ans = st.top() + ans;
		st.pop();
	}
	return ans;
}  

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		string a, b;
		cin >> a >> b;
		a = handle(a);
		b = handle(b);
		if(a==b) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}

