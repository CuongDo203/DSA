#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n,x;
		cin >> n >> x;
		int a[n], b[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
			b[i] = x-a[i];
		}
		stable_sort(b, b+n, [](int t1, int t2)->bool{
			return abs(t1) < abs(t2);
		});
		for(int i = 0; i < n; i++){
			cout << x-b[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
