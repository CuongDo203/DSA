#include <bits/stdc++.h>
using namespace std;

int p[1000001];

void sieve(){
	memset(p,1, sizeof(p));
	p[0] = p[1] = 0;
	for(int i = 2; i <= sqrt(1000000); i++){
		if(p[i]){
			for(int j = i*i; j <= 1000000; j+=i){
				p[j] = 0;
			}
		}
	}
}

int main(){
	sieve();
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		bool ok = false;
		for(int i = 2; i <= n/2; i++){
			if(p[i] && p[n-i]){
				cout << i << " " << n - i << endl;
				ok = true;
				break;
			}
		}
		if(!ok){
			cout << "-1\n";
		}
	}
	return 0;
}
