/**判断两个单链表是否有相同的节点,就是说两个链表是否最后合成了同一个链表啦
 *    - - - - -
 *    			- - - - - -
 *    - - - - -			
 *    考察的地方其实很巧的,应该还是思维的转变,一般来说如果要查找二者是否
 *    有相同的元素,一般都是进行遍历,然后查看另一个对象是否包含当前遍历得到的
 *    元素.这就是一般比较最常用的方法.如果你在遇到这种情况就直接想到了
 *    这个思路,然后在想到如何去得知第二个对象包含这个元素(一般都是在这里
 *    进行优化,那么在解这道题的时候,思路其实就已经偏离了,),对于这样的方法,
 *    首先要想到的是从条件推出充分必要条件)
 */
#include <stdio.h>
using namespace std;
struct Node {
public:
	Node *next;
	int value;
	Node(int val){
		value=val;
	}
}
/**
 * 一个问题是,在这个方法中是需要使用值传递?引用传递?还是传指针呢?
 * 值传递如果要传递对象的话,效率比较第的啊
 */
int combine4(Node first,Node second) {
			while(first.next!=NULL) {
				first=first->next;
			}
			while(second.next!=NULL) {
				second=second->next;
			}
			return first==second;
}
int combined3(Node *first,Node *second){

}
int main() {

}

