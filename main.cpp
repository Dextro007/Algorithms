#include <iostream>
#include <vector>
#include "dynamicProgramming/houseRobbery.h"
using namespace std;

static
void arrayTestCase(void)
{
    long long T;
    long long n; 
    // get the no. of testcases 
    // cout << "Enter T: ";
    cin >> T;
    for ( long long i = 0; i < T; i++ ) {
        cin >> n;
        vector<int> vect;
        int value;
        // get the array value
        // cout << " Elements of array: \n";
        for (long long j=0; j < n; j++ ) {
            cin >> value;
            vect.push_back(value);
        }
        cout << houseRobber(vect);
        return;
    }
}

void testfunc(void)
{
    vector<int> vect;
    vect.push_back(2);
    vect.push_back(3);
    vect.push_back(2); 
    houseRobber(vect);
}

int main()
{
    // arrayTestCase();
    testfunc();
    return 0;
}