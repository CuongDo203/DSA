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
		int n;
	    cin >> n;
	    for(int i = 1; i <= n; i++){
	        cin >> x[i];
	    }
	    int i = n - 1;
	    while(i >= 1 && x[i] > x[i+1])
	        --i;
	    if(i < 1){
	        reverse(x+1, x+1+n);
	    }
	    else{
	        int j = n;
	        while(x[j] < x[i]){
	            --j;
	        }
	        swap(x[i], x[j]);
	        int l = i+1, r=n;
	        while(l < r){
	            swap(x[l], x[r]);
	            l++;
	            r--;
	        }
	    }
	    for(int i = 1; i <= n; i++){
	        cout << x[i] << " ";
	    }
	    cout << endl;
	}
	return 0;
}
