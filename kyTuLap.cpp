#include <bits/stdc++.h>
using namespace std;

int n, ans = 1e9;
string res[15], tmp[15];
bool used[20], ok = false;

void Dq(int i, int cnt){	
	if(i>n){
		ans = min(ans, cnt);
		ok = true;
		cout << cnt << " " << ans << endl;
		return;
	}
	for(int j = 1; j <= n; j++){
		if(!used[j]){
			tmp[i] = res[j];
			used[j] = 1;
			int dem=0;
			int l = 0, r = 0;
			while(l < tmp[i].size() && r < tmp[i-1].size()){
				if(tmp[i][l] < tmp[i-1][r]){
					l++;
				}
				else if(tmp[i-1][r] < tmp[i][l]){
					r++;
				}
				else{
					dem++;
					l++;
					r++;
				}
			}
			if(cnt + dem < ans)
				Dq(i+1, cnt+dem);
			used[j] = 0;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> res[i];
	}
	Dq(1,0);
	cout << ans << endl;
	return 0;
}

