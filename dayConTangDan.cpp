#include <bits/stdc++.h>
using namespace std;

int n;
int a[105];
int x[105];
vector<string> v;

void Dq(int i, int pos){
	for(int j = pos; j <= n; j++){
		if(a[j] > x[i-1]){
			x[i] = a[j];
			if(i >= 2){
				string tmp = "";
				for(int k = 1; k <= i; k++){
					tmp += to_string(x[k]);
					tmp += " ";
				}
				v.push_back(tmp);
			}
			Dq(i+1,j+1);
		}
	}
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	Dq(1,1);
	sort(v.begin(), v.end());
	for(auto x : v){
		cout << x << endl;
	}
	return 0;
}
