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
	int kmpSearch(string s,string p) {
		int i=0,j=0,res=-1;
		int sLen=s.size();
		int pLen=p.size();
		if (sLen==pLen||sLen==0||pLen==0) {   //  s="a",p="", success
			if (s==p) return 0;
			if (p=="") return 0;
			return res;
		}
		if (pLen==0) return 0;
		if (sLen<pLen) return -1;
		int *next=new int[pLen];
		getNextArrayBetter(p,next,pLen);
		while (i<sLen&&j<pLen) {
			// cout<<"i :"<<i<<"j:"<<j<<endl;
			if (j==-1||s[i]==p[j]) {
				if (j==pLen-1){
					res=i-j;
					break;
				}
				i++;
				j++;
			
			} else {  //使用next来进行移动
				//i不动
				j=next[j];
			}
		}
		delete[] next;
		return res;
	}
	void getNextArray(string needle,int next[]) {
		int len=needle.size();
		next[0]=-1;
		int k=-1; 
		int j=0;  // 1:跳过i=0的时候 2:不对,应该是从0开始到len-2,因为是计算j+1的啊
		while (j<len-1) {
			if (k==-1) {  //刚开始的时候
				next[j+1]=0;
				k=0;
				j++;
				continue;
			}
			if (needle[k]==needle[j]) {  
				next[j+1]=next[j]+1;
			} else {
				int flag=0;
				while (next[k]!=-1&&needle[next[k]]!=needle[j]) {
					k=next[k];
				}
				if (next[k]==-1) {  //没有找到
					next[j+1]=0;
				} else {  //找到了一个比较小的
					next[j+1]=next[k]+1;
				}
			}
			k=next[j+1];
			j++;
		}
	}
	/**
	 * 这个算法的过程也太简单啦.....和上边的那个我写的算法.....
	 */
	void getNextArrayBetter(string needle,int next[],int size) {
		int j=0,k=-1;
		next[0]=-1;
		while (j<size-1) { //每次是求j+1的值的
			if (k==-1||needle[k]==needle[j]) {
				++k;
				++j;
				next[j]=k;  // equal to next[j+1]=k+1;
				//对于p[j]=p[k]的优化,注意如果不进行优化,现在k就是next[p]的值啊,会导致p[j]比较不正确,然后p[next[p]]还是正确
				//因为是动态编程,从小往大进行计算,所以这个位置不需要进行递归的,只要保证之前的都没有needle[j]==needle[k]的情况!!!!
				if (needle[j]!=needle[k]) {
					next[j]=k;
				} else {
					next[j]=next[k]; //这里应该可以进行递归的
				}
			} else {
				k=next[k];
			}
		}
	}
};
int main() {
	Solution solution;
	int a= solution.strStr("mississippi","issip");
	cout<<a<<endl;
}
