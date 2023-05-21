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
		int a[n+1];
		int dp1[n+1], dp2[n+1];
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(int i = 1; i <= n; i++){
			dp1[i] = a[i];
			for(int j = 1; j < i; j++){
				if(a[i] > a[j]){
					dp1[i] = max(dp1[i], dp1[j]+a[i]);
				}
			}
		}
		for(int i = n; i >= 1; i--){
			dp2[i] = a[i];
			for(int j = n; j > i; j--){
				if(a[i] > a[j]){
					dp2[i] = max(dp2[i], dp2[j]+a[i]);
				}
			}
		}
		int maxx = -1e9;
		for(int i = 1; i <= n; i++){
			maxx = max(maxx, dp1[i]+dp2[i]-a[i]);
		} 
		cout << maxx << endl;
	}
	return 0;
}

