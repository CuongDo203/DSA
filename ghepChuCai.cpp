#include <bits/stdc++.h>
using namespace std;

char c;
string s;

bool nguyen_am(char a){
    return a=='A' || a=='E';
}

bool check(string a){
    for(int i = 1; i < a.size()-1; i++){
        if(nguyen_am(a[i]) && !nguyen_am(a[i-1]) && !nguyen_am(a[i+1]))
            return false;
    }
    return true;
}

void sinh(){
    for(char i = 0; i <= c-'A'; i++){
        s+=char('A' + i);
    }
    while(1){
        if(check(s))
            cout << s << endl;
        int i = s.size()-2;
        while(i >=0 && s[i] > s[i+1]){
            i--;
        }
        if(i < 0)
            return;
        else{
            int j = s.size()-1;
            while(s[j] < s[i]){
                j--;
            }
            swap(s[i], s[j]);
            int l = i+1, r = s.size()-1;
            while(l < r){
                swap(s[l], s[r]);
                l++;
                r--;
            }
        }
    }
}

int main() { 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin >> c;
    sinh();
    return 0;
}

