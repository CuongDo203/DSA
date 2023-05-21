#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n+1], dp1[n+5], dp2[n+5];
		memset(dp1,0,sizeof(dp1));
		memset(dp2,0,sizeof(dp2));
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			dp1[i] = dp2[i] = 1;
		}
		for(int i = 1; i <= n; i++){
			if(a[i]>a[i-1])
				dp1[i] = dp1[i-1]+1;
		}
		for(int i = n; i >= 1; i--){
			if(a[i]>a[i+1]){
				dp2[i] = dp2[i+1]+1;
			}
		}
		int ans = 0;
		for(int i = 1; i <= n; i++){
			ans = max(ans, dp1[i]+dp2[i]-1);
		}
		cout << ans << endl;
	}
	return 0;
}

