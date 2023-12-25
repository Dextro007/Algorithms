#include<iostream>
#include<string.h>

using namespace std;
class Solution {
  public:
    int editDistance(string s, string t) {
        
        int len1 = s.size() +1;
        int len2 = t.size() +1;
        int arr[len1][len2];
        for(int row =0; row<len1; row++){
            for(int col = 0; col<le2; col++){
                if(row == 0){
                    arr[row][col] = col;
                }
                else if(col == 0){
                    arr[row][col] = row;
                    
                }
                else{
                    if(s[row-1] == t[col-1]){
                        arr[row][col] = arr[row-1][col-1];
                        
                    }
                    else{
                        arr[row][col] = 1+ min(arr[row-1][col], min(arr[row][col-1],
                                                arr[row-1][col-1]));
                                                
                    }
                }
            }
        }
        int ret = arr[len1-1][len2-1];
        return ret;
    }
    
};
