/**Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. 
You should gather all requirements up front before implementing one.**/

/* logic:
 * 1 多个字母 abc--false
 * 2 e字母  可以是按照
 * 3 . 按照小数
 * 4 全是数字
 * 想的方法是如果当前节点之前是numberic，是否可以完全无视，直接看之后的string？
 * 0.010是numeric？
 * 0001 是numberic？
 * e 不是的
 *. 也不是的
 *  .3434 is
 	3. is
 	4. is
 	.3434 is
 *  注意还有空格的问题啊，空格不能出现在数字中间啊。
 *  e9 false                       10e-3 ok
 *
 *  处理的时候，有些时候只需要处理这个位置后边不能有神马元素就可以，但是一些
 *  特殊的元素，前边必须有一些值，比如说e9为false，所以e的前边必须有数字
 *
 */
 #include <string>
 #include <stdio.h>
 using namespace std;
class Solution {
public:
	bool isNumber(string s) {
		int len;
		len=s.size();
		if (len==0) return false;
		return isNumberIn(s,0,len);
	}
	//由于是一个一个按照顺序判断，所以，每个位置只需要判断一个方的是否合理，比值判断自己后方的元素是否合理就可以啦。
    bool isNumberIn(string s,int start,int end) {
    	//先出去外侧的空格字符	
		int dotNum=0;
		int eNum=0;
		int Emode=0;
		while(start<end&&isBlank(s[start])) {
			start++;
		}
		while(end>start&&isBlank(s[end-1])) {
			end--;
		}
		if (start==end) return false;
		
		if (isNegPos(s[start])) {
			start++;
		}
//		然后在去掉前边的逗号，和后边的逗号。
		if (start==end) return false;
		if(isDot(s[start])) {
			start++;
			dotNum++;
		}
		if (start==end) return false;
// 		if (isDot(s[end-1])) {
// 			end--;
// 			dotNum++;
// 		}
		if (dotNum==2) return false;
		if (start==end) return false;
		
		//进入真正的判断
		int i=start;
		while(i<end) {
			if (isNum(s[i])) {
				//01 和 0.010都是可以的啊
			} else if (isE(s[i])) {
				eNum++;
				if (eNum>1) return false;
				//e的两侧都必须有数字啊
				//相同的问，E需要判断前边的位的char吗？其实E只是需要前边其他位置而，不需要判断前边位的值
				if (i-1<start||i+1>=end||!(isNum(s[i+1])||isNegPos(s[i+1]))) {  //E的前可以有.但是后边不能有dot
					return false;
				}//其实感觉，只要有e，那么就可以进行迭代啦。
				//出现了E，那么E之的数必须是整数啦。
				Emode=1;
			} else if (isDot(s[i])) {   //其实dot的判断和E的判断中有重复的地方
				dotNum++;
				if (i-1<start&&i+1>=end) return false;
				if (dotNum>1) return false;
				if (Emode==1) return false;
				//可以肯定，dot不会出现第一 所以i-1>start是无用的,而起Emode==1的判断决定了dot前部不可能是E，dotNum也决定了
				//前也不能是dot,所以不用判断.前边的位置
				//只用判断dot后边的位置啊
				//dot 的后不能为e   .e2 false   23.e2 true !!!!这是神规定啊
				
			} else if (isBlank(s[i])) {
				return false;
			} else if (isNegPos(s[i])){
				//must after the E at first
				if (i-1<start||!isE(s[i-1])) {
					return false;
				}
				//+ or - 必须后边有值,dot,e的啊
				if (i+1>=end) {
				    return false;
				}
			} else {
				return false;
			}
			i++;
		}
		return true;
    }	
    bool isNegPos(const char c) {
    	return c=='-'||c=='+';
    }
	bool isNum(const char c) {
		return c>='0'&&c<='9';
	}
	bool isE(const char c) {
		return c=='e'||c=='E';
	}
	bool isDot(const char c) {
		return c=='.';
	}
	bool isBlank(const char c) {
		return c==' ';
	}
};
int main() {
	Solution s;
	if (s.isNumber(" 4e3.")) {
		printf("true\n" );
	} else {
		printf("false\n");
	}

}

