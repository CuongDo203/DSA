#include <bits/stdc++.h>
using namespace std;

int main() { 
	int t;
	cin >> t;
	while(t--){
		int s, d;
	    cin >> s >> d;
	    string res="";
	    bool ok = 1;
	    if(s > 9*d){
	        ok = 0;
	    }
    	while(d--){
	        if(s > 9){
	            res = "9"+res;
	            s-=9;
	        }
	        else{
	            if(d==0)
	            	res = to_string(s) + res;
	            else
					res = to_string(s-1)+res;
	            s = 1;
	        }
	    }
	    if(ok)
	    	cout << res << endl;
		else
			cout << "-1\n";	
	}
    return 0;
}

