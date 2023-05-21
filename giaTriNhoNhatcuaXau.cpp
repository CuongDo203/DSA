#include <bits/stdc++.h>
using namespace std;

int main() {  
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int t;
    cin >> t;
    while(t--){
    	int k;
	    cin >> k;
	    string s;
	    cin >> s;
		int c[26] = {0};
	    for(int i = 0; i < s.size(); i++){
	        c[s[i]-'A']++;
	    }
	    priority_queue<int> q;
	    for(auto it : c){
	        q.push(it);
	    }
	    while(k--){
	        int t = q.top();
	        q.pop();
	        --t;
	        q.push(max(t,0));
	    }
	    long long ans = 0;
	    while(!q.empty()){
	        ans += 1ll*q.top()*q.top();
	        q.pop();
	    }
	    cout << ans << endl;
	}
    return 0;
}

