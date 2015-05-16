//Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

//get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
//set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
// 初步定位map+双向列表的形式啊。
#include <map>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct DoubleListNode{
	int val;
	int key;
	DoubleListNode *right;
	DoubleListNode *left;
	DoubleListNode(int x,int y):val(x),right(NULL),left(NULL),key(y) {}
};
class LRUCache{
public:
    LRUCache(int capacity) {
        		max=capacity;
        		size=0;
       		lru_map=new map<int,DoubleListNode>();
		head=NULL;
		tail=NULL;
    }
    int get(int key) {
        map<int,DoubleListNode>::iterator itr=lru_map->find(key);
		if (itr==lru_map->end()) return -1;
		changeList(itr->second);
		return (*head).val;
    }
    void set(int key, int value) {
        map<int,DoubleListNode>::iterator itr=lru_map->find(key);
		if (itr==lru_map->end()) {  //insert
			DoubleListNode add_node(value,key);
			lru_map->insert(pair<int,DoubleListNode>(key,add_node));
			///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			//c++真是坑啊!!!!!
			//由于insert是值传递的啊,写入lru_map的只是add_node的一个副本啊
			//而如果直接使用add_node进行设置setHead,等你set方法结束,
			//head就指向了null了,必须使用lru_map中的副本进行setHead
			setHead(lru_map->find(key)->second);
			
			size++;
			if(size>max) {   //remove last    also need to delete the map
				//去掉tail上的
				cout<<"delete the tail"<<tail->key<<endl;
				if (tail==NULL) {
					cout<<"tail is null"<<endl;
				}
				int deleteKey=tail->key;
				tail=tail->left;
				lru_map->erase(lru_map->find(deleteKey));
				//delete
			}
		} else {  //set
			itr->second.val=value;
			changeList(itr->second);
		}
		cout<<"the head is "<<head->key<<" the tail is "<<tail->key<<endl;
    }
private:
	int max;
	int size;
	map<int,DoubleListNode> *lru_map;
	DoubleListNode *head;  //头
	DoubleListNode *tail;   //尾
	/**
	** move the cur to head
	**/
	void changeList(DoubleListNode &cur) {   //must use &&&&&!!!!!!!!!!!!!!!!!!!!!!
		//在原有位置删除Node,放在最开头去。	
		cout<<"changeList"<<head->key<<" "<<cur.key<<endl;	
		if(head->key==cur.key) {  //just on head ,包括头尾是同一个的情况
			
			//do nothing
		} else if (tail->key==cur.key) {   //这种情况是头尾不是指向一个,是尾的情况
			cout<<"in tail"<<endl;
			tail=tail->left;
			tail->right=NULL;

			setHead(cur);
		} else {
			cout<<"in middle"<<endl;
			DoubleListNode* pre=cur.left;
			DoubleListNode* next=cur.right;
			pre->right=next;
			next->left=pre;

			setHead(cur);
		}
	}
	void setHead(DoubleListNode & cur) {
			cout<<"setHead"<<endl;
			if (head==NULL&&tail==NULL) {
				head=&cur;
				tail=&cur;
			}
			head->left=&cur;
			cur.right=head;
			head=&cur;
			cur.left=NULL;
	}
};
int main() {
	LRUCache cache(1);
	cache.set(2,1);
	cout<<"-------------------"<<endl;
	int a=cache.get(2);
	cout<<"-------------------"<<endl;
	cache.set(3,2);
	cout<<"cache get 2"<<endl;
	int b=cache.get(2);
	cout<<"cache get 3"<<endl;
	int c=cache.get(3);
	int d=0;
	cout<<a<<" "<<b<<" "<<c<<endl;
}
