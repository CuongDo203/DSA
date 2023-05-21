#include <bits/stdc++.h>
using namespace std;

void solve() {
    int k; string a, b;
    cin >> k >> a >> b;
    while (a.length() < b.length()) {
        a = "0" + a;
    }
    while (b.length() < a.length()) {
        b = "0" + b;
    }
    string s = ""; int nho = 0;
    for (int i = a.length() - 1; i >= 0; --i) {
        int dg = (a[i] - '0') + (b[i] - '0') + nho;
        s = char(dg % k + '0') + s;
        nho = dg / k;
    }
    if (nho > 0) s = char(nho + '0') + s;
    cout << s << endl;
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

