#include <stdlib.h>
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;
class Solution {
    //主要的问题是如何存储数值对应的字母信息，涉及表编程的啊。其实就是hashmap加vector之类的啊。
    //但是好像使用ASCII编码好像也是可以的啊。使用一个int数组来表示a,a[i]表示，i数组代表的字符组的开始的
public:
    //   0 |  1  | 2  | 3  | 4  |   5    |     6        | 7        |    8       | 9
    //   *    *   123  456  789  10 11 12  13 14 15      16 17 18 19 20 21 22     23 24 25 26
    int tables[11]={0,0,1,4,7,10,13,16,20,23,27};// 0,1都是特殊字符啊。7,9是4个字符啊。
              //0,1,2,3,4,5, 6, 7, 8, 9  10
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        int len=digits.length();
        if (len==0) return res;
		res.push_back("");
       for(int i=0;i<digits.length();i++) {
            res=func(digits[i],res);
       }
       return res;
    }
    vector<string> func(char s,vector<string> &input) {

           vector<string> res;
           int loc=s-'0';  //0~9
           int start=tables[loc];
           
           int end=tables[loc+1];
		   //这边是重大的问题啊，没有考虑刚开始input应该是空的，所以循环根本
		   //没有进入啊。
           for(int i=start;i<end;i++) {
               for(int j=0;j<input.size();j++) {
                    char str=transform(i);

                    res.push_back(input[j]+transform(i));
               }
           }
           return res;
    }
    char transform(int i) {
      char x=char(i+96);
      return x;
    }
};
int main() {
	Solution solution;
	solution.letterCombinations("243");
}
