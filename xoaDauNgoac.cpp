#include <bits/stdc++.h>
using namespace std;

string s;
set<string> se;
vector<pair<int,int>> res;
int x[1001];

void Dq(int i){
	for(int j = 0; j <= 1; j++){
		x[i] = j;
		if(i == res.size()-1){
			string tmp = s;
			for(int k = 0; k < res.size(); k++){
				if(x[k] == 0){
					tmp[res[k].first] = ' ';
					tmp[res[k].second] = ' ';
				}
			}
			string ans = "";
			for(auto it : tmp){
				if(it != ' '){
					ans += it;
				}
			}
			if(ans != s)
				se.insert(ans);
		}
		else
			Dq(i+1);
	}
}
	
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	stack<char> st;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '('){
			st.push(i);
		}
		else if(s[i] == ')'){
			int v= st.top();
			st.pop();
			res.push_back({v,i});
		}
	}
	Dq(0);
	for(auto x : se){
		cout << x << endl;
	}
	return 0;
}

