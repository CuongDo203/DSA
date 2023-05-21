#include <bits/stdc++.h>
using namespace std;

char c; 
int k;

void Dq(int pos, string s){
	if(s.size() == k){
		cout << s << endl;
		return;
	}
	else{
		for(int j = pos; j <= c-'A'; j++){
			s+=char(j+'A');
			Dq(j, s);
			s.pop_back();
		}
	}
}

int main(){
	cin >> c >> k;
	Dq(0,"");
	return 0;
}
