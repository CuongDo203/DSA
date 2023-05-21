#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        deque<int> dq;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            while (!dq.empty() && a[i] >= a[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (dq.front() <= i - k) {
                dq.pop_front();
            }
            if (i >= k - 1) {
                cout << a[dq.front()] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

//int main(){
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int t;
//	cin >> t;
//	while(t--){
//		int n, k;
//		cin >> n >> k;
//		int a[n];
//		for(int i = 0; i < n; i++){
//			cin >> a[i];
//		}
//		for(int i = 0; i < n-k+1; i++){
//			cout << *max_element(a+i,a+k+i) << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}
