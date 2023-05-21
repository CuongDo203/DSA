#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; 
	cin >> t;
    while (t--) {
        int n, m, k, x;
	    cin >> n >> m >> k;
	    vector<int> a;
	    for (int i = 0; i < n + m; ++i) {
	        cin >> x;
	        a.push_back(x);
	    }
	    sort(a.begin(), a.end());
	    cout << a[k - 1] << endl;
    }
    return 0;
}
