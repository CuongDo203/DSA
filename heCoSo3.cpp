#include <bits/stdc++.h>
using namespace std;

bool check(string s){
	for(int i = 0; i < s.size(); i++){
		if(s[i] != '0' && s[i] != '1' && s[i] != '2')
			return false;
	}
	return true;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		if(check(s))
			cout << "YES\n";
		else{
			cout << "NO\n";
		}
	}
	return 0;
}
