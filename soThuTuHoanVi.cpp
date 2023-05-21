#include <bits/stdc++.h>
using namespace std;

int a[1001];
vector<int> x(1001);
vector<vector<int>> v;
int n;

void sinh(){
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		x[i] = i;
	}
	int dem = 0;
	while(1){
		dem++;
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			if(a[i] == x[i]){
				cnt++;
			}
		}
		if(cnt == n){
			cout << dem << endl;
			return;
		}
		int i = n-1;
		while(i >= 1 && x[i] > x[i+1]){
			i--;
		}	
		if(i < 1){
			break;
		}
		else{
			int j = n;
			while(x[j] < x[i]){
				j--;
			}
			swap(x[i], x[j]);
			int l = i+1, r = n;
			while(l < r){
				swap(x[l], x[r]);
				l++;
				r--;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		sinh();
	}
	return 0;
}
