#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	cin.ignore();
	while(t--){
		string s;
		getline(cin,s);
		char a = s[0];
		char b = s[4];
		char c = s[8];
		if((a-'0')+(b-'0')==c-'0'){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
} 
