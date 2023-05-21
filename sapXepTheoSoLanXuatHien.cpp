#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		map<int, int> mp;
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			mp[x]++;
		}
		vector<pair<int,int>> v(mp.begin(), mp.end());
		sort(v.begin(), v.end(), [](pair<int,int> x, pair<int,int> y)->bool{
			if(x.second==y.second)
				return x.first < y.first;
			return x.second > y.second;
		});
		for(auto x : v){
			for(int i = 1; i <= x.second; i++){
				cout << x.first << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
