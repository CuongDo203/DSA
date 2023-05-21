#include <bits/stdc++.h>
using namespace std;

int n, T[100], k, X[100], s, final;

void next(){
    int i = k;
    while(i >= 1 && X[i] == n - k + i){
        --i;
    }
    if(i < 1){
        final = 1;
    }
    else{
        X[i]++;
        for(int j = i+1; j <= k; j++){
            X[j] = X[j-1]+1;
        }
    }
}

int main(){
    cin >> n >> s;
    for(int i = 1; i <= n; i++){
        cin >> T[i];
    }
    sort(T+1, T+n+1, greater<int>());
    for(int i = 1; i <= n; i++){
        k = i;
        final = 0;
        for(int j = 1; j <= k; j++){   //khoi tao gia tri ban dau
            X[j] = j;
        }
        while(!final){
            int sum =0;
            for(int j = 1; j <= k; j++){
                sum += T[X[j]];
            }
            if(sum == s){
                cout << k << endl;
                return 0;
            }
            next();
        }
    }
    cout << "-1\n";
}
