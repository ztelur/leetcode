#include "../header.h"
#include <string>
using namespace std;
class Solution {
public:
    bool isScramble(string s1, string s2) {
        /**
         * 思路：设置s1i=s1[0-i],s2i=s2[0:i];
         * so if s1(len-2) is a scrambled string of s2(len-2) so,just check simple condition lead to s1 is a scrambled string of s2
         * 
         **/
        int len1=s1.size();
        int len2=s2.size();
        if (len1!=len2) {
            return false;
        }
        int cur=0;
        int offset=0;
        int a=0;
        string c1,c2;
        while (cur<len1) {
            c1=s1[cur];
            a=s2.find(c1,cur);
            cout <<"cur:"<<cur<<"a:"<<a<<endl;
            if (a<0) {
                return false;
            } else {
                while (s1[cur]==s2[a]) {
                    cout <<"________"<<cur<<" "<<a<<endl;
                    cur++;
                    a--;
                    if (a<0||cur>=len1) {
                        break;
                    }
                }
            }
        }
        if (cur==len1) {
            return true;
        }
         
    }
};
int main() {
    string str1("abc");
    string str2("bca");
    Solution * p=new Solution();
    if (p->isScramble(str1,str2)) {
        cout <<"true"<<endl;
    } else {
        cout <<"false"<<endl;
    }
}