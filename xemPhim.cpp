#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c, n;
	cin >> c >> n;
	int a[n];
    for(auto &x : a) cin >> x;
    long long dp[c+1];
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = c; j >= a[i]; j--){
            if(dp[j-a[i]]){
                dp[j] = 1;
            }
        }
    }
    for(int j = c; j >= 1; j--){
        if(dp[j]){
            cout << j << endl;
            return 0;
        }
    }
	return 0;
}

