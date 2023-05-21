#include <bits/stdc++.h>
using namespace std;
int n, x[1001];
void Dq(int i){
	for(int j = 0; j <= 1; j++){
		x[i] = j;
		if(i == n){
			for(int i = 1; i <= n; i++){
				if(x[i] == 0){
					cout << "A";
				}
				else
					cout << "B";
			}
			cout << " ";
		}
		else{
			Dq(i+1);
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
		cin >> n;
		Dq(1);
		cout << endl;
	}
	return 0;
}
