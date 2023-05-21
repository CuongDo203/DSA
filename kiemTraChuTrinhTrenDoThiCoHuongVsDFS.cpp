//#include <bits/stdc++.h>
//using namespace std;
//
//int n, m;
//vector<int> ke[1005];
//bool visited[1005];
//stack<int> st;
//
//void input(){
//	memset(ke,0,sizeof(ke));
//	memset(visited, false, sizeof(visited));
//	cin >> n >> m;
//	for(int i = 0; i < m; i++){
//		int x, y;
//		cin >> x >> y;
//		ke[x].push_back(y);
//	}
//}
//
//bool dfs(int u){
//	st.push(u);
//	while(!st.empty()){
//		int x = st.top();
//		st.pop();
//		if(visited[x]){
//			return true;
//		}
//		visited[x] = true;
//		for(auto v : ke[x]){
//			if(!visited[v]){
//				st.push(v);
//			}
//		}
//	}
//	return false;
//}
//
//void solve(){
//	memset(visited, false, sizeof(visited));
//	for(int i = 1; i <= n; i++){
//		if(!visited[i]){
//			if(dfs(i)){
//				cout << "YES\n";
//				return;
//			}
//		}
//	}
//	cout << "NO\n";
//}
//
//int main(){
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int t;
//	cin >> t;
//	while(t--){
//		input();
//		solve();
//	}
//	return 0;
//}


#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool DFS(vector<int> graph[], int start, vector<bool>& visited, vector<bool>& stack_recursion) {
    visited[start] = true;
    stack_recursion[start] = true;
    for (int neighbor : graph[start]) {
        if (!visited[neighbor] && DFS(graph, neighbor, visited, stack_recursion)) {
            return true;
        }
        else if (stack_recursion[neighbor]) {
            return true;
        }
    }
    stack_recursion[start] = false;
    return false;
}

bool hasCycle(vector<int> graph[], int n) {
    vector<bool> visited(n+1, false);
    vector<bool> stack_recursion(n+1, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && DFS(graph, i, visited, stack_recursion)) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> graph[n+1];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    if (hasCycle(graph, n)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}


