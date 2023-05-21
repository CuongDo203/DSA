#include <bits/stdc++.h>
using namespace std;

string s;
bool ok = false;

bool check(){
	int x = stoi(s.substr(0, 2));
	int y = stoi(s.substr(5,2));
	int z = stoi(s.substr(10, 2));
	if(x < 10 || y < 10 || z < 10)
		return false;
	if(s[3] == '+'){
		return x+y==z;
	}
	else{
		return x-y==z;
	}
}

void Dq(int i){
	if(ok) return;
	if(i==s.size()){
		if(check()){
			cout << s;
			ok=true;
		}
		return;
	}
	if(s[i] == '?'){
		if(i == 0 || i == 5 || i==10){
			for(int j = 1; j <= 9; j++){
				s[i] = j + '0';
				Dq(i+1);
			}
		}
		if(i == 3){
			for(int j = 0; j <= 1; j++){
				if(j==0){
					s[i] = '+';
					Dq(i+1);
				} 
				else{
					s[i] = '-';
					Dq(i+1);
				}
			}
		}
		for(int j = 0; j <= 9; j++){
			s[i] = j + '0';
			Dq(i+1);
		}
		s[i] = '?';
	}
	else
		Dq(i+1);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	cin.ignore();
	while(t--){
		getline(cin,s);
		if(s[3] == '/' || s[3] == '*'){
			cout << "WRONG PROBLEM!\n";
			continue;
		}
		Dq(0);	
		if(!ok){
			cout << "WRONG PROBLEM!";
		}
		cout << endl;
		ok=false;
	}
	return 0;
}

