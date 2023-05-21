#include <bits/stdc++.h>
using namespace std;

int k,n, m;
set<string> se;
vector<string> ans;
char a[5][5];
bool vs[5][5];

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void Dq(int i, int j, string s){
	//cout << s << endl;
	if(se.count(s)){
		ans.push_back(s);
		return;
	}
	for(int k = 0; k < 8; k++){
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if(i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && !vs[i1][j1]){
			vs[i1][j1] = true;
			Dq(i1,j1, s + a[i1][j1]);
			vs[i1][j1] = false;
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
		se.clear();
		ans.clear();
		memset(vs, false, sizeof(vs));
		cin >> k >> n >> m;
		for(int i = 0; i < k; i++){
			string s;
			cin >> s;
			se.insert(s);
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> a[i][j];
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				vs[i][j] = true;
				Dq(i,j, string(1, a[i][j]));
				vs[i][j] = false;
			}
		}
		if(ans.size()==0){
			cout << "-1\n";
		}
		else{
			for(auto x : ans){
				cout << x << " ";
			}
			cout << endl;
		}
	}	
	return 0;
}

