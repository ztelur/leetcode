class Solution {
public:
    //就和move zero一样，那是把zero全部移动到末尾，这里其实也可以使用相同的方法进行
    int removeElement(vector<int>& nums, int val) {
      int n = nums.size();
      if (n == 0) {
        return 0;
      }
      if (n == 1) {
        return nums[0] == val ? 0 : 1;
      }
      int i = 0;
      int j = 0;
      while(i < n && j < n) {
        int itr = nums[i];
        if (itr != val) {
          nums[j] = itr;
          j++;
        }
        i++;
      }
      return j + 1;
    }
};
