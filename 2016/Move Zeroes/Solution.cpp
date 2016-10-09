#include <vector>
#include <stdio.h>
#include <limits.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      /**
      * 排序，将0都放到末尾，最简单的方法就是遍历一遍，发现0就冒泡到末尾
      * in place
      **/
      int n = nums.size();
      if (n == 0 || n == 1) {
        return nums;
      }
      int index = 1;
      //error2 两个指针是有关系的，i一定要小于index
      for(int i = 0; i < n; i++) {
          int v1 = nums[i];
          if (v1 == 0) {
            // swap the value of index and i if index value is not 0
            int v2 = nums[index];
            // locate non-zero
            //error1 遍历时并没有设置终止条件！！！！
            while(v2 == 0 && index < n) {
              index++;
              v2 = nums[index];
            }
            //swap
            if (index < n) {
              nums[i] = v2;
              nums[index] = v1;
            }
          }

          if (index == n)
            break;
          if (i >= index)
            index++;
      }
    }
    // best solution 
    void moveZeroesbest(vector<int>& nums) {
        int j = 0;
        // move all the nonzero elements advance
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }
        for (;j < nums.size(); j++) {
            nums[j] = 0;
        }
    }
};
