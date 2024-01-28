#include <vector>

using namespace std;

vector<vector<int>> transposeMatrix(vector<vector<int>> matrix) {
  // Write your code here.
  unsigned int n,m;
  m = matrix.size();
  n = matrix[0].size();
  vector<vector<int>> vec(n, vector<int>(m));
  for (unsigned int i=0; i<n; i++){
    for (unsigned int j=0; j<m; j++) {
      vec[i][j] = matrix[j][i];
    }
  }
  //cout << n << " " << m;
  return vec;
}
