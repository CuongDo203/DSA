#include <bits/stdc++.h>
using namespace std;

vector<int> quay1(vector<int> a){
	vector<int> tmp(10);
	tmp[0] = a[3]; tmp[1] = a[0]; tmp[2] = a[2]; tmp[3] = a[7];
	tmp[4] = a[4]; tmp[5] = a[1]; tmp[6] = a[6]; tmp[7] = a[8];
	tmp[8] = a[5]; tmp[9] = a[9];
	return tmp;
}

vector<int> quay2(vector<int> a){
	vector<int> tmp(10);
	tmp[0] = a[0]; tmp[1] = a[4]; tmp[2] = a[1]; tmp[3] = a[3];
	tmp[4] = a[8]; tmp[5] = a[5]; tmp[6] = a[2]; tmp[7] = a[7];
	tmp[8] = a[9]; tmp[9] = a[6];
	return tmp;
}

vector<int> quay3(vector<int> a){
	vector<int> tmp(10);
	tmp[0] = a[1]; tmp[1] = a[5]; tmp[2] = a[2]; tmp[3] = a[0];
	tmp[4] = a[4]; tmp[5] = a[8]; tmp[6] = a[6]; tmp[7] = a[3];
	tmp[8] = a[7]; tmp[9] = a[9];
	return tmp;
}

vector<int> quay4(vector<int> a){
	vector<int> tmp(10);
	tmp[0] = a[0]; tmp[1] = a[2]; tmp[2] = a[6]; tmp[3] = a[3];
	tmp[4] = a[1]; tmp[5] = a[5]; tmp[6] = a[9]; tmp[7] = a[7];
	tmp[8] = a[4]; tmp[9] = a[8];
	return tmp;
}

void solve(){
	vector<int> a(10);
	vector<int> b = {1,2,3,8,0,0,4,7,6,5};
	for(int i = 0; i < 10; i++){
		cin >> a[i];
	}
	queue<pair<vector<int>, int>> q1, q2;
	q1.push({a, 0});
	q2.push({b, 0});
	map<vector<int>, int> mp;
	int ans = 1e9;
	while(!q1.empty()){
		pair<vector<int>, int> top = q1.front();
		q1.pop();
		vector<int> left = quay1(top.first);
		
		if(mp[left] == 0){
			mp[left] = top.second+1;
			q1.push({left, top.second+1});
		}
		
		vector<int> right = quay2(top.first);
		if(mp[right] == 0){
			mp[right] = top.second + 1;
			q1.push({right, top.second+1});
		}
		if(top.second + 1 == 14){
			break;
		}
	}
	while(!q2.empty()){
		pair<vector<int>, int> top = q2.front();
		q2.pop();
		if(mp[top.first]){
			ans = min(ans, mp[top.first]+top.second);
		}
		vector<int> left = quay3(top.first);
		q2.push({left, top.second+1});
		
		vector<int> right = quay4(top.first);
		q2.push({right, top.second+1});
		if(top.second+1==14){
			break;
		}
	}
	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		solve();
	}	
	return 0;
}

