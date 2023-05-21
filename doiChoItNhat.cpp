#include <bits/stdc++.h>
using namespace std;

int selection_sort(int a[], int n){
	int cnt = 0;
	for(int i = 0; i < n-1; i++){
		int min_idx = i;
		for(int j = i+1; j < n; j++){
			if(a[min_idx] > a[j]){
				min_idx=j;
			}
		}
		if(i != min_idx){
			cnt++;
			swap(a[i], a[min_idx]);
		}
	}
	return cnt;
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
		cout << selection_sort(a,n) << endl;
	}
	return 0;
}
