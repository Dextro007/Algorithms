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

Approach : DP (overlapping subproblems, memoization)
 * */
class Solution {
  public:
    int countNumberswith4(int N) {
	    // if number is smaller than 4
	    if(N<4){
		    return 0;
	    }
	    // denotes the power of 10th
	    int base10 = log10(N);
	    // denotes the closest 10th, 100th or 1000th to the number
	    int valueofbase = ceil(pow(10, base10));
	    // to store the precoputed value of base10s
	    int* arr  = new int[base10 + 1]; // note the arr[0] is for N = 0
	    // arr[1] if for 0-9
	    arr[0] = 0; arr[1] = 1;
	    for(int i = 2; i<=base10; i++){
		    arr[i] = arr[i-1]*9 + ceil(pow(10,i-1));

    }
};
