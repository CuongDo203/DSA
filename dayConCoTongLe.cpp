#include <bits/stdc++.h>
using namespace std;

int n, s=0;
int a[100];
vector<int> res;
set<vector<int>> v;

void Dq(int pos, int sum){
	for(int j = pos; j < n; j++){
		res.push_back(a[j]);
		sum+=a[j];
		if(sum%2==1){
			v.insert(res);
		}
		if(j+1<n){
			Dq(j+1, sum);
		}
		res.pop_back();
		sum-=a[j];
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
		for(int i = 0; i < n; i++){
			cin >> a[i];
			s+=a[i];
		}
		sort(a, a+n, greater<int>());
		Dq(0,0);
	//	cout << v.size() << endl;
		for(auto x : v){
			for(int i = 0; i < x.size(); i++){
				cout << x[i] << " ";
			}
			cout << endl;
		}
		v.clear();
	}
	return 0;
}

