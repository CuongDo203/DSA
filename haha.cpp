#include <bits/stdc++.h>
using namespace std;
int n;
bool check(string a){
	if(!(a[0] == 'H' && a[n-1] == 'A'))
		return false;
	for(int i = 0; i < a.size()-1; i++){
		if(a[i] == 'H' && a[i+1] == 'H')
			return false;
	}
	return true;
}
void sinh(){
	string s(n, 'A');
	while(1){
		if(check(s))
			cout << s << endl;
		int i = s.size()-1;
		while(i >= 0 && s[i] == 'H'){
			s[i] = 'A';
			i--;
		}
		if(i < 0){
			break;
		}
		else{
			s[i] = 'H';
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		sinh();
	}
	return 0;
}
