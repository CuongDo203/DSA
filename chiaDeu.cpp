#include <bits/stdc++.h>
using namespace std;

int n, k, a[100];
long long p[100];
long long cnt = 0;

void Dq(int val, int l, int r, int k){
	if(l > r) return;
	if(k == 1){
		if(p[r] - p[l-1] == val){
			cnt++;
		}
		return;
	}
	for(int i = l; i <= r; i++){
		if(p[i] - p[l-1] == val){
			Dq(val, i+1, r, k-1);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	memset(p, 0, sizeof(p));
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(i == 1){
			p[i] = a[i];
		}
		else
			p[i] = p[i-1]+a[i];
	}
	if(k == 1){
		cout << "1\n";
		return 0;
	}
	for(int i = 1; i <= n; i++){
		int x = p[i];
		Dq(x, i+1, n, k-1);
	}
	cout << cnt << endl;
	return 0;
}

