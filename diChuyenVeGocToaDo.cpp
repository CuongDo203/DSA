#include <bits/stdc++.h>
using namespace std;

long long dp[101][101];

void init(){
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= 100; i++){
		for(int j = 1; j <= 100; j++){
			dp[i][j] += dp[i-1][j] + dp[i][j-1]+1;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	init();
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		cout << dp[n][m]+1 << endl;
	}
	return 0;
}

