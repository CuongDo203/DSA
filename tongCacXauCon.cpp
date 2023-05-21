#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n = s.size();
		ll dp[n+1];
		memset(dp,0,sizeof(dp));
		dp[1] = s[0] - '0';
		long long u = 0;
		long long res = dp[1];
		for(int i = 2; i <= n; i++){
			u = (dp[i-1]-dp[i-2])*10 + (s[i-1]-'0')*i;
			dp[i] = dp[i-1] + u;
			res += u;
		}
		cout << dp[n] << endl;
	}
	return 0;
}

