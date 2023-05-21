#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[10001];
set<int> se;

void sinh(){
	memset(a,0, sizeof(a));
	se.clear(); 
    for(int i = 1; i <= k; i++){
        cin >> a[i];
        se.insert(a[i]);
    }
    int i = k;
    while(i >= 1 && a[i] == n-k+i){
        i--;
    }
    if(i < 1){
        cout << k << endl;
        return;
    }      
    else{
        a[i]++;
        for(int j = i+1; j <= k; j++){
            a[j] = a[j-1]+1;
        }
    }
    int cnt = 0;
    for(int j = 1; j <= k; j++){
        if(se.count(a[j]) == 0){
        	cnt++;
		}
    }
    cout << cnt << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		sinh();
	}
	return 0;
}
