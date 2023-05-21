#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n];
	for(auto &x : a) cin >> x;
	for (int i = 1; i < n; ++i) {
        bool ok = true;
        for (int j = 0; j < n - i; ++j) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                ok = false;
            }
        }
        if (ok) break;
        cout << "Buoc " << i << ": ";
        for (int j = 0; j < n; ++j) {
            cout << a[j] << " ";
        }
        cout << endl;
    }
	return 0;
}
