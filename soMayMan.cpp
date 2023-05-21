#include <bits/stdc++.h> 
using namespace std; 

int main() { 
	ios::sync_with_stdio(0); 
	cin.tie(0); 
	cout.tie(0); 
	int t; 
	cin >> t; 
	while (t--) { 
		int n; 
		cin >> n; 
		bool ok = false;
		int choice = n/7;
		for(int i = choice; i >= 0; i--){
			int remain = n - 7*i; //chon i so 7
			if(remain %4 ==0){
				ok = true;
				for(int j = 0; j < remain/4; j++){
					cout << "4";
				}
				for(int j = 0; j < i; j++){
					cout << "7";
				}
				cout << endl;
				break;
			}
		} 
		if(!ok) cout << "-1\n";
	} 
	return 0; 
}
