#include <bits/stdc++.h>
using namespace std;

int n, m;  //so dinh, so canh
vector<int> ke[1005];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;
	    for(int i =0; i < m; i++){  
	        int x, y;
	        cin >> x >> y;
	        ke[x].push_back(y);
	        ke[y].push_back(x);
	    }
	    for(int i = 1; i <= n; i++){
	        sort(ke[i].begin(), ke[i].end());
	        cout << i << ": "; 
	        for(auto x : ke[i]){
	            cout << x << " ";
	        }
	        cout << endl;
	    }
	    memset(ke,0,sizeof(ke));
	}
	return 0;
}

