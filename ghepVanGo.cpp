#include <bits/stdc++.h>
using namespace std;
/*
4
7 
5 2 4 3 3 1 4 
3 
2 2 2 
2 
6 6 
6 
5 5 5 5 3 1
*/
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		int ans = 0;
		stack<int> st;
		for(int i = 0; i < n; i++){
			if(st.empty() || a[i] >= a[st.top()]){
				st.push(i);
			}
			else{
				while(!st.empty() && a[i] < a[st.top()]){
					int v = st.top();
					st.pop();
					int tmp = 0;
					if(st.empty()){
						if(i >= a[v]) tmp = a[v];
					}
					else{
						if((i-st.top()-1) >= a[v]) tmp = a[v];
					}
					ans = max(ans, tmp);
				}
				st.push(i);
			}
		}
		while(!st.empty()){
			int v = st.top();
			st.pop();
			int tmp = 0;
			if(st.empty()){
				if(n >= a[v]) tmp = a[v];
			}
			else{
				if((n-st.top()-1) >= a[v]) tmp = a[v];
			}
			ans = max(ans, tmp);
		} 
		cout << ans << endl;
	}
	return 0;
}

