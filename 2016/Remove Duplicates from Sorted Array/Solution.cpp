class Solution {
public:
    //需要注意的是排序了的array,所以不需要记录重复value了
    int removeDuplicates(vector<int>& nums) {
      int n = nums.size();
      if (n == 0 || n == 1) {
        return n;
      }
      int i = 1;
      int j = 1;
      while(i < n && j < n) {
        int val = nums[i];
        if (val != nums[i-1]) {
          nums[j] = val;
          j++;
        }
        i++;
      }
      return j;
    }
};
