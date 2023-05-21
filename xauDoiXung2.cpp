#include <bits/stdc++.h>
using namespace std;

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
		int dp[n+1][n+1];
		memset(dp,0,sizeof(dp));
		for(int i = n-2; i >= 0; i--){
			for(int j = i+1; j < n; j++){
				if(s[i] == s[j]){
					dp[i][j] = dp[i+1][j-1];
				}
				else{
					dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1;
				}
			}
		}
		cout << dp[0][n-1] << endl;
	}
	return 0;
}


