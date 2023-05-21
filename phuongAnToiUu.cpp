#include <bits/stdc++.h>
using namespace std;

int v[101], w[101];
int n, s;
string np, res;

void solve(){
    np = string(n, '0');
    long long ans = -1e18;
    while(1){
        long long value = 0, weight = 0;
        for(int i = 0; i < n; i++){
            if(np[i] == '1'){
                value += v[i];
                weight += w[i];
            }
        }
        if(weight <= s){	
//        	ans = max(ans, value);
        	if(value >= ans){
        		ans = value;
        		res = np;
			}
		}
        int i = n-1;
        while(i >= 0 && np[i] == '1'){
            np[i] = '0';
            i--;
        }
        if(i<0){
            cout << ans << endl;
           	for(int i = 0; i < res.size(); i++){
            	cout << res[i] << " ";
			}
			cout << endl;
            return;
        }
        else{
            np[i] = '1';
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> n >> s;
    for(int i = 0; i < n; i++){  // nhap gia tri  
        cin >> v[i];
    }
    for(int i = 0; i < n; i++){  //nhap khoi luong
        cin >> w[i];
    }
    solve();
	memset(v, 0, sizeof(v));
    memset(w,0,sizeof(w));
    return 0;
}

