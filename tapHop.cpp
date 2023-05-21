#include <bits/stdc++.h>
using namespace std;

int x[101];
int cnt = 0;
int n, k , s;

void check(){
	long long sum = 0;
	for(int i = 1; i <= k; i++){
		sum += x[i];
	}
	if(sum == s)
		cnt++;
}

void Dq(int i){
	for (int j = x[i - 1] + 1; j <= n - k + i; ++j) {
        x[i] = j;
        if (i == k) check();
        else Dq(i + 1);
    }
}

int main(){
	while(1){
		cin >> n >> k >> s;
		if(n == 0 && k == 0 && s==0)
			break;
		Dq(1);
		cout << cnt << endl;
		memset(x,0,sizeof(x));
		cnt=0;
	}
	return 0;
}
