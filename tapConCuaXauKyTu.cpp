#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int x[101];

void Dq(int i){		
	for(int j = x[i-1]+1; j <= n; j++){
		x[i] = j;
		for(int k = 1; k <= i; k++){
			cout << s[x[k]-1];
		}
		cout << " ";
		if(i < n){
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
		cin >> n >> s;
		sort(s.begin(), s.end());
		Dq(1);
		cout << endl;
		memset(x,0,sizeof(x));
	} 
	return 0;
}

