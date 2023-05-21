#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> v1(n), v2(m), v3(k);
		for(auto &x : v1) cin >> x;
		for(auto &x : v2) cin >> x;
		for(auto &x : v3) cin >> x;
		int i = 0, j = 0, z = 0;
		vector<int> res;
		while(i < n && j < m && z < k){
			if(v1[i] == v2[j] && v1[i] == v3[z]){
				res.push_back(v1[i]);
				i++;
				j++;
				z++;
			}
			else if(v1[i] < v2[j]){
				i++;
			}
			else if(v2[j] < v3[z]){
				j++;
			}
			else{
				z++;
			}
		}
		if (res.empty()) cout << "NO";
	    else {
	        for (auto i : res) {
	            cout << i << " ";
	        }
	    }
	    cout << endl;
	}
	return 0;
}
