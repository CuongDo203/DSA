#include <bits/stdc++.h>
using namespace std;

int a[105][105];
pair<int,int> p[2] = {{1,0}, {0,1}};
int m, n;

int cnt = 0;
void Dq(int i, int j){
	if(i == m && j == n){
		cnt++;
	}
	else{
		for(int k = 0; k < 2; k++){
			int i1 = i + p[k].first;
			int j1 = j + p[k].second;
			if(i1 >= 1 && i1 <= m && j1 >= 1 && j1 <= n){
				Dq(i1,j1);
			}
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> m >> n;
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= n; j++){
				cin >> a[i][j];
			}
		}
		Dq(1,1);
		cout << cnt << endl;
		cnt=0;
		memset(a,0,sizeof(a));
	}
	return 0;
}
