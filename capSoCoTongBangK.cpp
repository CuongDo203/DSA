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
		map<int,int> mp;
		long long cnt = 0;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		} 
		for(int i = 0; i < n; i++){
			if(mp[k-a[i]]){
				cnt+=mp[k-a[i]];
			}
			mp[a[i]]++;
		}
		cout << cnt << endl;
	}
	return 0;
}   
