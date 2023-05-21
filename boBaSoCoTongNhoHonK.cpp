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
		sort(a, a+n);
		long long res = 0;
//		for(int i = 0; i < n-1; i++){
//			for(int j = i+1; j < n; j++){
//				long long tmp = k - a[i] - a[j];
//				res += lower_bound(a+j+1, a+n, tmp) - (a+j+1);
//			}
//		}
//		cout << res << endl;
		for (int i = 0; i < n - 2; i++) {
	        int j = i + 1, l = n - 1;
	        while (j < l) {
	            if (a[i] + a[j] + a[l] >= k)
	                l--;
	            else {
	                res++;
	                j++;
	            }
	        }
	    }
	    cout << res << endl;
	}
	return 0;
}
