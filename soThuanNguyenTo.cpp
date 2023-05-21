#include <bits/stdc++.h>
using namespace std;

int nt(int n){
	for(int i = 2; i <= sqrt(n); i++){
		if(n%i==0)
			return 0;
	}
	return n > 1;
}

bool check(int n){
	long long sum = 0;
	while(n){
		int cs = n % 10;
		if(!nt(cs))
			return false;
		sum += cs;
		n/=10;
	}
	return nt(sum);
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int l, r;
		cin >> l >> r;
		int cnt  = 0;
		for(int i = l; i <= r; i++){
			if(check(i) && nt(i)){
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
