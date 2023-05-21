#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	stack<int> st;
	string s;
	while(cin >> s){
		int k;
		if(s == "push"){
			cin >> k;
			st.push(k);
		}
		if(s == "pop"){
			if(!st.empty()){
				st.pop();
			}
			else{
				cout << "empty\n";
				return 0;
			}
		}
		if(s == "show"){
			vector<int> v;
			while(!st.empty()){
				v.push_back(st.top());
				st.pop();
			}
			for(int i = v.size()-1; i >= 0; i--){
				st.push(v[i]);
				cout << v[i] << " ";
			} 
			cout << endl;
		}
		if(st.empty()){
			cout << "empty\n";
			return 0;
		}
	}
	return 0;
}

