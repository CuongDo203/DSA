#include <bits/stdc++.h>
using namespace std;

int n;
int a[1005][1005];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	cin.ignore();
	for(int i = 1; i <= n; i++){
		string s;
		getline(cin,s);
		stringstream ss(s);
		string tmp;
		while(ss >> tmp){
			int x = stoi(tmp);
			a[i][x] = a[x][i] = 1; 
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

