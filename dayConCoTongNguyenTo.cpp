#include <bits/stdc++.h>
using namespace std;

int n, a[100];
vector<int> x;
set<vector<int>> se;

int nt(int n){
	for(int i = 2; i <= sqrt(n); i++){
		if(n%i==0)
			return 0;
	}
	return n>1;
}

void Dq(int pos, int sum){
	for(int j = pos; j < n; j++){
		x.push_back(a[j]);
		sum += a[j];
		if(nt(sum)){
			se.insert(x);
		} 
		if(j+1 < n){
			Dq(j+1, sum);
		}
		x.pop_back();
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
		}
		sort(a, a+n, greater<int>());
		Dq(0,0);
		for(auto it : se){
			for(auto i : it){
				cout << i << " ";
			}
			cout << endl;
		}
		se.clear();
	}
	return 0;
}

