#include <bits/stdc++.h>
using namespace std;

int s, p, n;
int x[101];
vector<int> prime;
vector<int> res;
vector<vector<int>> v;

int nt(int n){
	for(int i = 2; i <= sqrt(n); i++){
		if(n%i==0){
			return false;
		}
	}
	return n>1;
}

void Dq(int i, int pos, int sum){
	for(int j = pos; j < prime.size(); j++){
		if(sum + prime[j] <= s){
			res.push_back(prime[j]);
			sum+=prime[j];
			if(sum == s && i == n){
//				for(int h = 0; h < res.size(); h++){
//					cout << res[h] << " ";
//				}
				v.push_back(res);
			}
			else{
				Dq(i+1, j+1, sum);
			}
			sum-=prime[j];
			res.pop_back();
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> n >> p >> s;
		for(int i = p+1; i <= s; i++){
			if(nt(i)){
				prime.push_back(i);
			}
		}
		Dq(1,0,0);
		cout << v.size() << endl;
		for(auto it : v){
			for(int i = 0; i < it.size(); i++){
				cout << it[i] << " ";
			}
			cout << endl;
		}
		prime.clear();
		res.clear();
		v.clear();
	}
	return 0;
}

