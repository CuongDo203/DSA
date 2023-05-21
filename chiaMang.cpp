#include <bits/stdc++.h>
using namespace std;

int n, k, sum = 0;
int a[100];
int ok = 0;

void Dq(int pos, int s, int cnt){
	if(s > sum) return;
	if(ok) return;
	cout << s <<" " << cnt << endl;
	if(cnt == k){
		ok = 1;
		return;
	}
	for(int j = pos; j <= n; j++){
		if(s == sum){
			Dq(j+1,0, cnt+1);
		}
		else if(s < sum){
			Dq(j, s += a[j], cnt);		
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
		cin >> n >> k;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			sum += a[i];
		}
		if(sum % k != 0){
			cout << 0 << endl;
			sum = 0;
			continue;
		}
		else{
			sum/=k;
			Dq(1,0,0);
			cout << ok << endl;
		}
		sum = 0;
	}
	return 0;
}

