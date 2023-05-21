#include <bits/stdc++.h>
using namespace std;

int n, k;
set<string> se;
vector<string> v;
set<string> s1;
void Dq(int pos, string s, int cnt){
	if(cnt==k){
		s1.insert(s);
		return;
	}
	else{
		for(int j = pos; j < v.size(); j++){
			if(cnt <= k){
				cnt++;
				string tmp = s  + v[j] + " ";
				Dq(j+1, tmp, cnt);
				cnt--;
				tmp = s; 
			}
		}
	}
	
}

int main(){
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		se.insert(s);
	}
	for(auto x : se){
		v.push_back(x);
	}
	string s = "";
	Dq(0,s, 0);
	for(auto x : s1){
		cout << x << endl;
	}
	return 0;
}
