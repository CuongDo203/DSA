#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
    	string s;
	    cin >> s;
	    int n = s.size();
	    int dp[n+1][n+1]; 
	    memset(dp,0,sizeof(dp));
	    for(int i = 0; i < n; i++){
	        dp[i][i] = 1;
	    }
	    int ans = 1;
	    for(int len = 2; len <= n; len++){  
	        for(int i = 0; i <= n-len; i++){
	            int j = i+len-1; 
	            if(len==2){
	                if(s[i] == s[j]){
	                    dp[i][j] = 1;
	                }
	                else{
	                    dp[i][j] = 0;
	                }
	            }
	            else{
	                dp[i][j] = (s[i] == s[j]) && (dp[i+1][j-1]);
	            }
	            if(dp[i][j]){
	                ans=max(ans,len);
	            }
	        }
	    }
	    cout << ans << endl;
	}
    return 0;
}
