#include <bits/stdc++.h>
using namespace std;

int a[20][20], n, visited[20][20];
vector<string> v;
char path[4] = {'D', 'L', 'R', 'U'};
pair<int,int> p[4] = {{1,0}, {0,-1}, {0,1}, {-1,0}};
string s="";
bool ok = false;

void Dq(int i, int j){
	visited[i][j] = 1;
	if(i == n-1 && j == n-1){
		v.push_back(s);
		ok = true;
		return;
	}
	else{
		for(int k = 0; k < 4; k++){
			int i1 =i + p[k].first;
			int j1 =j + p[k].second;
			if(i1 >= 0 && i1 < n && j1 >= 0 && j1 < n && a[i1][j1] == 1 && !visited[i1][j1]){
				visited[i1][j1] = 1;
				s += path[k];
				Dq(i1,j1);
				visited[i1][j1] = 0;
				s.pop_back();
			}
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> a[i][j];
			}
		}
		Dq(0,0);
		if(a[0][0] == 0){
			cout << "-1\n";
			continue;
		}
		if(!ok){
			cout << "-1\n";
		}
		else{
			for(auto x : v){
				cout << x << " ";
			}
			cout << endl;
		}
		v.clear();
	}
	return 0;
}
