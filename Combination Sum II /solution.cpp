#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
/*
 * 思路:
 * 1 不事先对数组进行排序
 * 2 还是先排序比较好
 * 	2.1 从头开始
 * 		2.1 如果是加上这个位置小于 分两种情况 
 * 			2.1.1 加上
 * 			2.1.2 不加
 * 		2.2 正好等于,添加,并返回
 * 		2.3 大于,返回
 */
class Solution {
public:
	vector<vector<int> > *res;
    	vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
		res=new vector<vector<int> >();
        		vector<int> vec;
		if(target<1||candidates.size()<1) return *res;
		sort(candidates.begin(),candidates.end());
		dfs(vec,candidates,0,target,0);
		return *res;
    	}
	void dfs(vector<int> vec,const vector<int>& candidates,int sum,int target,int loc) {
		if(loc>=candidates.size()) return;
		int pre_sum=sum;
		cout<<"the sum is "<<sum<<" the loc is "<<candidates[loc]<<"the target is"<<target<<endl;
		sum+=candidates[loc];
		if(sum==target) {
			vec.push_back(candidates[loc]);
			res->push_back(vec);
			vec.pop_back();
			return;
		} else if (sum<target) {
			//继续
			vec.push_back(candidates[loc]);
			int j=loc;
			for(;j<candidates.size();j++) {
				if (candidates[j]!=candidates[loc]) break;
			}
			dfs(vec,candidates,sum,target,loc+1);  
			//这个位置和下边的那个dfs很不同,因为是要避免相同int的情况,上边这个dfs是添加了这个位置的int,所以是loc+1,
			//而下边那个dfs是当前的位置的int不添加进结果,所以要避免在次进入下边的相同的int值,那么就相当于又重复调用了一次
			vec.pop_back();
			sum=pre_sum;
			dfs(vec,candidates,sum,target,j);
		} else {
			return ;
		}
		return ;
	}
};
int main() {
	Solution solution;
	vector<int> so;
	so.push_back(2);
	so.push_back(1);
	vector<vector<int> > res=solution.combinationSum2(so,2);
	cout<<"--------------------------"<<endl;
	for(int i=0;i<res.size();i++) {
		for(int j=0;j<res[i].size();j++) {
			cout<<" "<<res[i][j]<<" ";
		}
		cout<<endl;
	}
}
