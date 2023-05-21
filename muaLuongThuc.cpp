#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n, s, m;
		cin >> n >> s >> m;
		if(n < m){
			cout << "-1\n";
			continue;
		}
		int day = s - s/7;
		int need = s*m;
		int res = need/n;
		if(need%n)
			res++;
		if(res <= day){
			cout << res << endl;
		}
		else{
			cout << "-1\n";
		}
	}
	return 0;
}
