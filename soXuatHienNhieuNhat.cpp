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
		int a[n];
		map<int,int> mp;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			mp[a[i]]++;
		}
		int ans = 0, fre = 1;
		for(int i = 0; i < n; i++){
			if(mp[a[i]] >= fre){
				ans=a[i];
				fre=mp[a[i]];
			}
		}
		
		if(fre > n/2){
			cout << ans << endl;
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}
