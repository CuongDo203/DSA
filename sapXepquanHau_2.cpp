#include <bits/stdc++.h>
using namespace std;

int x[105], cot[105], xuoi[105], nguoc[105];
int a[101][101];
int n;
long long ans = -1e18;

void Dq(int i){
    for(int j = 1; j <= n; j++){
        if(!cot[j] && !xuoi[n+i-j] && !nguoc[i+j-1]){
            x[i] = j;
            cot[j] = xuoi[n+i-j] = nguoc[i+j-1] = 1;
            if(i == n){
                long long sum = 0;
                for(int k = 1; k <= n; k++){
                    sum += a[k][x[k]];
                }
                ans = max(ans, sum);
            }
            else{
                Dq(i+1);
            }
            cot[j] = xuoi[n+i-j] = nguoc[i+j-1] = 0;
        }
    }
}

int main() { 
	int t;
	cin >> t;
	while(t--){
		n=8;
	    for(int i = 1; i <= n; i++){
	        for(int j = 1; j <= n; j++){
	            cin >> a[i][j];
	        }
	    }
	    Dq(1);
	    cout << ans << endl;
	    ans = -1e18;
	    memset(a,0,sizeof(a));
	    memset(cot,0,sizeof(cot));
	    memset(xuoi, 0, sizeof(xuoi));
	    memset(nguoc, 0 , sizeof(nguoc));
	}
    return 0;
}
