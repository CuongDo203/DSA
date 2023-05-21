#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n, s;
		cin >> n >> s;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		vector<bool> dp(s+1, false);
		dp[0] = true;
		for(int i = 0; i < n; i++){
			for(int j = s; j >= a[i]; j--){
				if(dp[j-a[i]]){
					dp[j] = true;
				}
			}
		}
		if(dp[s]){
			cout << "YES";
		}
		else{
			cout << "NO";
		}
		cout << endl;
	}
	return 0;
} 
