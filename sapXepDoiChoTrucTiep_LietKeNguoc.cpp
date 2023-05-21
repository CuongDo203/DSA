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
		vector<vector<int>> v;
		for(int i = 0; i < n-1; i++){
			for(int j = i+1; j < n; j++){
				if(a[j] < a[i]){
					swap(a[i], a[j]);
				}
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
	}
	return 0;
}
