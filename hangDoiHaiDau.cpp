#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	deque<int> dq;
	while(t--){
		string s;
		cin >> s;
		if(s == "PUSHBACK"){
			int x;
			cin >> x;
			dq.push_back(x);
		}	
		else if(s == "PUSHFRONT"){
			int x;
			cin >> x;
			dq.push_front(x);
		}
		else if(s == "PRINTFRONT"){
			if(dq.empty()) cout << "NONE\n";
			else cout << dq.front() << endl;
		}
		else if(s == "PRINTBACK"){
			if(dq.empty()) cout << "NONE\n";
			else cout << dq.back() << endl;
		}
		else if(s == "POPFRONT"){
			if(!dq.empty()) dq.pop_front();
		}
		else{
			if(!dq.empty()) dq.pop_back();
		}
	}
	return 0;
}

