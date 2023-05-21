#include <bits/stdc++.h>
using namespace std;

long long minn(string a, string b){
	for(int i = 0; i < a.size(); i++){
		if(a[i] == '6')
			a[i] = '5';
	}
	for(int i = 0; i < a.size(); i++){
		if(b[i] == '6')
			b[i] = '5';
	}
	long long res = stoll(a)+stoll(b);
	return res;
}

long long maxx(string a, string b){
	for(int i = 0; i < a.size(); i++){
		if(a[i] == '5')
			a[i] = '6';
	}
	for(int i = 0; i < b.size(); i++){
		if(b[i] == '5')
			b[i] = '6';
	}
	long long res = stoll(a)+stoll(b);
	return res;
}

int main(){
	string a, b;
	cin >> a >> b;
	cout << minn(a,b) << " " << maxx(a,b);
	return 0;
} 
