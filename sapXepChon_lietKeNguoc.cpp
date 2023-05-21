#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<vector<int>> v;
	for(int i = 0; i < n-1; i++){
		int min_idx = i;
		for(int j = i+1; j < n; j++){
			if(a[j] < a[min_idx]){
				min_idx = j;
			}
		}
		if(i!=min_idx){
			swap(a[i], a[min_idx]);
		}
		vector<int> tmp(a, a+n);
		v.push_back(tmp);
	}
	reverse(v.begin(), v.end());
	int cnt=0;
	for(auto it : v){
		cout << "Buoc " << v.size()-cnt << ": ";
		for(int i = 0; i < it.size(); i++){
			cout << it[i] << " ";
		}
		cout << endl;
		cnt++;
	}
	v.clear();
	return 0;
}
