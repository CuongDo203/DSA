#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;
int n;

struct matrix{
	ll a[15][15];
	matrix operator * (matrix b){
		matrix res;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
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

matrix Pow(matrix a, int b){
	if(b==1)
		return a;
	matrix tmp = Pow(a,b/2);
	if(b%2==1){
		return tmp*tmp*a;
	}
	else{
		return tmp*tmp;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int k;
		cin >> n >> k;
		matrix res;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> res.a[i][j];
			}
		}
		matrix ans = Pow(res,k);
		ll sum = 0;
		for(int i = 0; i < n; i++){
			sum += ans.a[i][n-1];
			sum%=mod;
		}
		cout << sum << endl;
	} 
	return 0;
}
