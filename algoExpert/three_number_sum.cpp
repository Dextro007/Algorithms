/* Solution for Three Number sum */

#include <vector>
using namespace std;

/* Some test cases are failing as the unchanged value in
the vector is 0 so it is giving false positives*/
bool checkSum(vector<int> temp, int targetSum) {
  int tempSum=0;
  // get the sum of all the elements
  for (int i=0; i<temp.size(); i++) {
    tempSum += temp[i];
  }
  // check if there is a 0 in vector which does not belong
  // since the array is sorted it should remain sorted
  for (int i=1; i<(temp.size()-1); i++) {
   if((temp[i]<temp[i-1]) || (temp[i]>temp[i+1])) {
     return false;
   }
  }
  
  if (tempSum == targetSum) {
    return true;
  }
  return false;
}
void calcSubset(vector<vector<int>> &result, vector<int> &temp,
vector<int> array, int targetSum, int arrIndex, int expSize, int index) {

  // sort and store the array
  if (index == expSize) {
    if (checkSum(temp,targetSum))
      result.push_back(temp);
    return;
  }
  
  // boundary check for index against array.size()
  if (arrIndex > array.size()) {
    return;
  }

  // add current element to temp array
  temp.push_back(array[arrIndex]);
  // proceed with including the element
  calcSubset(result, temp, array, targetSum, arrIndex+1, expSize, index+1);
  // proceed w/o including the element
  temp.pop_back();
  calcSubset(result, temp, array, targetSum, arrIndex+1, expSize, index);
  return;
}

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
  vector<vector<int>> result;
  vector<int> temp;
  sort(array.begin(), array.end());
  calcSubset(result, temp, array, targetSum, 0, 3, 0);
  return result;
}