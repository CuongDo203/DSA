#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		pair<int,int> p[n];
		for(int i = 0; i < n; i++){
			cin >> p[i].first >> p[i].second;
		}
		sort(p, p+n, [](pair<int,int> x, pair<int,int> y)->bool{
			return x.second < y.second;
		});
		int tmp = p[0].second;
		int cnt = 1;
		for(int i = 1; i < n; i++){
			if(p[i].first >= tmp){
				cnt++;
				tmp = p[i].second;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
