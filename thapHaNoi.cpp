#include <bits/stdc++.h>
using namespace std;

void HaNoi_Tower(int n, char a, char b, char c){
	if(n==1){
		cout << a << " -> " <<  c << endl;
	}
	else{
		HaNoi_Tower(n-1, a, c, b);
		HaNoi_Tower(1, a, b, c);
		HaNoi_Tower(n-1, b, a, c);
	}
}

int main(){
	int n;
	cin >> n;
	HaNoi_Tower(n, 'A', 'B', 'C');
	return 0;
}
