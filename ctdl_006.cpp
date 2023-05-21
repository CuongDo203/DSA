#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	set<int> se;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(se.insert(x).second){
			cout << x << ' ';
		}
	}
	return 0;
}
