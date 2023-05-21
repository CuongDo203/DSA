#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		priority_queue<long long, vector<long long>, greater<long long>> q;
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			q.push(x);
		}
		long long res = 0;
		while(q.size() > 1){
			long long a = q.top();
			q.pop();
			long long b = q.top();
			q.pop();
			res += (a+b);
			q.push(a+b);
		}
		cout << res << endl;
	}
	return 0;
}
