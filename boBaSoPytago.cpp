#include <bits/stdc++.h>
using namespace std;

void solve(int a[], int n){
	sort(a, a+n);
	for(int i = 0; i < n-2; i++){
		for(int j = i+1; j < n-1; j++){
			long long tmp = a[i]*a[i] + a[j]*a[j];
			long long x = sqrt(tmp);
			if(x*x==tmp && binary_search(a+j+1,a+n, x)){
				cout << "YES";
				return;
			}
		}				
	}
	cout << "NO" ;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		long long a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		solve(a,n);
		cout << endl;
	}
	return 0;
}
