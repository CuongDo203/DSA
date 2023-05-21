#include <bits/stdc++.h>
using namespace std;

long long a[1000008], dp[1000008];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		dp[1] = a[1];
		dp[2] = max(dp[1], a[2]);
		for(int i = 3; i <= n; i++){
			dp[i] = max(dp[i-1], dp[i-2]+a[i]);
		}
		cout << dp[n] << endl;
	}
	return 0;
}

