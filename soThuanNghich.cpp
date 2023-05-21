#include <bits/stdc++.h>
using namespace std;

bool dp[1005][1005];

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
		memset(dp,false,sizeof(dp));
		for(int i = 0; i < n; i++){
			dp[i][i] = true;
		}
		int max_length = 1;
		for(int k = 2; k <= n; k++){
			for(int i = 0; i < n-k+1; i++){
				int j = i + k - 1;
				if(k == 2){
					if(s[i] == s[j]){
						dp[i][j] = true;
					}
					else{
						dp[i][j] = false;
					}
				}
				else{
					if(dp[i+1][j-1] && s[i]==s[j]){
						dp[i][j] = true;
					}
					else{
						dp[i][j] = false;
					}
				}
				if(dp[i][j]){
					max_length = max(max_length, k);
				} 
			}
		}
		cout << max_length << endl; 
	}
	return 0;
}

