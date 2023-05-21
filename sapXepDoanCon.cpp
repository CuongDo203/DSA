#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int n, a[MAXN], left_max[MAXN], right_min[MAXN];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    left_max[1] = a[1];
    for (int i = 2; i <= n; i++) {
        left_max[i] = max(left_max[i - 1], a[i]);
    }

    right_min[n] = a[n];
    for (int i = n - 1; i >= 1; i--) {
        right_min[i] = min(right_min[i + 1], a[i]);
    }

    vector<int> ans;
    for (int i = 1; i <= n - 1; i++) {
        if (left_max[i] <= right_min[i + 1]) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for(auto x : ans){
    	cout << x << ' ';
	}
    cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

