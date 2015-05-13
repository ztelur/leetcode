#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> numMap;
        for(int i=0;i<nums.size();i++)
            if(numMap.find(target-nums[i])!=numMap.end())
                return vector<int>{numMap[target-nums[i]]+1,i+1};
            else
                numMap[nums[i]]=i;

    }
};