#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int n, m;
int p[MAXN], sz[MAXN];
vector<pair<int,int>> v;

void init(){
	memset(p,0,sizeof(p));
	memset(sz,0,sizeof(sz));
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        p[i] = i;
        sz[i] = 1;
    }
}

int find(int u){
    if(u == p[u])
        return u;
    else{
        p[u] = find(p[u]);
        return p[u];
    }
}

bool Union(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) return true;
    if(sz[u] < sz[v]){
        sz[v] += sz[u];
        p[u] = v;
    }
    else{
        sz[u] += sz[v];
        p[v] = u;
    }
    return false;
}

void solve(){
	bool ok = false;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
		v.push_back({x,y});
    }
    for(auto it : v){
    	if(Union(it.first, it.second)){
    		ok = true;
    		break;
		}
	}
	if(ok)
		cout << "YES\n";
	else
		cout << "NO\n";
	v.clear();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;  
    cin >> t;
    while(t--){ 
        init();
        solve();
    }
    return 0;
}

