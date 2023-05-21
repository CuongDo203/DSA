#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[505][505];

void nhap(){
	memset(a,0,sizeof(a));
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
			if(a[i][j] == 1 && i > 0 && a[i-1][j] > 0){
				a[i][j] = a[i-1][j] + 1;
			}
		}
	}
}

int solve(int a[], int m){
	vector<int> l(m), r(m);
	stack<int> st;
	for(int i = 0; i < m; i++){
		while(!st.empty() && a[i] <= a[st.top()]){
			st.pop();
		}
		if(st.empty()){
			l[i] = 0;
		}
		else{
			l[i] = st.top()+1;
		}
		st.push(i);
	}
	while(!st.empty()){
		st.pop();
	}
	for(int i = m-1; i >= 0; i--){
		while(!st.empty() && a[st.top()] >= a[i]){
			st.pop();
		}
		if(st.empty()){
			r[i] = m-1;
		}
		else{
			r[i] = st.top()-1;
		}
		st.push(i);
	}
	int tmp = 0;
	for(int i = 0; i < m; i++){
		tmp = max(tmp, a[i]*(r[i]-l[i]+1));
	}
	return tmp;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		nhap();
		int ans = 0;
		for(int i = 0; i < n; i++){
			ans = max(ans, solve(a[i],m));
		}
		cout << ans << endl;
	}
	return 0;
}

