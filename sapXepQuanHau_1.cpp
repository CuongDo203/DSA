#include <bits/stdc++.h>
using namespace std;

int x[100], cot[100], xuoi[100], nguoc[100];
int cnt = 0;
int n;
void Dq(int i){
	for(int j = 1;  j <= n; j++){
		if(cot[j] == 0 && xuoi[i-j+n] == 0 && nguoc[i+j-1] == 0){
			x[i] = j;
			cot[j] = xuoi[i-j+n] = nguoc[i+j-1] = 1;
			if(i == n){
				cnt++;
			}
			else{
				Dq(i+1);
			}
			cot[j] = xuoi[i-j+n] = nguoc[i+j-1] = 0;
		}
	}
}

void Test(){
	cin >> n;
	Dq(1);
	cout << cnt << endl;
	cnt = 0;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		Test();
	}
	return 0;
}
