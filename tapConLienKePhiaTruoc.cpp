#include <bits/stdc++.h>
using namespace std;

int x[1001];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        for(int i = 1; i <= k; i++){
            cin >> x[i];
        }
        x[0] = 0;
        bool ok = true;
        for(int i = k; i >= 1; i--){
            if(x[i] != x[i-1]+1){
                x[i]--;
                ok = false;
                if(x[k] != n){
                    for(int j = i+1; j <= k; j++){
                        x[j]++;
                    }
                }
                break;  
            }
        }
        if(ok && x[1] == 1){
            for(int i = 1; i <= k; i++){
                cout << n-k+i << ' ';
            }
        }
        else{
            for(int i = 1; i <= k; i++){
                cout << x[i] << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}
