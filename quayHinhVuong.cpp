#include <bits/stdc++.h>
using namespace std;

vector<int> quayPhai(vector<int> a){
	vector<int> res(6);
	res[0] = a[3]; res[1] = a[0]; res[2] = a[2];
	res[3] = a[4]; res[4] = a[1]; res[5] = a[5];
	return res;
}

vector<int> quayTrai(vector<int> a){
	vector<int> res(6);
	res[0] = a[0]; res[1] = a[4]; res[2] = a[1];
	res[3] = a[3]; res[4] = a[5]; res[5] = a[2];
	return res;
}

bool check(vector<int> a, vector<int> b){
	for(int i = 0; i < 6; i++){
		if(a[i] != b[i]) return false;
	}
	return true;
}

void bfs(vector<int> a, vector<int> b){
	queue<pair<vector<int>, int>> q;
	q.push({a,0});
	set<vector<int>> se;
	se.insert(a);
	while(!q.empty()){
		pair<vector<int>, int> top = q.front();
		q.pop();
		if(check(top.first, b)){
			cout << top.second << endl;
			return;
		}
		vector<int> trai = quayTrai(top.first);
		if(!se.count(trai)){
			q.push({trai, top.second+1});
			se.insert(trai);
		}
		vector<int> phai = quayPhai(top.first);
		if(!se.count(phai)){
			q.push({phai, top.second+1});
			se.insert(phai);
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
		vector<int> a(6);
		for(int i = 0; i < 6; i++){
			cin >> a[i];
		}
		vector<int> b(6);
		for(int i = 0; i < 6; i++){
			cin >> b[i];
		}
		bfs(a,b);
	}	
	return 0;
}

