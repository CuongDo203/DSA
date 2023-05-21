#include <bits/stdc++.h>
using namespace std;

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
		stack<int> st;
		long long maxArea = 0;
		for(int i = 0; i < n; i++){
			if(st.empty() || a[i] >= a[st.top()]){
				st.push(i);
			}
			else{
				while(!st.empty() && a[i] < a[st.top()]){
					int v = st.top();
					st.pop();
					long long tmp;
					if(st.empty()){
						tmp = 1ll*i*a[v];
					}									
					else{
						tmp = 1ll*(i-st.top()-1)*a[v];
					}
					maxArea = max(maxArea, tmp);			
				}
				st.push(i);
			}
		}
		while(!st.empty()){
			int v = st.top();
			st.pop();
			long long tmp;
			if(!st.empty())
				tmp = 1ll*(n-st.top()-1)*a[v];
			else
				tmp = 1ll*n*a[v];
			maxArea = max(maxArea, tmp);
		}
		cout << maxArea << endl;
	}
	return 0;
}

