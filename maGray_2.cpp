#include <bits/stdc++.h>
using namespace std;

string graytoBinary(string gray)
{
    string binary = "";
    binary += gray[0];
    for (int i = 1; i < gray.length(); i++) {
        if (gray[i] == '0')
            binary += binary[i - 1];
        else
            if(binary[i-1] == '0')
            	binary+='1';
            else
            	binary+='0';
    }
    return binary;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		string g;
		cin >> g;
		cout << graytoBinary(g) << endl;
	}
	return 0;
}
