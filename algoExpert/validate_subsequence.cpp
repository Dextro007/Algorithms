using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  // Write your code here.
  bool retVal = false;
  unsigned int arrSize = array.size();
  unsigned int seqSize = sequence.size();
  unsigned int count=0;
  unsigned int i=0,j=0;
  while(i<arrSize && j<seqSize) {
    if (array[i]==sequence[j]) {
      count++;
      j++;
    }
    i++;
  }
  if (count==seqSize)
    retVal = true;
  
  return retVal; 
}