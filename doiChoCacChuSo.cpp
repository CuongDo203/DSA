#include <bits/stdc++.h>
using namespace std;

int k;

void solve(string &s){    
	for(int i = 0; i < s.size(); i++){
		char maxx = s[s.size()-1];
		int idx = s.size()-1;
		for(int j = s.size()-1; j > i && k > 0; j--){
			if(maxx < s[j]){ 
				maxx = s[j];
				idx=j;
			}
		}
		if(k > 0 && maxx > s[i]){
			swap(s[i], s[idx]);
			k--;
		}
	}
	cout << s << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> k;
		string s;
		cin >> s;
		solve(s);
	} 
	return 0;
}

