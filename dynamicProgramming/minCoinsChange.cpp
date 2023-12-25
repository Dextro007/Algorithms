#include <bits/stdc++.h> 

/* //Recursive appraoch

int solveRecursive(vector<int> &num, int x) {
    int min_val = INT_MAX;
    // base case
    if (x==0) {
        return 0;
    }
    // invalid case
    if (x <0) {
        return INT_MAX;
    }

    for ( int i=0; i < num.size(); i++) {
        int temp = solveRecursive(num, x-num[i]);
        if(temp != INT_MAX) {
            min_val =  min(min_val, 1+temp);
        }
    }

    return min_val;
} */

/* //Memoization
int solveMemoization(vector<int> &num, int x, int *dp)
{
    int min_val=INT_MAX;

    if (x <0 ) {
        return INT_MAX;
    }

    if (dp[x] != INT_MAX) {
        return dp[x];
    }

    for (int i=0; i<num.size(); i++) {
        int temp = solveMemoization(num, x-num[i],dp);
        if(temp != INT_MAX) {
            min_val = min(min_val, temp+1);
            dp[x] = min_val;
        }
    }
    // cout << dp[x] <<" ";
    return dp[x];

} */

// Tabulation Approach bottom - Up
int solveTabulation(vector<int> &num, int x)
{
    vector<int> dp(x+1, INT_MAX);
    dp[0]=0;

    for(int i =1; i<=x; i++) {
        int temp = INT_MAX;
        for(int j=0;j<num.size(); j++) {
            if(i>=num[j]){
                temp = min(temp,dp[i-num[j]]);
            }
        }
        if(temp!=INT_MAX){
            dp[i] =1+temp;
        }

    }
    return dp[x];
}

int minimumElements(vector<int> &num, int x)
{
   /* for recursion and memoization  
   
   int dp[x+1];
    for(int i=0;i<=x;i++)
        dp[i] = INT_MAX;
    dp[0] = 0; */
    // cout<<dp[1]<< " "<<dp[0];
    int ans = solveTabulation(num, x);
    if (ans == INT_MAX) {
        return -1;
    }
    return ans;

}