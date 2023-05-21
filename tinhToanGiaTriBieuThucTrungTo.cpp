#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int pri(char c){
	if(c == '/' || c == '*') return 2;
	else if(c == '+' || c == '-') return 1;
	return 0;
} 

ll tinh(ll a, ll b, char c){
	if(c == '+') return a+b;
	else if(c == '-') return a-b;
	else if(c == '*') return a*b;
	else return a/b;
}

void solve(string s){
	stack<char> st1;
	stack<ll> st2;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '('){
			st1.push('(');
		}
		else if(isalnum(s[i])){
			ll tmp = 0;
			while(i < s.size() && isalnum(s[i])){
				tmp = tmp*10 + (s[i]-'0');
				i++;
			}
			--i;
			st2.push(tmp);
		}
		else if(s[i] == ')'){
			while(!st1.empty() && st1.top() != '('){
				ll so1 = st2.top(); st2.pop();
				ll so2 = st2.top(); st2.pop();
				st2.push(tinh(so2,so1,st1.top()));
				st1.pop();
			}
			if(!st1.empty())
				st1.pop();
		}
		else{
			while(!st1.empty() && pri(s[i])<=pri(st1.top())){
				ll so1 = st2.top(); st2.pop();
				ll so2 = st2.top(); st2.pop();
				st2.push(tinh(so2, so1, st1.top()));
				st1.pop();
			}
			st1.push(s[i]);
		}
	}
	while(!st1.empty() && st2.size() >= 2){
		ll so1 = st2.top(); st2.pop();
		ll so2 = st2.top(); st2.pop();
		st2.push(tinh(so2, so1, st1.top()));
		st1.pop();
	}
	cout << st2.top() << endl;
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
		solve(s);
	}
	return 0;
}

