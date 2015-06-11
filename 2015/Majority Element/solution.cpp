/**Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

**/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
    	int len=nums.size();
    	int res;
    	if (len == 0) { //其实在这个语境下无法直接返回一个数值．．．    
			
		} else {
			int mark;
			int num=0;
			for(int i=0;i<len;i++) {
				if (num == 0) {
					mark=nums[i];
					num=1;
				} else {
					if (mark==nums[i]) {
						num++;
					} else {
						num--;
					}
				}
			}
			res=mark;
		}
		return res;
    }
};
