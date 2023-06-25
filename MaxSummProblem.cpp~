#include<iostream>


int maxSum( int n){
	int summ;
	if(n == 0)
		return 0;
	summ = max(n/2, maxSum(n/2)) + max(n/3, maxSum(n/3)) + max(n/4, maxSum(n/4));
	return summ;
}
