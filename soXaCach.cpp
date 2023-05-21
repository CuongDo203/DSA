#include <bits/stdc++.h>
using namespace std;

int n;
int x[100];
int used[100];
void Dq(int i){
	for(int j = 1; j <= n; j++){
		if(!used[j] && abs(j - x[i-1]) > 1){
			x[i] = j;
			used[j] = 1;
			if(i == n){
				for(int k = 1; k <= n; k++){
					cout << x[k];
				}
				cout << endl;
			}
			else
				Dq(i+1);
			used[j] = 0;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	x[0]=-1; 
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		Dq(1);
		memset(x,0, sizeof(x));
		memset(used,0,sizeof(used));
	}
	return 0;
}
