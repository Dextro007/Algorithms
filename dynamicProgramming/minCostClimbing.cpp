#include <iostream>
#include <algorithm>
#include <vector>

/*  Recursive Relation 

class Solution {
public:
    
    int recursiveFunc(vector<int>& cost, int n) {
        if ((n==0) || (n==1)) {
            return cost[n];
        }
        return (min(recursiveFunc(cost, n-1), recursiveFunc(cost, n-2))
            + cost[n]);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return min(recursiveFunc(cost, n-1), recursiveFunc(cost, n-2));
        
    }

}; */

class Solution {
public:
    
    /* int recursiveFunc(vector<int>& cost, int n) {
        if ((n==0) || (n==1)) {
            return cost[n];
        }
        return (min(recursiveFunc(cost, n-1), recursiveFunc(cost, n-2))
            + cost[n]);
    }
 */
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp[n+1];
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2;  i<=n; i++){
            if (i!=n) {
                dp[i] = min(dp[i-1],dp[i-2]) + cost[i];
            } else{
                dp[i] = min(dp[i-1], dp[i-2]);
            }
        }
        return dp[n];
        
    }

};