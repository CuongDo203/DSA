#include <bits/stdc++.h>
using namespace std;

set<char> se;

void solve(string s){
	for(int i = 0; i < s.size(); i++){
		se.insert(s[i]);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
    	int n;
    	cin >> n;
    	for(int i = 0; i < n; i++){
    		string s;
    		cin >> s;
    		solve(s);
		}
		for(auto it : se){
			cout << it << " ";
		}
		cout << endl;
		se.clear();
	}
	return 0;
}
