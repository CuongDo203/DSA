#include <bits/stdc++.h>
using namespace std;

int n, a[100];

vector<string> v;

void in(int n){
	cout << "(";
	for(int i = 1; i <= n; i++){
		cout << a[i];
		if(i != n)
			cout << " ";
		else 
			cout << ")";
	}
	cout << " ";
}

void Dq(int x, int i, int s){
	for(int j = x; j >= 1; j--){
		a[i] = j;
		if(j == s) in(i);
		else if(j < s) Dq(j, i+1, s-j);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		Dq(n,1,n);
		cout << endl;
		memset(a,0,sizeof(a));
	}
	return 0;
}

