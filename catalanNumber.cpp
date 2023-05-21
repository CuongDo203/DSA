#include <bits/stdc++.h>
using namespace std;

string a[105];

string add(string a, string b){
	while(a.size() < b.size()){
		a = "0" + a;
	}
	while(b.size() < a.size()){
		b = "0" + b;
	}
	string res = "";
	int nho = 0;
	for(int i = a.size()-1; i >= 0; i--){
		int tmp = (a[i]-'0') + (b[i] - '0') + nho;
		nho = tmp/10;
		tmp%=10;
		res = char(tmp + '0') + res;
	}
	if(nho>0){
		res = char(nho + '0') + res;
	}
	return res;
}

string mul(string s1, string s2){
	int len1  = s1.size();
	int len2 = s2.size();
	int len = len1 + len2;
	vector<int> a, b;
	for(int i = 0; i < len1; i++){
		a.push_back(s1[i] - '0');
	} 
	for(int i = 0; i < len2; i++){
		b.push_back(s2[i] - '0');
	} 
	vector<vector<int>> res(len2);
	
	int idx = 0;
	for(int i = len2-1; i >= 0; i--){
		int t = 0;
		while(t < idx){
			res[idx].push_back(0);
			t++;
		}
		int nho = 0, so = 0;
		for(int j = len1-1; j >= 0; j--){
			so = a[j]*b[i] + nho;
			res[idx].push_back(so%10);
			nho = so/10;
		}
		if(nho>0) res[idx].push_back(nho);
		while(res[idx].size() < len){
			res[idx].push_back(0);
		}	
		reverse(res[idx].begin(), res[idx].end());
		idx++;
	}
	
	int nho = 0;
	string ans = "";
	for(int j = res[0].size()-1; j>= 0; j--){
		int so = nho;
		for(int i = 0; i < res.size(); i++){ //xet tung hang 1
			so += res[i][j];
		}
		ans = char(so%10 + '0') + ans;
		nho = so/10;
	}
	if(nho>0) ans = char(nho+'0') + ans;
	while(ans[0] == '0') ans.erase(ans.begin());
	return ans;
}

void init(){
	a[0] = "1";
	a[1] = "1";
	for(int i = 2; i <= 100; i++){
		string tmp = "";
		for(int j = 0; j < i; j++){
			//string t1 = "0";
			tmp = add(tmp, mul(a[j], a[i-j-1]));
		}
		a[i] = tmp;
	}	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	init();
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << a[n] << endl;
	}
	return 0;
}

