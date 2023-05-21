#include <bits/stdc++.h>
using namespace std;
vector<long long> a, b;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 0; i < n; i++){
			long long x;
			cin >> x;
			a.push_back(x);
		}
		for(int i = 0; i < n; i++){
			long long x;
			cin >> x;
			b.push_back(x);
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end(), greater<long long>());
		long long ans = 0;
		for(int i = 0; i < n; i++){
			ans += a[i]*b[i];
		}
		cout << ans << endl;
		a.clear();
		b.clear();
	}
	return 0;
}

