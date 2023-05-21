#include <bits/stdc++.h>
using namespace std;

int n, C[100][100];
int x[100];   //x[i] thanh pho thu i ma nguoi du lich di qua
bool visited[100]; //kiem tra da duoc di qua hay chua 
int res = 1e9, cmin = 1e9;

void Dq(int i, int cost){
	for(int j = 2; j <= n; j++){
		if(!visited[j]){
			visited[j] = true;
			x[i] = j;
			cost += C[x[i-1]][x[i]];
			if(i==n){
				cost += C[1][x[i]];
				res = min(res, cost);
			}
			else if(cost + (n-i+1)*cmin < res){
				Dq(i+1, cost);
			}
			cost -= C[x[i-1]][x[i]];
			visited[j] = false;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> C[i][j];
			if(C[i][j]){
				cmin = min(cmin, C[i][j]);
			}
		}
	}
	x[1] = 1;
	Dq(2,0);
	cout << res << endl;
	return 0;
}

