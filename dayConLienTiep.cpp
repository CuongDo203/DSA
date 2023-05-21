#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int ans(int a[], int n){
	int tmp = 0, max_sum = 0;
	for(int i = 0; i < n; i++){
		if(tmp + a[i] < 0){
			tmp = 0;
		}
		else{
			tmp += a[i];
		}
		if(tmp > max_sum){
			max_sum = tmp;
		}
	}
	return max_sum;
}

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
		cout << ans(a,n) << endl;
	}
	return 0;
}
