#include <bits/stdc++.h>
using namespace std;
using ll = long long;
set<ll> Union(vector<ll> &a, vector<ll> &b){
	set<ll> res, ans;
	for(auto x : a){
		res.insert(x);
	} 
	for(auto x : b){
		if(res.count(x)){
			ans.insert(x);
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		ll n1, n2, n3;
		cin >> n1 >> n2 >> n3;
		vector<long long> v1(n1), v2(n2), v3(n3);
		for(auto &x : v1) cin >> x;
		for(auto &x : v2) cin >> x;
		for(auto &x : v3) cin >> x;
		vector<long long> res;
	    int i = 0, j = 0, z = 0;
	    while (i < n1 && j < n2 && z < n3) {
	        if (v1[i] == v2[j] && v1[i] == v3[z]) {
	            res.push_back(v1[i]);
	            i++, j++, z++;
	        }
	        else if (v1[i] < v2[j]) i++;
	        else if (v2[j] < v3[z]) j++;
	        else z++;
	    }
	    if (res.empty()) cout << -1;
	    else {
	        for (auto i : res) {
	            cout << i << " ";
	        }
	    }
	    cout << endl;
	} 
	return 0;
}
