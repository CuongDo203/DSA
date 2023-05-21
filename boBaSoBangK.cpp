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
		sort(a,a+n);
		bool ok = false;
		for(int i = 0; i < n-2; i++){
			int j = i+1, r=n-1;
			while(j < r){
				if(a[i] + a[j] + a[r] == k){
					ok = true;
					break;
				}
				else if(a[i] + a[j] + a[r] > k){
					r--;
				}
				else{
					j++;
				}
			}
		}
		if(!ok){
			cout << "NO";
		}
		else{
			cout << "YES";
		}
		cout << endl;
	}
	return 0;
} 
