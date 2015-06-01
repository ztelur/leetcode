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
		int lens=s.length();
		int lent=t.length();
		int [][] mem=new int[lens][lent];
		//当t为空字符的时候，也就是说t.length()=0的时候啊。s为任何数，mem[s][0]都是1
		for(int i=0;i<lens;i++) {
			mem[i][0]=1;
		}
		//然后进行遍历啊
		for(int i=0;i<lens;i++) {
			for(int j=0;j<lent&&j<=i;j++) {   //只需要计算对角线一下的部分啊。其他部分其实都是0的啊。
				if (s[i]==s[j]) {
					if (i==j)//对角线上{
						
					}
				}
			}
		}
    }
};
int main() {
	Solution solution;
	solution.numDistinct("a","b");
}

