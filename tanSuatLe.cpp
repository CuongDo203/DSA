#include <bits/stdc++.h>
using namespace std;

int a[1000000], cnt[1000000];

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			cnt[a[i]]++;
		}
		for(int i = 0; i < n; i++){
			if(cnt[a[i]]%2){
				cout << a[i] << endl;
				break;
			}	
		}
		memset(cnt,0,sizeof(cnt));
	}
	return 0;
}
