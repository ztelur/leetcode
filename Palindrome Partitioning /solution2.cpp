#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<string> > partition(string s) {
    	vector<string> pal;
    	vector<vector<string> > res;
    	dfs(s,res,pal);
    	for(int i=0;i<res.size();i++) {
    		for(int j=0;j<res[i].size();j++) {
    			cout<<res[i][j]<<endl;
    		}
    	}
    	return res;
    }
    void dfs(const string s,vector<vector<string> > &res,vector<string> &pal) {
    	cout<<"ddd   "<<s<<endl;
    	int size=s.size();
    	if (size==0) {
    		res.push_back(pal);
    		return ;
    	}
    	for(int i=0;i<size;i++) {
    		if (isPalindrome(s.substr(0,i+1))) {    // if is palindrome
    			cout <<""<<s.substr(0,i+1)<<endl;
    			pal.push_back(s.substr(0,i+1));
    			dfs(s.substr(i+1,size-i-1),res,pal);
    			pal.pop_back();
    		}
    	}
    	return ;
    }
    bool isPalindrome(string s) {
    	if (s.size()==0) return false;
    	int i=0;
    	int j=s.size()-1;
    	while(i<j) {
    		if (s.at(i)!=s.at(j)) return false;
    		i++;
    		j--;
    	}
    	return true;
    }
};
int main() {
	string s("a");
	Solution solution;
	solution.partition(s);

}