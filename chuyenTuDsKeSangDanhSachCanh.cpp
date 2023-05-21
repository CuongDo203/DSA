#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int>> v;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	cin.ignore();
	for(int i = 1; i <= n; i++){
		string s;
		getline(cin, s);
		string tmp;
		stringstream ss(s);
		while(ss >> tmp){
			if(stoi(tmp) > i){
				v.push_back(make_pair(i, stoi(tmp)));
			}
		}		
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < v.size(); i++){
		cout << v[i].first << " " << v[i].second << endl;
	}
	v.clear();
	return 0;
}

