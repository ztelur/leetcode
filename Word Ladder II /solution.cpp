#include <vector>
#include <string>
#include <stdlib.h>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
		vector<vector<string> > res;
		vector<string> cur;
		if(start==NULL||end==NULL) return res;
		cur.push_back(start);
		dfs(start,end,dict,res,cur);
		return res;
    }
	void dfs(string start,string end,unordered_set<string> &dict,vector<vector<string> > & res,vector<string> & cur) {
		char c;
		for(int i=0;i<start.size();i++) {
			if(start[i]!=end[i]) {  //有一个位置可以改变
				c=start[i];
				start[i]=end[i];  //1.1
				if(contain(dict,start)) {  //字典中保存这个字段
					cur.push_back(start);//2.1
					dfs(start,end,dict,res,cur);
					cur.pop_back();//2.2
					//进行迭代
				}
				start[i]=c;//1.2
			}
		}
		if(start==end) {
			res.push_back(cur);
		}
	}
	int diff(const string start,const string end) {
		for(int i=0;i<start.size();i++) {
			if(start[i]==end[i]) return i;
		}
		return -1;
	}
	bool contain(const unordered_set<string>& dict,const string str) {
		return dict.find(str)!=dict.end();
	}
};
