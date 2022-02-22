#include<iostream>
#include<stdlib.h>
#include<climit>
using namespace std;

int minJumps(int arr[], int n){
	int res[n];
        res[0] = 0;
        if(arr[0] == 0){
		// check if there is only one element in the array
                if(n == 1)
                    return 0;
                else
		    // if there are >1 element and the arr[0] = 0
		    // then none of the other elements could be reached
                    return -1;
        }
        for(int i = 1; i<n; i++){
                res[i] = INT_MAX;
        }
        int i = 0;
        int cnt=0;
        while(i<n){
            for(int j=i+1; j<= (i+arr[i]); j++){
                
                if(j>=n){
                    if(res[n-1] == INT_MAX)
                        return -1;
                    else
                        return res[n-1];
                }
                 res[j] = min(res[j], res[i] + 1);
            }
             i+= 1;
            
        }
        if(res[n-1] == 2147483647){
            res[n-1] = -1;
        }
        return res[n-1];
}


