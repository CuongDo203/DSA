#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, k;

const int mod = 1e9+7;
struct matrix{
    ll a[20][20];
    matrix operator * (matrix b){       //nap chong toan tu nhan 2 ma tran cap 2x2
        matrix res;
        for(int i = 0; i < n; i++){
            for(int j =0 ; j < n; j++){
                res.a[i][j] = 0;
                for(int k = 0; k < n; k++){
                    res.a[i][j] += a[i][k] * b.a[k][j];
                    res.a[i][j] %= mod;
                }
            }
        }
        return res;
    }
};

matrix Pow(matrix a, ll n){
	if(n==1) return a;
	matrix tmp = Pow(a,n/2);
	if(n%2==1)
		return tmp*tmp*a;
	else
		return tmp*tmp;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		matrix res;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> res.a[i][j];
			}
		}
		matrix ans = Pow(res, k);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << ans.a[i][j] << " ";
			}
			cout << endl;
		}
	} 
	return 0;
}

