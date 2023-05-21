#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
using ll = long long;

ll Pow(ll a, ll b){
	if(b == 0){
		return 1;
	}
	ll x = Pow(a,b/2)%mod;
	if(b%2==1){
		return ((x*x)%mod*(a%mod))%mod;
	}
	else{
		return (x*x)%mod;
	}
}

int main(){
	while(1){
		ll a, b;
		cin >> a >> b;
		if(a==0 && b==0){
			break;
		}
		else{
			cout << Pow(a,b) << endl;
		}
	}
	return 0;
}
