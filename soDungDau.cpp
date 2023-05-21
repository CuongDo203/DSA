#include <bits/stdc++.h>
using namespace std;

int main(){
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
		int res = a[n-1];
		st.push(res);
		for(int i = n-2; i >= 0; i--){
			if(a[i] > res){
				st.push(a[i]);
				res = a[i];
			}
		}
		while(!st.empty()){
			cout << st.top() << ' ';
			st.pop();
		}
		cout << endl;
	}
	return 0;
}
