#include <bits/stdc++.h>
using namespace std;

int n, k, a[101], x[101];
vector<vector<int>> v;

void Dq(int i, int pos, int dem){
	for(int j = pos; j <= n; j++){
		if(dem == k){
			vector<int> tmp;
			for(int id = 1; id <= k; id++){
				tmp.push_back(x[id]);
			}
			v.push_back(tmp);
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
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		sort(a+1, a+n+1);
		Dq(1,1,0);
		for(auto it : v){
			for(int i = 0; i < it.size(); i++){
				cout << it[i] << " ";
			}
			cout << endl;
		}
		v.clear();
		memset(x,0,sizeof(x));
	}
	return 0;
} 
