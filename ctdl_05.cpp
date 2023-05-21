#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n;
	cin >> n;
	long long a[n];
	for(auto &x : a){
		cin >> x;
	}
	long long q;
	cin >> q;
	for(auto x : a){
		if(x != q){
			cout << x << ' ';
		}
	}
	return 0;
}
