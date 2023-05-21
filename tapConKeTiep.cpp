#include <bits/stdc++.h>
using namespace std;

int x[1001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n, k;
	    cin >> n >> k;
	    for(int i = 1; i <= k; i++){
	        cin >> x[i];
	    }
	    int i = k;
	    while(i >= 1 && x[i] == n - k + i){
	        i--;
	    }
	    if(i < 1){
	        for(int j = 1; j <= k; j++){
	            x[j] = j; 
	        }
	    }
	    else{
	        x[i]++;
	        for(int j = i+1; j <= k; ++j){
	            x[j] = x[j - 1] + 1;
	        }
	    }
	    for(int r = 1; r <= k; r++){
	        cout << x[r] << " ";
	    }
	    cout << endl;
	}
	return 0;
}
