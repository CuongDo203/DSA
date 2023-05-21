#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> odd;
	vector<int> even;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if((i+1)%2==1){
			odd.push_back(x);
		}
		else{
			even.push_back(x);
		}
	}
	sort(odd.begin(), odd.end());
	sort(even.begin(), even.end(), greater<int>());
	int i = 0, j=0;
	while(i < odd.size() && j < even.size()){
		cout << odd[i] << " " << even[j] << " ";
		i++;
		j++;
	}
	while(i < odd.size()){
		cout << odd[i] << " ";
		i++;
	}
	while(j < even.size()){
		cout << even[j] << " ";
		j++;
	}
	return 0;
} 
