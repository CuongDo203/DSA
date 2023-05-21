#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		multiset<int> m;
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			m.insert(x);
		}
		for(auto x : m)
			cout << x << " ";
		cout << endl;
	}
	return 0;
} 
