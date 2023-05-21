#include <bits/stdc++.h>
using namespace std;

string binaryToGray(string bin){
	string gray = "";
	gray += bin[0];
	for(int i = 1; i < bin.size(); i++){
		if(bin[i] == bin[i-1]){
			gray+='0';
		}
		else{
			gray+='1';
		}
	}
	return gray;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		cout << binaryToGray(s) << endl;
	}
	return 0;
}
