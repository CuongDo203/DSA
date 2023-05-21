#include <bits/stdc++.h>
using namespace std;

int n, k;
int x[101];
map<int,int> mp;

void sinh(){
	int i = k;
	while(i >= 1 && x[i] == n-k+i){
		--i;
	}
	if(i < 1){
		cout << k;
		return;
	}
	else{
		x[i]++;
		for(int j = i+1; j <= k; j++){
			x[j] = x[j-1]+1;
		}
	}
	int cnt = 0;
	for(int j = 1; j <= k; j++){
		if(mp[x[j]] == 0){
			cnt++;
		}
	}
	cout << cnt;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 1; i <= k; i++){
			cin >> x[i];
			mp[x[i]]++;
		}
		sinh();
		cout << endl;
		memset(x,0,sizeof(x));
		mp.clear();
	}
	
	return 0;
}
