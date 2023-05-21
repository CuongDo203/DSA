#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin >> t;
	while(t--){
		long long n, k;
		cin >> n >> k;
		long long a[n];
		map<long long, int> mp;
		mp[0] = 1;
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		long long sum = 0;
		bool ok = false;
		for(int i = 0; i < n; i++){
			sum += a[i];
			if(mp[sum-k]){
				ok = true;
				break;
			}
			mp[sum]++;
		}
		if(!ok) cout << "NO\n";
		else cout << "YES\n";
		mp.clear();
	}
	return 0;
}
