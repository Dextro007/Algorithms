/*
Count of numbers from 0 to 9   = 1
Count of numbers from 0 to 99  = 1*9 + 10 = 19
Count of numbers from 0 to 999 = 19*9 + 100 = 271

In general, we can write
count(10^d) =   9 * count(10^(d - )1) + 10^(d - 1)

Then we calc MSD i.e Most significant decimal !st digit
 = number / 10^d

after that we have 2 cases and it is handles accordingly

1. MSD < 4
2. MSD = 4
3. MSD > 4

Approach :	1. DP (overlapping subproblems, memoization)
	  	2. Naive Approach 

1) Find number of digits minus one in n. Let this value be 'd'.
   For 328, d is 2.

2) Compute some of digits in numbers from 1 to 10d - 1.
   Let this sum be w. For 328, we compute sum of digits from 1 to
   99 using above formula.

3) Find Most significant digit (msd) in n. For 328, msd is 3.

4.a) If MSD is 4. For example if n = 428, then count of
     numbers is sum of following.
     1) Count of numbers from 1 to 399
     2) Count of numbers from 400 to 428 which is 29.

4.b) IF MSD > 4. For example if n is 728, then count of
     numbers is sum of following.
     1) Count of numbers from 1 to 399 and count of numbers
        from 500 to 699, i.e., "a[2] * 6"
     2) Count of numbers from 400 to 499, i.e. 100
     3) Count of numbers from 700 to 728, recur for 28
4.c) IF MSD < 4. For example if n is 328, then count of
     numbers is sum of following.
     1) Count of numbers from 1 to 299 a
     2) Count of numbers from 300 to 328, recur for 28
 * */
class Solution {
  public:
    int countNumberswith4(int N) {
	    // if number is smaller than 4
	    if(N<4){
		    return 0;
	    }
	    // denotes the power of 10th
	    int retVal = 0;
	    int base10 = log10(N);
	    // denotes the closest 10th, 100th or 1000th to the number
	    int valueOfBase = ceil(pow(10, base10));
	    // to store the precoputed value of base10s
	    int* arr  = new int[base10 + 1]; // note the arr[0] is for N = 0
	    // arr[1] if for 0-9
	    arr[0] = 0; arr[1] = 1;
	    // this arr can be passed as argument to save some runtime
	    for(int i = 2; i<=base10; i++){
		    arr[i] = arr[i-1]*9 + ceil(pow(10,i-1));
	    }
	    // extract the Most significant decimal from number
	    int msd = (int)(N/valueOfBase);
	    /* for say 425
	     * till(0-399) + till(25) + 400(1)
	     * */
	    if(msd == 4){
		    retVal =  msd*arr[base10] + (N % valueOfBase) + 1;
	    }
	    /*for say 765
	     * till (0-399) + till(500-699) --> msd-1 * arr[d]
	     * till (400-499)
	     * rest for (765 % d)		
	     * */
	    else if(msd > 4){
		    retVal =  (msd-1)*arr[base10] + valueOfBase + countNumberswith4(N % valueOfBase);
	    }
	    else{
		    retVal = msd*arr[base10] + countNumberswith4(N % valueOfBase);
	    }
	    return retVal;
   }
};
