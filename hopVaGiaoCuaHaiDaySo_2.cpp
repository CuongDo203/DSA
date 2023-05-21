#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<int> v1(n);
		vector<int> v2(m);
		set<int> Union, tmp, Intersection;
		for(int i = 0; i < n; i++){
			cin >> v1[i];
			Union.insert(v1[i]);
		}
		for(int i = 0; i < m; i++){
			cin >> v2[i];
			Union.insert(v2[i]);
			tmp.insert(v2[i]);
		}
		for(int i = 0; i < n; i++){
			if(tmp.count(v1[i])){
				Intersection.insert(v1[i]);
			}
		}
		for(auto x : Union)
			cout << x << " ";
		cout << endl;
		for(auto it : Intersection)
			cout << it << " ";
		cout << endl;
	}
	return 0;
}
