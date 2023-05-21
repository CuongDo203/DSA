#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin >> q;
	stack<int> st;
	string s;
	while(q--){
		int k;
		cin >> s;
		if(s == "PUSH"){
			cin >> k;
			st.push(k);
		}
		if(s == "PRINT"){
			if(st.empty()){
				cout << "NONE\n";
			}
			else{
				cout << st.top() << endl;
			}
		}
		if(s=="POP"){
			if(!st.empty()){
				st.pop();
			}
		}
	}
	return 0;
}

