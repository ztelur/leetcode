/**Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"
注意的是，这里是S中有多少子串在和T相同啊。
这个类似与字符串的匹配问题啊。
logic:
	1 先在S中寻找T的开头，然后只要继续比较，如果有不同的，那么T指针不动，
	S指针后移，只要找到T，然后count++，然后S继续后移啊。使用回溯法啊。
	2 先找T结尾的字符。

	感觉类似于KMP的升级版啊

解法一：回溯法一定是可以的啦。导致out of time 啦。。。。
Return 3.**/

#include <string>
#include <stdio.h>
using namespace std;
class Solution {
public:
	int res;
    int numDistinct(string s, string t) {
 		res=0;
		int lens=s.size();
		if (lens==0) return res;
		int lent=t.size();
		if (lent>lens) return res;
		dfs(s,0,lens,t,0,lent);
		return res;
    }
	/**
	 * locs:当前迭代位置
	 * lens:总长度
	 * loct:
	 * lent:
	 */
	void dfs(string s,int locs,int lens,string t,int loct,int lent) {
		if (loct>=lent) {
			res++;
			return;
		}
		if (locs>=lens) return;
		//判断当前的位置
		printf("%s %d %d %d %d \n","test",locs,lens,loct,lent);
		if (s[locs]==t[loct]) {  //当前位置相匹配
			dfs(s,++locs,lens,t,++loct,lent);//当前位置计算在内
			dfs(s,++locs,lens,t,loct,lent); //滤过当前位置
		} else {
			dfs(s,++locs,lens,t,loct,lent);
		}
		return;
	}
};
int main() {
	Solution solution;
	solution.numDistinct("a","b");
}
