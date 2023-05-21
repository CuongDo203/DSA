#include <bits/stdc++.h>
using namespace std;

string s = "";
vector<string> v;
int n, k;
void sinh(){
	for(int i = 0; i < k; i++){
		s+= char(i + 'A');
	}
	while(1){
		cout << s << endl;
		int i = s.size()-1;
		while(i >= 0 && s[i] == (char)((n-k+i)+'A')){
			i--;
		}
		if(i < 0){
			break;
		}
		else{
			s[i]++;
			for(int j = i+1; j < k; j++){
				s[j] = s[j-1]+1;
			}
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		sinh();
	} 
	return 0;
}
