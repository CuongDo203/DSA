#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

long long Pow(int n, int k){
	if(k==0){
		return 1;
	}
	long long tmp = Pow(n,k/2)%mod;
	if(k%2==1){
		return ((tmp*tmp)%mod*n%mod)%mod;
	}
	else{
		return (tmp*tmp)%mod;
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		cout << Pow(n,k) << endl;
	}
	return 0;
}
