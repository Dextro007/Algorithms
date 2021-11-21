/*
 * Problem : Given two strings find the length of the longest common subsequence among them
 *
 * Solution : Since it has overlapping subproblems 
 *
 *                          lcs("AXYT", "AYZX")
                       /
         lcs("AXY", "AYZX")            lcs("AXYT", "AYZ")
         /                              /
lcs("AX", "AYZX") lcs("AXY", "AYZ")   lcs("AXY", "AYZ") lcs("AXYT", "AY")

*Approach : Dynammic Problem
1. Construct a 2D array 
2. if the row_element ==  col_element 
	length =  prev_diagnolValue +  1
3. else 
	length = max of( left, top)

* */

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
	int retVal;
	if(x==0 || y==0){
		return 0;
	}

	//Since it is not a dynamically allocated array initialization is to be done
        int arr[x+1][y+1];
	for(int row = 0; row<= x; row++){
		for(int col = 0; col <= y; col++){
			arr[row][col] = 0;
		}
	}
 
	for(int row = 0; row <= x; row++){
		for(int col=0; col<=y; col++){
			//initialize the 1st row and 1st col
			if(row == 0 || col==0){
				arr[row][col] == 0;
			}
			else{
				// check if both element are same
				if(s1[row-1] == s2[col-1]){
					// if the element same then take the diagonal element 
					arr[row][col] = arr[row-1][col -1] + 1;
				}
				else{
					// else take the max( top, left) 
					arr[row][col] = max(arr[row-1][col], arr[row][col-1]);
				}
			}
		}
	}
	retVal = arr[x][y];

	return retVal;

    }
};
