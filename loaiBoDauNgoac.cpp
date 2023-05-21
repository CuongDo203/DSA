#include <bits/stdc++.h>
using namespace std;

string s;
int len;
set<string> se;

bool check(string s) {
    if (s.length() < 2)
        return false;
    stack<int> st;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(')
            st.push(1);
        else if (s[i] == ')') {
            if (st.empty())
                return false;
            st.pop();
        }
    }
    return st.empty();
}

void Dq(int pos, string s){
	if(s.size() < len){
		return;
	}
	if(check(s)){
		if(s.size() > len){
			len = s.size();
			se.clear();
		}
		se.insert(s);
		return;
	}
	for(int i = pos; i < s.size(); i++){
		if(s[i] == '(' || s[i] == ')'){
			string tmp = s;
			tmp.erase(i,1);
			Dq(i, tmp);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> s;
		len = 0;
		se.clear();
		Dq(0,s);
		//cout << len << endl;
		if(se.empty()) {
			cout << "-1\n";
		}
		else{
			for(auto it : se){
				cout << it << " ";
			}
			cout << endl;
		}
	}
	return 0;
}

