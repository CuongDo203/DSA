#include <bits/stdc++.h>
using namespace std;

int n, x[1001], k;

bool check(){
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(x[i])
			cnt++;
	}
	return cnt == k;
}

void Dq(int i){
	for(int j = 0; j <= 1; j++){
		x[i] = j;
		if(i == n){
			if(check()){
				for(int i = 1; i <= n; i++){
					cout << x[i];
				}
				cout << endl;
			}
		}
		else{
			Dq(i+1);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		Dq(1);
		cout << endl;
	}
	return 0;
}
