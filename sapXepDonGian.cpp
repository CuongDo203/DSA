#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;
    int f[n + 1] = {};
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        f[x] = f[x - 1] + 1;
    }
    cout << n - *max_element(f + 1, f + 1 + n);
	return 0;
}
