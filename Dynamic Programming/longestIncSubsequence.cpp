/*
 * Problem : Given an array find the length of longest(strictly) increasing subequence
 *
 * Approach : Since the overall solution is sum of overlapping subproblems we use DP
 * 1. make all 1 as they in themselves are a subsequence
 * 2. calculate the max length upto each index
 * 
 * f(n)  = 1 + max(f(1), f(2), .... , f(n-1)*/

class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
	    int currentIndex, iterator;
	    int subseqLength[n];
	    int maxLength = 0;
	    for(int i = 0; i<n; i++){
		    // Since all element in themself are a subsequence they hold value 1
		    subseqLength[i] = 1;
	    }

	    // calculate longest subsequence length upto each index
	    for(currentIndex = 0; currentIndex < n; currentIndex++){
		    // compare with all the element before it
		    for(iterator = 0 ; iterator < currentIndex; iterator++){
			    if(a[currentIndex] > a[iterator]){
				    subseqLength[currentIndex] = max(subseqLength[currentIndex], subseqLength[iterator] + 1);
			    }
		    }
	    }
	    // calculate the maximum of all subsequence length
	    for(int i = 0; i<n; i++){
		    maxLength = max(maxLength, subseqLength[i]);
	    }

	    return maxLength;
    
    }
};
