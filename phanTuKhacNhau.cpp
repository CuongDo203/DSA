#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> a, vector<int> b){
	int i = 0, j = 0;
	while(i < a.size() && j < b.size()){
		if(a[i] == b[j]){
			i++;
			j++;
		}
		else{
			cout << i+1 << endl;
			return;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<long long> a(n);
		vector<long long> b(n-1);
		for(auto &x : a) cin >> x;
		for(auto &x : b) cin >> x;
		solve(a,b);
	}
	return 0;
} 
