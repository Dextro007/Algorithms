#include <vector>
#include <iostream>

using namespace std;

long long int solveRecursion(vector<int> valueInHouse,
    long long int n)
{
    long long int maxRob=0;   
    if ( n==0 ) {
        return valueInHouse[0]; 
    }
    if ( n<0 ) {
        return 0;
    }

    maxRob = max(solveRecursion(valueInHouse, n-1),
        (solveRecursion(valueInHouse, n-2) + valueInHouse[n]));
    return maxRob;
}
long long int houseRobber(vector<int>& valueInHouse)
{
    long long maxVal=0;
    int size = valueInHouse.size();
    maxVal = max(solveRecursion(valueInHouse, size-1), 
    (solveRecursion(valueInHouse, size)));
    // cout << maxVal;
    return maxVal;

}