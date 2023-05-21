#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;

struct matrix{
    ll a[2][2];
    matrix operator * (matrix b){
        matrix res;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                res.a[i][j] = 0;
                for(int k = 0; k < 2; k++){
                    res.a[i][j] += a[i][k] * b.a[k][j];
                    res.a[i][j] %= mod;
                }
            }
        }
        return res;
    }
};

matrix Pow(matrix a, ll n){
    if(n == 1){
        return a;
    }
    matrix tmp = Pow(a,n/2);
    if(n%2==1)
        return tmp*tmp*a;
    else
        return tmp*tmp;
}

int main() {  
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		ll n;
	    cin >> n;
	    matrix F;
	    F.a[0][0] = 1;
	    F.a[0][1] = 1;
	    F.a[1][0] = 1;
	    F.a[1][1] = 0;
	    matrix res = Pow(F,n);
	    cout << res.a[0][1] << endl;
	} 
    return 0;
}

