/**
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
  ]**/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> buf;
        vector<vector<int>> res;
        trackback(res,nums,0,nums.size(),buf);
        return res;
    }
  void trackback(vector<vector<int>> res,vector<int> &nums,int loc,int size,vector<int> & buf) {
    if (loc == size) {
      vector<int> buf2 = buf;
      res.push_back(buf); //应该是buf的克隆啦
      return;

    }
    int cur = nums.at(loc);
    int iter = loc;
    while (iter<size && nums.at(iter) == cur) {
      iter++;
    }
    // 如果iter - cur == 3 那么说明中间有3个相同的，那么就有3种情况啦

    while (loc < iter) {
      trackback(res,nums,iter,size,buf);
      buf.push_back(cur);
      loc++;
    }
  }
};
int main() {
  Solution solution;
  solution.
}
