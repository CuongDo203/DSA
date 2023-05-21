#include <bits/stdc++.h>
using namespace std;

int n, m;
int deg_in[1005], deg_out[1005];

void solve(){
	memset(deg_in, 0, sizeof(deg_in));
	memset(deg_out, 0, sizeof(deg_out));
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		deg_out[x]++;
		deg_in[y]++;
	}
	int cnt= 0;
	for(int i = 1; i <= n; i++){
		if(deg_in[i] != deg_out[i]){
			cnt++;
		}
	}
	if(cnt == 0){
		cout << 1 << endl;
	}
	else{
		cout << 0 << endl;
	}
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		solve();
	} 
	return 0;
}

