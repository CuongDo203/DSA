#include <bits/stdc++.h>
using namespace std;

int a[1005];

bool check(int res, vector<int> v){
	for(int i = 0; i < v.size()-1; i++){
		if(a[i]/v[i] != res) return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}	
	int minn = *min_element(a, a+n);
	long long ans = 1e9;
	
	for(int k = minn; k>0 ; k--){
		long long sum = 0;
		int tmp = minn;
		int res = (int)tmp/k;
		vector<int> v;
		for(int i = 0; i < n; i++){
			int te = a[i]/(res+1);
			sum += (te+1);
			v.push_back(te+1);
		}
		if(check(res, v)){
			long long t = accumulate(v.begin(), v.end(), 0);
			ans = min(ans, t);
		}
		v.clear();
	}
	cout << ans << endl;
	return 0;
}

