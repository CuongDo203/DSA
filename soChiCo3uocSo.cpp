#include <bits/stdc++.h>
using namespace std;

int a[1000001];

void sieve(){
	for(int i = 0; i <= 1000000; i++){
		a[i] = 1;
	}
	a[0] = a[1] = 0;
	for(int i = 2; i <= sqrt(1000000); i++){
		if(a[i]){
			for(int j = i*i; j <= 1000000; j+=i){
				a[j] = 0;
			}
		}
	}
}

int main(){
	sieve();
	int t;
	cin >> t;
	while(t--){
		long long l, r;
		cin >> l >> r;
		long long cnt = 0;
		int x = sqrt(l);
		int y = sqrt(r);
		for(int i = x; i <= y; i++){
			if(a[i]){
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
