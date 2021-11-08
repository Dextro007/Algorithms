class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
	if(x==0 || y==0){
		return 0;
	}

        int arr[x+1][y+1];
	for(int row = 0; row < x; row++){
		for(int col=0; col<y; col++){
			if(row == 0 || col==0){
				arr[row][col] == 0;
			}
			else{
				if(s1[row-1] == s2[col-1]){
					arr[row][col] = arr[row-1][col -1] + 1;
				}
				else{
					arr[row][col] = max(arr[row-1][col], arr[row][col-1]);
				}
			}
		}
	}
	return arr[x][y];

    }
};
