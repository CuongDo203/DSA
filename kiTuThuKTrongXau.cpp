#include <bits/stdc++.h>
using namespace std;

char Find(long long n, long long k){
	if(k%2==1){
		return 'A';
	}
	if(k == pow(2,n-1)){
		return (n-1+'A');
	}
	else if(k < pow(2,n-1)){
		return Find(n-1,k);
	}
	else{
		return Find(n-1,k-pow(2,n-1));
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		long long n, k;
		cin >> n >> k;
		cout << Find(n,k) << endl;
	}
	return 0;
}
