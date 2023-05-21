#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<vector<int>> v;
	int idx, new_number;
	for(int i = 0; i < n; i++){
		int j = i;
		while(j > 0 && a[j] < a[j-1]){
			swap(a[j], a[j-1]);
			j--;
		}
		vector<int> tmp(a, a+i+1);
		v.push_back(tmp);
	}
	reverse(v.begin(), v.end());
	int cnt=0;
	for(auto it : v){
		cnt++;
		cout << "Buoc " << v.size()-cnt << ": ";
		for(int i = 0; i < it.size(); i++){
			cout << it[i] << " ";
		}
		cout << endl;
	}
	v.clear();
	return 0;
}
