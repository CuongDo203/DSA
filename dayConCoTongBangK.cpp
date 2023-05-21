#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[1001], x[1001];
bool ok = false;

void Dq(int i, int sum, int idx){
    for(int j = idx; j < n; j++){
        if(sum+a[j] <= k){
            x[i] = a[j];
            sum+=x[i];
            if(sum==k){
            	ok = true;
                cout << "[";
                int r;
                for(r=1; r < i; r++){
                    cout << x[r] << ' ';
                }
                if(r==i)
                    cout << x[r] << "] ";
              
            }
            else{
                Dq(i+1,sum,j+1);
            }
            sum -=x[i];
        }
    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a, a+n);
		Dq(1,0,0);
		if(!ok){
			cout << "-1";
		}
		cout << endl;
		memset(x,0,sizeof(x));
	}
	return 0;
}
