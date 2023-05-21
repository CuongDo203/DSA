#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<long long> v1(n);
		vector<long long> v2(m);
		for(int i = 0; i < n; i++){
			cin >> v1[i];
		}
		for(int i = 0; i < m; i++){
			cin >> v2[i];
		}
		sort(v1.begin(),v1.end(), greater<int>());
		sort(v2.begin(), v2.end());
		long long ans = v1[0]*v2[0];
		cout << ans << endl;
	}
	return 0;
}
