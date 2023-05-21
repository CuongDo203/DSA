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
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		stack<int> st;
		vector<int> b(n);
		for(int i = 0; i < n; i++){
			if(st.empty() || a[i] <= a[st.top()]){
				st.push(i);
			}
			else{
				while(!st.empty() && a[i] > a[st.top()]){
					b[st.top()] = a[i];
					st.pop();
				}
				st.push(i);
			}
		}
		while(!st.empty()){
			b[st.top()] = -1;
			st.pop();
		}
		for(int i = 0; i < n; i++){
			cout << b[i] << " ";
		}
		cout << endl;
	}
	return 0;
}

