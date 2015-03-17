#include "../header.h"
#include <stack>
#include <sstream>
#include <vector>
class Solution {
public:
    int figure(string operation,int i,int j) {
   	if (operation=="+") {
   		return i+j;
   	} else if (operation=="-") {
   		return i-j;
   	} else if(operation=="*") {
   		return i*j;
   	} else if (operation=="/") {
   		return i/j;
   	}
    }
    bool checkOperation(string str) {
    	return str=="+"||str=="-"||str=="*"||str=="/";
    }
    int evalRPN(vector<string> &tokens) {
        stack<int> stk;
        int result;
        for(int i=0;i<tokens.size();i++) {
        	if (checkOperation(tokens[i])) {
        		int n=stk.top();
        		stk.pop();
        		int m=stk.top();
        		stk.pop();
        		stk.push(figure(tokens[i],m,n)); //注意这里的栈是后进先出的啊，所以两个位置的要调换一下位置
        	} else {
        		stk.push(atoi(tokens[i].c_str()));
        	}
    	}
            		return stk.top();
	}
};
int main() {
	vector<string> v;
	v.push_back("3");
	v.push_back("-4");
	v.push_back("+");
	Solution solution;
	cout<<solution.evalRPN(v);
}
