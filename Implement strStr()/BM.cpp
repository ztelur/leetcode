/**
 * Implement strStr().
 *
 *Returns the index of the first occurrence of needle in haystack,
 *or -1 if needle is not part of haystack.
*/

/**
 * 实现模式匹配
 * 1 KMP
 * 	  1.1 使用next[] 数组
 * 	  1.2 使用最大相同前缀后缀数组
 * 	  1.3 使用优化的next[]数组
 * 	  O(M+n)
 */
#include <string>
 #include <iostream>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
    	//生成优化的next数组
    	return kmpSearch(haystack,needle);
    }
	/**BM算法
	 *  1 坏字符规则:某个字符和模式串中的某个字符不匹配的时候,模式串需要右移
	 *  移动的位数=坏字符在模式串中出现的位置-坏字符在模式串中最右边的出现的
	 *  位置,如果没有,那么便是-1
	 *  后移位数 = 坏字符的位置 - 搜索词中的上一次出现位置
	 *  2 好后缀规则:当字符失效的时候,后移位数=好后缀在模式串中的位置-好后缀
	 *  在模式串中出现的最右边的位置.如果没有出现,那么就是-1
	 *后移位数 = 好后缀的位置 - 搜索词中的上一次出现位置
	 好后缀"的位置以最后一个字符为准
	 *
	 *  每次进行移动的时候,取两个规则中移动位数比较大的那一条.
	 */
    int BM(string haystack,string needle) {
 			   	
    }
};
int main() {
	Solution solution;
	int a= solution.strStr("mississippi","issip");
	cout<<a<<endl;
}
