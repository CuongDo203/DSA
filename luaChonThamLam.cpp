#include <bits/stdc++.h>
using namespace std;

string maxNumber(int n, int s){
	int sl = n, sum = s;
	if(9*sl < sum) return "-1";
	if(sum==0){
		if(sl==1) return "0";
		else return "-1";
	} 
	string res = "";
	while(sum>9){
		res += "9";
		sum-=9;
	}
	if(sum!=0){
		res+=to_string(sum);
	}
	while(res.size() < sl){
		res += "0";
	}
	return res;
}

string minNumber(int n, int s){
	int sl = n, sum = s;
	if(9*sl < sum) return "-1";
	if(sum==0){
		if(sl==1) return "0";
		else return "-1";
	} 
	string res = "";
	while(sl--){
		if(sum>9){
			res="9"+res;
			sum-=9;
		}
		else{
			if(sl==0){
				res = to_string(sum) + res;
			}
			else{
				res = to_string(sum-1) + res;
			}
			sum=1;
		}
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	//cin >> t;
	while(t--){
		int n, s;
		cin >> n >> s;
		cout << minNumber(n,s) << " " << maxNumber(n,s) << endl;
	}	
	return 0;
}

