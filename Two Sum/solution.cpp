#include <vector>
#include <iostream>
#include <map>
using namespace std;
/**
 * require: 1 index1 must be less than index2
 * 			2 not zero-base
 *	
 *	logic:
 *		这个题目其实和前边的max points in a line很像，一堆没有相互关系
 *		的点（数字）,由于一个小的集合的点（数字）的组合要满足一定的关系
 *		而进行求解
 *		1 首先想一下时间复杂度 o(n)，也就是一次遍历啦
 	no no no !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 	again not thing about the below zero !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 */
class Solution {
public:
 	vector<int> twoSum(vector<int>& nums, int target) {
		 int length=nums.size();
		//	 if (nums==NULL) return NULL; //判断
		 map<int,vector<int> > num_map;
		 num_map.insert(pair<int,vector<int> >(0,vector<int>()));  //error has been target
		 int cut_num=0;
		 for(int i=0;i<length;i++) {
		 	for(map<int,vector<int> >::iterator iter=num_map.begin();iter!=num_map.end();iter++) {
				int grow_num=iter->first+nums[i];  //how bad the brain you are
				if(grow_num==target) {
					cout<<"==target "<<iter->first<<" "<<i+1<<endl;
					iter->second.push_back(i+1);  //not-base zero location
					cut_num=nums[i];
					break;
				} else if(grow_num<target){
					cout<<"pus_back "<<grow_num<<" "<<endl;
					vector<int> add_vec(iter->second);
					add_vec.push_back(i+1);
					num_map.insert(pair<int,vector<int> >(grow_num,add_vec));
				} else {
					//do nothing
				}
			}
		 }

	return num_map.find(target-cut_num)->second;
 	}
};
int main() {
	Solution solution;
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(4);
	vector<int> res=solution.twoSum(nums,6);
	for(int i=0;i<res.size();i++) {
		cout <<" "<<res[i]<<endl;
	}
}
