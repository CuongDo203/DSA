#include <bits/stdc++.h>
using namespace std;


int a[1000001];
vector<long long> v;

void sinh(int n){
	string s(n,'0');
	s[n-1] = '9';
	while(1){
		v.push_back(stoll(s));
		int i = n-1;
		while(i>=0 && s[i] == '9'){
			s[i] = '0';
			i--;
		}
		if(i < 0){
			return;
		}
		else{
			s[i] = '9';
		}
	}
}

int main(){
	sinh(18);
	long long ans[501];
	for(int i = 1; i <= 500; i++){
		for(auto x : v){
			if(x%i==0){
				ans[i] = x;
				break;
			}
		}
	}
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << ans[n] << endl;
	}
	return 0;
}
