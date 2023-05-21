#include <bits/stdc++.h>
using namespace std;

int n;
int a[1005][1005];
vector<int> ke[1005];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(a[i][j]){	
				ke[i].push_back(j);	
			}
		}
	}
	for(int i = 1; i <= n; i++){
		sort(ke[i].begin(), ke[i].end());
		for(auto x : ke[i]){
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}

