#include <bits/stdc++.h>
using namespace std;

int n;
int dp[10005];

void solve(){
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for(int i = 4; i <= 10000; i++){
		dp[i] = i;
		for(int j = 1; j <= sqrt(i); j++){
			dp[i] = min(dp[i], dp[i-j*j]+1);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	solve();
	while(t--){
		cin >> n;
		cout << dp[n] << endl;
	}
	return 0;
}

