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
		vector<pair<int,int>> v(n);
		int dp[n];
		for(int i = 0; i < n; i++){
			cin >> v[i].first >> v[i].second;
			dp[i] = 1;
		}
		sort(v.begin(), v.end());
		for(int i = 0; i < n; i++){
			for(int j = 0; j < i; j++){
				if(v[i].first > v[j].second){
					dp[i] = max(dp[i], dp[j]+1);
				}
			}
		}
		cout << *max_element(dp, dp+n) << endl;
	}	
	return 0;
}

