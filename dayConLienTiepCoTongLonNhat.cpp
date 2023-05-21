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
		int max_end_here = 0, max_diff = 0;
		for(int i = 0; i < n; i++){
			max_end_here += a[i];
			if(max_diff < max_end_here){
				max_diff = max_end_here;
			}
			if(max_end_here < 0){
				max_end_here = 0;
			}
		}
		cout << max_diff << endl;
	}
	return 0;
}
