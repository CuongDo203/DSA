#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int cnt[256] = {0};
		for(auto x : s){
			cnt[x-'A']++;
		}
		for(int i = 0; i < s.size(); i++){
			if(cnt[s[i]-'A']){
				cout << s[i] << cnt[s[i]-'A'];
				cnt[s[i]-'A']=0;
			}
		}
		cout << endl;
	}
	return 0;
}
