#include <bits/stdc++.h>
using namespace std;

int dp[1005];

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
		dp[i]=1;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			if(a[i] > a[j])
				dp[i] = max(dp[i], dp[j]+1);
		}
	}	
	cout << *max_element(dp, dp+n);  
	return 0;
}
