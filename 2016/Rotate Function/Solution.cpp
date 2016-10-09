#include <vector>
#include <stdio.h>
#include <limits.h>
using namespace std;
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
      int n = A.size();
      if (n == 0) {
        return 0;
      }
      int max = INT_MIN;
      for (int i = 0; i < n; i++) {
        int result = figure(A,n,i);
        if (max < result) {
          max = result;
        }
      }
      return max;
    }
    int figure(vector<int>& A, int length, int start) {
      int sum = 0;
      int i = 0;
      int index = start;
      while (i < length) {

        sum += A[index] * i;
        i = i + 1;
        index = index + 1;
        if (index >= length) {
          index = 0;
        }
      }
        return sum;
    }
};
