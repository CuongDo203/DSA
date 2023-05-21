#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
	vector<string> v;
    while(t--){
    	string s;
    	cin >> s;
    	for(int i = 0; i < s.size(); i++){
    		if(isalpha(s[i])){
    			s[i] = ' ';
			}
		}
		string tmp;
		stringstream ss(s);
		while(ss >> tmp){	
			while(tmp[0] == '0'){
				tmp.erase(tmp.begin());
			}
			if(tmp.size()==0){
				v.push_back("0");
			}
			else{
				v.push_back(tmp);
			}
		}
	}
	sort(v.begin(), v.end(), [](string a, string b)->bool{
		if(a.size()==b.size())
			return a < b;
		return a.size() < b.size();
	});
	for(auto x : v){
		cout << x << endl;
	}
	return 0;
}
