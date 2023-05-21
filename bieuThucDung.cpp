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
		stack<int> st;
		int res = 0;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '['){
				st.push(i);
			}
			else{
				if(!st.empty()){
					st.pop();
				}
				else{
					int j = i;
					while(s[j] == ']' && j < s.size()){
						j++;
					}
					res += j-i;
					swap(s[i], s[j]);
					st.push(i);
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}

