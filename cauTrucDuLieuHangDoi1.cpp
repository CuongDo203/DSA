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
		queue<int> q;
		while(n--){
			int choice;
			cin >> choice;
			switch (choice){
				case 1:
					cout << q.size() << endl;
					break;
				case 2:
					if(q.empty()) cout << "YES\n";
					else cout << "NO\n";
					break;
				case 3:
					int x; cin >> x;
					q.push(x);
					break;
				case 4:
					if(!q.empty()) q.pop();
					break;
				case 5:
					if(!q.empty()) cout << q.front() << endl;
					else cout << "-1\n";
					break;
				case 6:
					if(!q.empty()) cout << q.back() << endl;
					else cout << "-1\n";
					break; 
			} 
		}
	}
	return 0;
}

