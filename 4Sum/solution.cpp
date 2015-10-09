
/**
 * 1 排序
 * 2 使用回溯法 不对，没有认真思考backtracking对于这题的使用方式啊
 *   如果使用backtracking,那么如何进行控制呢？
 *   backtracking的关键点：
 *   	1 合适进行dfs,由于你不知道当前的节点是否能构成4个，那么你每个点都要
 *   	进行遍历啦，那就相当于复杂度最高的排列组合遍历啦！！！！
 */

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
		vector<vector<int> > res;
		int len;
		if((len=num.size())<=0) return res;
		sort(num.begin(),num.end()); //sort
		
	}
	void dfs(

};
