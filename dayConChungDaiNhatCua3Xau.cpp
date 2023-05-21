#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n, m, k;
		cin >> n >> m >> k;
		string s1, s2, s3;
		cin >> s1 >> s2 >> s3;
		int dp[n+1][m+1][k+1];
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= m; j++){
				for(int z = 0; z <= k; z++){
					if(i==0 || j == 0 || z == 0){
						dp[i][j][z] = 0;
					}
					else{
						if(s1[i-1] == s2[j-1] && s1[i-1] == s3[z-1]){
							dp[i][j][z] = dp[i-1][j-1][z-1] + 1;
						}
						else{
							dp[i][j][z] = max({dp[i-1][j][z], dp[i][j-1][z], dp[i][j][z-1]});
						}
					}
				}
			}
		}
		cout << dp[n][m][k] << endl;
	}
	return 0;
}

