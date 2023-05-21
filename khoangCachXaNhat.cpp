#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		pair<int,int> p[n+1];
		for(int i = 1; i <= n; i++){
			cin >> p[i].first;
			p[i].second = i;
		}
		sort(p, p+n);
		int ans = -1, tmp = p[1].first, idx = p[1].second;
		for(int i = 2; i <= n; i++){
			if(p[i].first > tmp){
				ans = max(ans, p[i].second - idx);
			}
			if(idx > p[i].second){
				idx = p[i].second;
				tmp = p[i].first;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

