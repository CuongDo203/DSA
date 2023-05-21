#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int d;
		cin >> d;
		string s;
		cin >> s;
		map<char, int> mp;
		set<char> se;
		for(int i = 0; i < s.size(); i++){
			mp[s[i]]++;
		}
		int res = 0;
		for(int i = 0; i < s.size(); i++){
			res = max(res, mp[s[i]]);
		}
		if(s.size() - res >= (res-1)*(d-1)){
			cout << "1\n";
		}
		else{
			cout << "-1\n";
		}
	}
	return 0;
}

