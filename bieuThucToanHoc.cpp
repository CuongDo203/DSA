#include <bits/stdc++.h>
using namespace std;

vector<int> a(5);
vector<int> num(5);
vector<int> sign(4);  // 1 la '+', 2 la '-', 3 la '*'
bool vs[5];
vector<vector<int>> So;
vector<vector<int>> Dau;

void nhap(){
	So.clear();
	Dau.clear();
	memset(vs, false, sizeof(vs));
	for(int i = 0; i < 5; i++){
		cin >> a[i];
	}
}

void DqSo(int i){
	for(int j = 0; j < 5; j++){
		if(!vs[j]){
			vs[j] = true;
			num[i] = a[j];
			if(i == 4){
				So.push_back(num);
			}
			else{
				DqSo(i+1);
			}
			vs[j] = false;
		}
	}
}

void DqDau(int i){
	if(i > 3){
		Dau.push_back(sign);
		return;
	}
	for(int j = 1; j <= 3; j++){
		sign[i] = j;
		DqDau(i+1);
	}
}

int tinh(int a, int b, int c){
	if(c == 1) return a+b;
	else if(c==2) return a-b;
	else if(c == 3) return a*b;
	return a/b;
}

bool check(vector<int> so, vector<int> dau){
	return tinh(tinh(tinh(tinh(so[0], so[1], dau[0]), so[2], dau[1]), so[3], dau[2]), so[4], dau[3]) == 23;
}

void solve(){
	for(auto i : So){
		for(auto j : Dau){
			if(check(i, j)){
				cout << "YES\n";
				return;
			}
		}
	}
	cout << "NO\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		nhap();
		DqSo(0);
		DqDau(0);
		solve();
	}
	return 0;
}

