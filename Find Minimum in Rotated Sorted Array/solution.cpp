#include <stdlib.h>
#include <vector>
using namespace std;
/*
	1 对于这个题目，首先一次遍历一定是可以的啊，但是时间复杂度是O(n)
	2 对于已经排序过的数组，只要其结构没有被破坏的很严重，那么应该都是可以使用二分法的。
	3 二分法的关键是寻找比较的条件，也就是如何判断结果在两边的哪一边的啊。
	4 对于已经知道的结构，然后进行一定的变化，要清楚变化只可能部分的改变了结构的特性，可以利用改变生成的特性
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        // if (nums==NULL)
        // 	return ;
        int start=0;
        int end=nums.size()-1;
        while(start<=end) {
        	int mid=(start+end)/2;
        	if (nums[mid]>nums[end]) {
        		start=mid+1;
        	} else if(nums[mid]<nums[start]) {
        		end=mid;

        	} else {
        		return nums[start];
        	}
        }
        return nums[start];
    }
};
int main() {

}
