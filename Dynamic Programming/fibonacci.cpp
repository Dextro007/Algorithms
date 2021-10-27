#include<iostream>
#include<climits>
#include<vector>

using namespace std;

unsigned int calcMaxIncSubset(vector<int> arr){

}

int main(){
	
	int temp;
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i = 0; i<n;i++){
		cin>>temp;
		arr.push_back(temp);
	}
	cout<< calcMaxIncSubset(arr);
	return 0;

}
