#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a, a+n);
		int min1 = *min_element(a, a+n);
		auto it = upper_bound(a, a+n, min1);
		if(it == a+n){
			cout << "-1\n";
		}
		else{
			cout << min1 << ' ' << *it << endl;
		}
	}
	return 0;
}
