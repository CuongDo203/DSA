#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<string> v;

bool check(string s){
	int cnt = 0, res = 0;
	for(int i = 0; i < s.size(); i++){
		int j = i;
		while(s[j] == 'A'){
			cnt++;
			j++;
		}
		if(cnt > k){
			return false;
		}
		if(cnt==k){
			res++;
		}
		cnt=0;
	}
	return res == 1;
}

void sinh(){
	string s(n,'A');
	while(1){
		if(check(s)){
			v.push_back(s);
		}
		int i = s.size()-1;
		while(i >= 0 && s[i] == 'B'){
			s[i] = 'A';
			i--;
		}
		if(i < 0){
			break;
		}
		else{
			s[i] = 'B';
		}
	}
}

int main(){
	cin >> n >> k;
	sinh();
	cout << v.size() << endl;
	for(auto x : v){
		cout << x << endl;
	}
	return 0;
}
