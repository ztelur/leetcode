/**
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
动态规划
可以看做两个层次的动态规划
以前动态规划都只是一个，可以使用一个一维数组标示
现在这个是二维数组，s，t都是在动态规划。

**/


class Solution {
public:
    int numDistinct(string s, string t) {
		int lenT = t.size();
		int lenS = s.size();
		vector<int> prefixV(lenT,0);
		for(int i=0;i<lenS;i++) {
			for(int j=lenT-1;j>=0;j--) {
				if (s[i] == t[j]) {
					if (j==0) {
						prefixV[j] += 1;
					} else {
						prefixV[j] += prefixV[j-1]; //必须依赖前边已经匹配了
					}
				}
			}
		
		}
		return prefixV.back();
    }
};
