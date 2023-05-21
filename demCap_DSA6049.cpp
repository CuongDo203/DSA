#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		long long cnt = 0;
		sort(a,a+n);
		for(int i = 0; i < n; i++){
			auto it = lower_bound(a+i+1, a+n, k+a[i]);
			--it;
			cnt += it - (a+i);
		}
		cout << cnt << endl;
	}
	return 0;
}
