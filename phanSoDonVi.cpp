#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		long long a, b;
		cin >> a >> b;
		while(a!=0){
			long long tmp = b/a;
			if(a*tmp < b) tmp++;
			cout << "1/" << tmp;
			a = a*tmp - b;
			b = b*tmp;
			if(a!=0) cout << " + "; 
		}
		cout << endl;
	}	
	return 0;
}

