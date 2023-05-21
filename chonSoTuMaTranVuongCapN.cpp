#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[20][20];
int used[20];
int col[20];   //luu chi so cot
vector<string> v;

void Dq(int i){
	for(int j = 1; j <= n; j++){
		if(!used[j]){
			col[i] = j;
			used[j] = 1;
			if(i==n){
				int sum = 0;
				for(int idx = 1; idx <= n; idx++){
					sum += a[idx][col[idx]];
				}
				
				if(sum == k){
					string tmp = "";
					for(int idx = 1; idx <= n; idx++){
						tmp+=to_string(col[idx]);
						tmp+=" ";
					}
					v.push_back(tmp);
				}
			}
			else{
				Dq(i+1);
			}
			used[j] = 0;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	Dq(1);
	cout << v.size() << endl;
	for(auto it : v){
		cout << it << " ";
		cout << endl;
	}
	return 0;
}

