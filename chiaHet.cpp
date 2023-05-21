#include <bits/stdc++.h>
using namespace std;

int check(int n, int k){
	int cnt = 0;
	for(int i = 2; i <= n; i*= 2){
		cnt += n/i;
	}
	return cnt >= k;
}

int main(){
	int n, k;
	cin >> n >> k;
	if(check(n,k))
		cout << "Yes";
	else
		cout << "No";
	return 0;
}
