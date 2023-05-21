#include <bits/stdc++.h>
using namespace std;

int n, x;
int a[100];
vector<int> res;
vector<string> v;

void Dq(int pos, int sum){
	for(int j = pos; j < n; j++){
		if(sum + a[j] <= x){
			res.push_back(a[j]);
			sum+=a[j];
			if(sum == x){
				string tmp = "[";
				for(int k = 0; k < res.size(); k++){
					tmp+=to_string(res[k]);
					if(k != res.size()-1){
						tmp += " ";
					}
					else{
						tmp += "]";
					}
				}
				v.push_back(tmp);
			}
			else{
				Dq(j, sum);
			}
			sum-=a[j];
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
		cin >> n >> x;
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		Dq(0,0);
		if(v.size()==0){
			cout << "-1\n";
		}
		else{
			for(auto it : v){
				cout << it ;
			}
			cout << endl;
		}
		v.clear();
		res.clear();
	}
	return 0;
}

