#include <bits/stdc++.h>
using namespace std;
const int mod = 123456789;
long long Pow(long long n, long long k){
	if(k==0)
		return 1;
	long long x = Pow(n,k/2)%mod;
	if(k%2==1){
		return ((x*x)%mod*(n%mod))%mod;
	}
	else{
		return (x*x)%mod; 
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		long long n;
		cin >> n;
		cout << Pow(2,n-1) << endl;
	}
	return 0;
}
