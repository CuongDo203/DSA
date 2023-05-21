#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

long long P[1005][1005];

void init(){
	for(int i = 1; i <= 1000; i++){
		P[i][1] = i;
	}
	for(int i = 2; i <= 1000; i++){
		for(int j = 2; j <= i; j++){
			P[i][j] = i*P[i-1][j-1];
			P[i][j] %= mod;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	init();
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		cout << P[n][k] << endl;
	}
	return 0;
}

