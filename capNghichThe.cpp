#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll merge(ll a[], int l, int m, int r){
	vector<int> v1(a+l, a+m+1);
	vector<int> v2(a+m+1, a+r+1);
	int i = 0, j = 0;
	ll cnt=0;
	while(i < v1.size() && j < v2.size()){
		if(v1[i] <= v2[j]){
			a[l++] = v1[i++];
		}
		else{
			cnt += (v1.size() - i);
			a[l++] = v2[j++];
		}
	}
	while(i < v1.size()){
		a[l++] = v1[i++];
	}
	while(j < v2.size()){
		a[l++] = v2[j++];
	}
	return cnt;
}

ll merge_sort(ll a[], int l, int r){
	if(l >= r)
		return 0;
	ll cnt = 0;
	int m = (l+r)/2;
	cnt += merge_sort(a,l,m);
	cnt += merge_sort(a,m+1, r);
	cnt += merge(a,l,m,r);
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		ll a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		cout << merge_sort(a,0,n-1) << endl;
	}
	return 0;
}

