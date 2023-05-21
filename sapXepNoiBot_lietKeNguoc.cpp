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
		for(int i = 1; i < n; i++){
			bool ok = true;
			for(int j = 0; j < n-i;++j){
				if(a[j] > a[j+1]){
					swap(a[j], a[j+1]);
					ok = false;
				}
			}
			if(ok)
				break;
			vector<int> tmp(a,a+n);
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
