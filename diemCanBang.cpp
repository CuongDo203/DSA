#include <bits/stdc++.h>
using namespace std;

long long prefix[1000002];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
			if(i==0){
				prefix[i] = a[i];
			}
			else{
				prefix[i] = prefix[i-1]+a[i];
			}
		}
		bool ok = 0;
		for(int i = 0; i < n; i++){
			if(prefix[i] == prefix[n-1] - prefix[i-1]){
				cout << i+1;
				ok = 1;
				break;
			}
		}
		if(!ok){
			cout << "-1";
		}
		cout << endl;
		memset(prefix,0,sizeof(prefix));
	}
	return 0;
}
