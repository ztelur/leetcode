#include <vector>
#include <string>
#include <iostream>
#define debug true
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        // if (board==NULL||word==NULL||board.size()==0||word.length()==0) {
        // 	return false;
        // }
        if (board.size()==0||word.length()==0) {
        	return false;
        }
        for(int i=0;i<board.size();i++) {
        	for(int j=0;j<board[i].size();j++) {
        	    if(dfs(board,word,i,j,0))  //from the first char in the word
        	    {
        	        return true;
        	    }
        	}
        }
    }
    bool dfs(vector<vector<char> > & b,string word,int x,int y,int cur) {
    	bool result=false;
    	if(cur==word.length()) {
    		return true;
    	}
    	if (x>=b.size()||y>=b[0].size()) {   // assumption that board has 0 row
    		return false;
    	}
    	char c=b[x][y];
      	if (b[x][y]==word.at(cur)) {

      		b[x][y]='*';

      		result=dfs(b,word,x+1,y,cur+1)|
      			dfs(b,word,x-1,y,cur+1)|
      			dfs(b,word,x,y+1,cur+1)|
      			dfs(b,word,x,y-1,cur+1);
      		if (result) {
      			return true;
      		}
      		b[x][y]=c;
      	}
      	return false;
    }
};
int main() {
	vector<vector<char> > vec;
	vector<char> v1;
	v1.push_back('a');
	vec.push_back(v1);
	Solution solution;
	if (solution.exist(vec,"a")) {
		cout <<"dddd"<<endl;
	}
}