#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		long long a[n];
		map<long long, int> mp;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			mp[a[i]]++;
		}
		long long maxx=-1e9, minn=1e9;
		for(int i = 0; i < n; i++){
			if(a[i] > maxx){
				maxx=a[i];
			}
			if(a[i] < minn){
				minn=a[i];
			}
		}
		int cnt= 0;
		for(int i = minn; i <= maxx; i++){
			if(mp[i]==0){
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
