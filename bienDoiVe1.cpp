#include <bits/stdc++.h>
using namespace std;

int res = INT_MAX, n;

void Dq(int n, int cnt){
	if(cnt > res) return;
	if(n==1){
		res = min(res, cnt);
		return;
	}	
	if(n%3==0){
		Dq(n/3, cnt+1);
	}
	if(n%2==0){
		Dq(n/2,cnt+1);
	}
	Dq(n-1, cnt+1);
}

//void solve(){
//	queue<pair<int,int>> q;
//	q.push(make_pair(n,0));
//	while(1){
//		pair<int,int> p = q.front();
//		q.pop();
//		if(p.first==1){
//			cout << p.second << endl;
//		//	res=min(res,p.second);
//			return;
//		}
//		if(p.first%3==0)
//			q.push(make_pair(p.first/3, p.second+1));
//		if(p.first%2==0)
//			q.push(make_pair(p.first/2, p.second+1));
//		q.push(make_pair(p.first-1, p.second+1));
//	}
//}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		Dq(n,0);
		//solve();
		cout << res << endl;
	}
	return 0;
}

