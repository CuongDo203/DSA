#include <bits/stdc++.h>
using namespace std;

int n, x, y, z;
int dp[1001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> n >> x >> y >> z;
		memset(dp,0,sizeof(dp));
		dp[1] = x;
		for(int i = 2; i <= n; i++){
			if(i%2==0){
				dp[i] = min(dp[i-1]+x, dp[i/2] + z);
			}
			else{
				dp[i] = min(dp[i-1]+x, dp[(i+1)/2] + z + y);
			}
		}
		cout << dp[n] << endl;
	}
	return 0;
}

