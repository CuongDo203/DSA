#include <bits/stdc++.h>
using namespace std;

long long dp[1001][1001];  //dp[i][j]:gia tri lon nhat cua cai tui co trong luong j khi chon do vat tu 1 den i

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n, v;
		cin >> n >> v;
		int w[n+1], b[n+1];
		for(int i = 1; i <= n; i++){
			cin >> w[i];
		}
		for(int i = 1; i <= n; i++){
			cin >> b[i];
		}
		for(int i = 1; i <= n; i++){
			for(int j = 0; j <= v; j++){ //xet cac kha nang tui mang duoc
				dp[i][j] = dp[i-1][j];
				if(j >= w[i]){
					dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + b[i]);
				}
			}
		}
		cout << dp[n][v] << endl;
		memset(dp,0,sizeof(dp));
	}
	return 0;
}

