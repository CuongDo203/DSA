#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	stack<int> st;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(st.empty() || (st.top() + x) % 2 == 1){
			st.push(x);
		}
		else{
			st.pop();
		}
	}
	cout << st.size() << endl;
	return 0;
}

