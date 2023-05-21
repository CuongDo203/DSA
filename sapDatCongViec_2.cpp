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
		vector<pair<int,int>> v(n);
		for(int i = 0; i < n; i++){
			int x;
			cin >> x >> v[i].first >> v[i].second;
		}
		sort(v.begin(), v.end(), [](pair<int,int> x, pair<int,int> y)->bool{
			if(x.second == y.second){
				return x.first > y.first;
			}
			return x.second > y.second;
		});
		bool start[1005] = {};
		vector<pair<int,int>> ans;
		long long profit = 0;
		for(int i = 0; i < n; i++){
			for(int j = v[i].first-1; j>=0; j--){
				if(!start[j]){
					ans.push_back(v[i]);
					profit += v[i].second;
					start[j] = 1;
					break;
				}
			}
		}
		cout << ans.size() << " " << profit << endl;
		ans.clear();
	}
	return 0;
}

