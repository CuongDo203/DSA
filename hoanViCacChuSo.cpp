#include <bits/stdc++.h>
using namespace std;

int n, k; 
vector<string> v, res;
int x[101];
int diff = 1e9;

void sinh(){
	for(int i = 0; i < k; i++){
		x[i] = i;
	}
	while(1){
		for(int i = 0; i < n; i++){
			string tmp = "";
			for(int j = 0; j < k; j++){
				tmp+=v[i][x[j]];
			}
			res.push_back(tmp);
		}
		int maxx=-1e9, minn = 1e9;
		for(int i =0; i < res.size(); i++){
			if(maxx < stoi(res[i])){
				maxx=stoi(res[i]);
			}
			if(minn > stoi(res[i])){
				minn = stoi(res[i]);
			}
		}
//		cout << maxx << " " << minn << endl;
//		cout <<"*********\n";
		diff=min(diff, maxx-minn);
		res.clear();
		int i = k-2;
		while(i>=0 && x[i] > x[i+1]){
			i--;
		}
		if(i < 0){
			return;
		}
		else{
			int j = k-1;
			while(x[j] < x[i]){
				j--;
			}
			swap(x[i], x[j]);
			int l = i+1, r=k-1;
			while(l < r){
				swap(x[l], x[r]);
				l++;
				r--;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		v.push_back(s);
	}
	sinh();
	cout << diff << endl;
	return 0;
}

