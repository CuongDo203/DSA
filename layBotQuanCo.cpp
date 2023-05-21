#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int c, m;
		cin >> c >> m;
		if(c%(m+1)){
			cout << "First\n";
		}
		else{
			cout << "Second\n";
		}
	}
	return 0;
}

