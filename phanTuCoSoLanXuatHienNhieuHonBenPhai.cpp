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
		map<int,int> mp;
		mp.clear();
		for(int i = 0; i < n; i++){
			cin >> a[i];
			mp[a[i]]++;
		}
		stack<int> st, ans;
		for(int i = n-1; i >= 0; i--){
			while(!st.empty() && mp[a[i]] >= mp[st.top()]){
				st.pop();
			}
			if(st.empty()){
				ans.push(-1);
			}
			else{
				ans.push(st.top());
			}
			st.push(a[i]);
		}
		while(!st.empty()){
			st.pop();
		}
		while(!ans.empty()){
			cout << ans.top() << " ";
			ans.pop();
		}
		cout << endl;
	}
	return 0;
}

