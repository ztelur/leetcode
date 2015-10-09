#include <vector>
#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<string> > findLadders(string start, string end, vector<string> &dict) {
		vector<vector<string> > res;
		vector<string> cur;
		// if(start==NULL||end==NULL) return res;
		cur.push_back(start);
		dfs(start,end,dict,res,cur);
		return res;
    }
	void dfs(string start,string end,vector<string> &dict,vector<vector<string> > & res,vector<string> & cur) {
		char c;
		for(int i=0;i<start.size();i++) {
			if(start[i]!=end[i]) {  //有一个位置可以改变
				cout<<"the locaiont is "<<i<<" "<<start[i]<<endl;
				c=start[i];
				start[i]=end[i];  //1.1
				cout<<"change to "<<start<<endl;
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
	bool contain(const vector<string>& dict,const string str) {
		for(int i=0;i<dict.size();i++) {
			if (dict[i]==str) return true;
		}
		return false;
	}
};
int main() {

	Solution* solution=new Solution();
	vector<string> dict;
	dict.push_back("hot");
	dict.push_back("cog");
	dict.push_back("dog");
	dict.push_back("tot");
	dict.push_back("hog");
	dict.push_back("hop");
	dict.push_back("pot");
	dict.push_back("dot");

	vector<vector<string> > res= solution->findLadders("hit","cog",dict);
	for(int i=0;i<res.size();i++) {
		for(int j=0;j<res[i].size();j++) {
			cout<<" "<<res[i][j];
		}
		cout<<"-------------------"<<endl;
	}
}
