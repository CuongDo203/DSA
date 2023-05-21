#include <bits/stdc++.h>
using namespace std;

void next_distinct(vector<int> &a, int &x){ 
	do{
		x++;
	}while(x  < a.size() && a[x-1] == a[x]);
}

void printUnion(vector<int> a, vector<int> b){
	int i = 0, j = 0;
	while(i < a.size() && j < b.size()){
		if(a[i] < b[j]){
			cout << a[i] << " ";
			next_distinct(a,i);
		}
		else if(a[i] > b[j]){
			cout << b[j] << " ";
			next_distinct(b,j);
		}
		else{
			cout << a[i] << " ";
			next_distinct(a,i);
			next_distinct(b,j);
		}
	}
	while(i < a.size()){
		cout << a[i] << " ";
		next_distinct(a,i);
	}
	while(j < b.size()){
		cout << b[j] << " ";
		next_distinct(b,j);
	}
}

void printIntersection(vector<int> a, vector<int> b){
	int i = 0, j = 0;
	while(i < a.size() && j < b.size()){
		if(a[i] < b[j]){
			i++;
		}
		else if(a[i] > b[j]){
			j++;
		}
		else{
			cout << b[j] << " ";
			i++;
			j++;
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<int> v1(n);
		vector<int> v2(m);
		for(int i = 0; i < n; i++){
			cin >> v1[i];
		}
		for(int i = 0; i < m; i++){
			cin >> v2[i];
		}
		printUnion(v1,v2);
		cout << endl;
		printIntersection(v1,v2);
		cout << endl;
	}
	return 0;
} 
