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
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		bool ok = true;
		for(int i = 1; i < n; i++){
			if(a[i] <= a[i-1]){
				ok = false;
				break;
			}
		}
		if(ok) cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}

