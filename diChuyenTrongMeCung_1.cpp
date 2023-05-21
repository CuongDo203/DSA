#include <bits/stdc++.h>
using namespace std;

int a[100][100];
int n;
bool ok=false;

pair<int, int> p[2] = {{1,0}, {0,1}};

void Dq(int i, int j, string s){
	if(i == n && j == n){
		ok = true;
		cout << s << " ";
		return;	
	} 
	else{
		for(int k = 0; k < 2; k++){
			int i1 = i + p[k].first;
			int j1 = j + p[k].second;
			if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && a[i1][j1] == 1){
				if(k==0){
					s+='D';
				}
				else{
					s+='R';
				}
				Dq(i1,j1,s);
				s.pop_back();
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
		memset(a, 0, sizeof(a));
		cin >> n;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				cin >> a[i][j];
			}
		}
		if(a[1][1] == 0 || a[n][n] == 0){
			cout << "-1\n";
			continue;
		}
		string s = "";
		Dq(1,1,s);
		if(!ok)
        	cout << "-1";
        ok = false;
        cout << endl;
	}
	return 0;
}
