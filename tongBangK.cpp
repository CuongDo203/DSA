#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int dp[1005], a[1005];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		memset(dp,0,sizeof(dp));
		int n, k;
		cin >> n >> k;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		
		dp[0] = 1;
		for(int i = 1; i <= k; i++){
			for(int j = 1; j <= n; j++){
				if(a[j] <= i){
					dp[i] += dp[i-a[j]];
					dp[i] %= mod;
				}
			}
		}
		cout << dp[k] << endl;
	} 
	return 0;
}

