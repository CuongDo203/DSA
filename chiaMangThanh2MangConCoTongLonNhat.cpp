#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		long long s1 = 0, s2 = 0;
		int pos = min(k, n-k);
		sort(a, a+n);
		for(int i = 0; i < pos; i++){
			s1 += a[i];
		}
		for(int i = pos; i < n; i++){
			s2 += a[i];
		}
		cout << s2 - s1 << endl;
	}
	return 0;
}
