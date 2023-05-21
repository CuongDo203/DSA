#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		stack<char> st;
		int cnt = 0;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '('){
				st.push('(');
			}
			else{
				if(!st.empty()){
					st.pop();
				}
				else{
					cnt++;
				}
			}
		}
		int ans = st.size()/2 + cnt/2;
		ans += st.size()%2 + cnt % 2;
		cout << ans << endl;
	}
	return 0;
}

