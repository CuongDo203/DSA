#include <bits/stdc++.h>
using namespace std;

string start, finish;

void bfs(multiset<string> ms){
	queue<pair<string, int>> q;
	q.push({start,0});
	while(!q.empty()){
		pair<string, int> top = q.front();
		q.pop();
		if(top.first == finish){
			cout << top.second+1 << endl;
			return;
		}
		for(int i = 0; i < top.first.size(); i++){
			char c = top.first[i];
			for(char j = 'A'; j <= 'Z'; j++){
				top.first[i] = j;
				if(ms.count(top.first)){
					q.push({top.first, top.second+1});
					ms.erase(top.first);	
				}
			}
			top.first[i] = c;
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
		int n;
		cin >> n;
		cin >> start >> finish;
		multiset<string> ms;
		for(int i = 0; i < n; i++){
			string s;
			cin >> s;
			ms.insert(s);
		}
		bfs(ms);
	}
	return 0;
}

