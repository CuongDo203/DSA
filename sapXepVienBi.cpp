#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	map<char,int> mp;
	for(auto &x : s){
		mp[x]++;
	}
	//xu li X
	int step = 0;
	for(int i = 0; i < mp['X']; i++){
		if(s[i] == 'T'){
			for(int j = mp['X']; j < n; j++){
				if(s[j] == 'X'){
					swap(s[i], s[j]);
					step++;
					break;
				}
			}
		}
		else if(s[i] == 'D'){
			for(int j = n-1; j >= mp['X']; j--){
				if(s[j] == 'X'){
					swap(s[i], s[j]);
					step++;
					break;
				}
			}
		}
	}
	//xu li T
	for(int i = mp['X']; i < mp['X']+mp['T']; i++){
		if(s[i] == 'D'){
			for(int j = mp['X']+mp['T']; j < n; j++){
				if(s[j] == 'T'){
					swap(s[i], s[j]);
					step++;
					break;
				}
			}
		}
	}
	cout << step << endl;
	return 0;
} 
