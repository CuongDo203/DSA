#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;

ll C[1001][1001];   //to hop chap j cua i

void gene(){
	for(int i = 0; i <= 1000; i++){
		for(int j = 0; j <= i; j++){
			if(j == 0 || j == i)
				C[i][j] = 1;
			else{
				C[i][j] = C[i-1][j-1] + C[i-1][j];
				C[i][j] %= mod;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	gene();
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		cout << C[n][k] << endl;
	}
	return 0;
} 
