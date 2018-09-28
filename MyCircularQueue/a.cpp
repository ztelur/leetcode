#include <vector>

using namespace std;
// https://zh.wikipedia.org/wiki/%E7%92%B0%E5%BD%A2%E7%B7%A9%E8%A1%9D%E5%8D%80
// 最为主要的方法是解决判定缓冲区是full还是empty
class MyCircularQueue {
private:
    vector<int> vec;
    int head,tail;   
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k): vec(k+1, 0), head(0), tail(0) {
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (!isFull()) {
            vec[head] = value;
            head = (head + 1) % vec.size();
            return true;        
        }    
        return false;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (!isEmpty()) {
            tail = (tail + 1) % vec.size();
            return true;
        }
        return false;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (!isEmpty()) {
            return vec[tail];
        }    
        return -1;
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (!isEmpty()) {
            return vec[(head + vec.size() - 1) % vec.size()];
        }    
        return -1;
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return head == tail; 
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        int next = (head + 1) % vec.size();
        return next == tail;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * bool param_1 = obj.enQueue(value);
 * bool param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * bool param_5 = obj.isEmpty();
 * bool param_6 = obj.isFull();
 */