#include <bits/stdc++.h>
using namespace std;

int n, k, a[101], x[101];
long long cnt = 0;

void Dq(int i, int pos, int dem){
	for(int j = pos; j <= n; j++){
		if(dem == k){
			cnt++;
			return;
		}
		else if(a[j] > x[i-1]){
			x[i] = a[j];
			Dq(i+1,j,dem+1);
			//dem--;
		}
	}
}

int main(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	Dq(1,1,0);
	cout << cnt << endl;
	return 0;
} 
