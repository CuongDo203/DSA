#include <bits/stdc++.h>
using namespace std;

void sinh(string s){
	while(1){
		cout << s << " ";
		int i = s.size()-2;
		while(i >= 0 && s[i] > s[i+1]){
			i--;
		}
		if(i < 0){
			break;
		}
		else{
			int j = s.size()-1;
			while(s[i] > s[j]){
				j--;
			}
			swap(s[i], s[j]);
			int l = i+1, r = s.size()-1;
			while(l < r){
				swap(s[l], s[r]);
				l++;
				r--;
			}
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		sinh(s);
		cout << endl;
	}
	return 0;
}
