#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[1001], x[1001];

void sinh(){
	for(int i = 1; i <= k; i++){
		cin >> x[i];
	}
	for(int i = 1; i <= k; i++){
		a[i] = i;
	}
	int dem = 0;
	while(1){
		dem++;
		int cnt = 0;
		for(int i = 1; i <= k; i++){
			if(a[i] == x[i]){
				cnt++;
			}
		}
		if(cnt==k){
			cout << dem << endl;
			return;
		}
		int i = k;
	    while(i >= 1 && a[i] == n-k+i){
	        i--;
	    }
	    if(i < 1){
	        cout << k << endl;
	        break;
	    }      
	    else{
	        a[i]++;
	        for(int j = i+1; j <= k; j++){
	            a[j] = a[j-1]+1;
	        }
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
		sinh();
	}
	return 0;
}
