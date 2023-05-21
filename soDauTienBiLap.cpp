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
		for(int i=0; i < n; i++){
			cin >> a[i];
			mp[a[i]]++;
		}
		bool ok = false;
		for(int i = 0; i < n; i++){
			if(mp[a[i]]>1){
				cout << a[i]<< endl;
				ok = true;
				break;
			}
		}
		if(!ok){
			cout << "NO\n";
		}
	}
	return 0;
}
