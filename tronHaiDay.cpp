#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int n, int b[], int m){
	int i = 0, j = 0;
	while(i < n && j < m){
		if(a[i] <= b[j]){
			cout << a[i] << " ";
			i++;
		}
		else{
			cout << b[j] << " ";
			j++;
		}
	}
	while(i < n){
		cout << a[i] << " ";
		i++;
	}
	while(j < m){
		cout << b[j] << " ";
		j++;
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		int a[n], b[m];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		for(int i = 0; i < m; i++){
			cin >> b[i];
		}
		sort(a, a+n);
		sort(b, b+m);
		merge(a,n,b,m);
		cout << endl;
	}
	return 0;
}
