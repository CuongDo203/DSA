#include <bits/stdc++.h>
using namespace std;

int n, k, cnt=0;
int a[1001], x[1001];

bool check(){
	long long sum = 0;
	for(int i = 0; i < n; i++){
		if(x[i] == 1){
			sum += a[i];
		}
	}
	if(sum == k)
		return 1;
	else
		return 0;
}

void sinh(){
	for(int i = 0; i < n; i++){
		x[i] = 0;
	}
	while(1){
		if(check()){
			cnt++;
			for(int i = 0; i < n; i++){
				if(x[i] == 1){
					cout << a[i] << ' ';
				}
			}
			cout << endl;
		}			
		int i = n-1;
		while(i >= 0 && x[i] == 1){
			x[i]=0;
			i--;
		}
		if(i < 0){
			break;
		}
		else{
			x[i] = 1;
		}
	}
	cout << cnt << endl;
}

int main(){
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sinh();
	return 0;
}
