#include <bits/stdc++.h>
using namespace std;

int a[10] = {1000,500,200,100,50,20,10,5,2,1};

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		long long cnt = 0;
		for(int i = 0; i < 10; i++){
			cnt += (n/a[i]);
			n%=a[i];
		}
		cout << cnt << endl;
	}
	return 0;
}
