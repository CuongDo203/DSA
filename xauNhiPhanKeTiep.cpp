#include <bits/stdc++.h>
using namespace std;

void sinh(string s){   
    int i = s.size()-1;
    while(s[i] == '1'){
            s[i] = '0';
            i--;
        }
    if(i < 0){
        for(int j = 0; j < s.size(); j++){
            s[j] = '0';
        }
    }
    else{
        s[i] = '1';
    }
    cout << s << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		sinh(s);
	}
	return 0;
}
