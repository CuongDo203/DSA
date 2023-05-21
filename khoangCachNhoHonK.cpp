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
		long long a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a, a+n);
		int ans = 0;
		for(int i = 0; i < n; i++){
			auto it = lower_bound(a+i+1, a+n, a[i]+k);
			--it;
			int idx = it - a;
			ans += idx - i;
		}
		cout << ans << endl;
	}	
	return 0;
}

