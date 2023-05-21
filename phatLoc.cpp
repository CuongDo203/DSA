#include <bits/stdc++.h>
using namespace std;
string s;
int n;

bool check(){
    if(!(s[0] == '8' && s[s.size()-1] == '6'))
        return false;
    for(int i = 0; i < s.size(); i++){
        int cnt = 0;
        if(s[i] == '6'){
            while(s[i] == '6'){
                cnt++;
                i++;
            }
            if(cnt > 3){
                cnt = 0;
                return false;
            }
        }
        if(s[i] == '8' && s[i+1] == '8')
            return false;
    }
    return true;
}

void sinh(){
    for(int i = 0; i < n; i++){
        s.push_back('6');
    }
    while(1){
        if(check())
           cout << s << endl;
        int i = n-1;
        while(i >=0 && s[i] == '8'){
            s[i] = '6';
            i--;
        }
        if(i < 0)
           return;
        else{
           s[i] = '8';   
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cin >> n;
    sinh();
    return 0;
}

