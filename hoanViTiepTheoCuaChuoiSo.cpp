#include <bits/stdc++.h>
using namespace std;

void sinh(pair<int,string> p){
	string s = p.second;
	int stt = p.first;
	int i = s.size()-2;
	while(i >= 0 && s[i] >= s[i+1]){
		--i;
	}
	if(i < 0){
		cout <<stt << " BIGGEST";
		return;
	}
	else{
		int j = s.size()-1;
		while(s[j] <= s[i]){
			j--;
		}
		swap(s[i], s[j]);
		int l = i+1, r=s.size()-1;
		while(l < r){
			swap(s[l], s[r]);
			l++;
			r--;
		}
		cout <<stt <<" "<< s;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		pair<int, string> p;
		cin >> p.first >> p.second;
		sinh(p);
		cout << endl;
	}
	return 0;
} 
