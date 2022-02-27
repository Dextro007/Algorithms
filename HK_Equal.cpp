/*
 * Subtracting 1 from an employee is similar to adding 1 to all others
 * find the minimum value in the list of choclates
 * then calculate steps required to convert each employees choclate to the minimum value
 * the caveat is sometimes the actual minima is not the minimum value but in betn min and min-4
 * so calculate for all possible minimum value
 * */
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int equal(vector<int> arr){
	int allMin[5];
	int minima = *min_element(arr.begin(), arr.end());
	int stepsReq =0;
	int j=0;
	while(j<5){
		for(int i:arr){
			int diff = i - minima;
			stepsReq += (diff/5) + (diff % 5)/2 + (diff % 5)%2;
		}
		minima--;
		allMin[j] = stepsReq;
		stepsReq = 0;
		j++;
	}
	int minIndex = 0;
	int actualMin = allMin[0];
	for(int i = 1; i<5; i++){
		if(actualMin > allMin[i]){
			actualMin = allMin[i];
			minIndex = i;
		}
	}
	return allMin[minIndex];
}

	
