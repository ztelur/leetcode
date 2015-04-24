#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
  	vector<vector<int> > res;
  	if (num.size()==0) return res;
  	vector<int> per;
  	dfs(num,per,res);
  	return res;
    }
    void dfs(vector<int> & num,vector<int> &list,vector<vector<int> > &res) {
    	if (num.size()==0) {
    		res.push_back(list);
    		return ;
    	}
    	for(int i=0;i<num.size();i++) {
    		int digit=num[i];
    		list.push_back(digit);
    		num.erase(num.begin()+i);
    		dfs(num,list,res);
    		list.pop_back();
    		num.insert(num.begin()+i,digit);
    	}
    }
};