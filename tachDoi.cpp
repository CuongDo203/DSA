#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		if(s.size() % 2 == 1){
			cout << "INVALID\n";
		}
		else{
			int half = s.size()/2;
			string t1 = s.substr(0,half);
			string t2 = s.substr(half);
			long long s1 = stoll(t1);
			long long s2 = stoll(t2);
			long long res = (s1*s2)/__gcd(s1,s2);
			cout << res << endl;
		}
	}
	return 0;
}
