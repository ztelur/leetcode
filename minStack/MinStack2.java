package minStack;

import java.util.Deque;
import java.util.LinkedList;
import java.util.Stack;

/**
 * Created by randy on 15-4-5.
 */
    public class MinStack2 {
        /**
         * 注意,这个方法能够成功,其实都是因为stack这个先进后出的栈,而且注意这里边的数据都是一步一步的进入
         * 关键是一步一步的进入,这里的过程性很重要的.
         * 输入的值 2, 3 ,1   这个时候stak [2,3,1]  min [2,1] 所以,当不会出现本来一个比较大的没有进入min,然后min中的一个被pop掉的
         * 情况.
         */
        Deque<Integer> stack=new LinkedList<Integer>();
        Deque<Integer> min=new LinkedList<Integer>();
        public void push(int x) {
            stack.push(x);
            if (min.isEmpty()||min.peek()>=x) {   //这边是个关键点啊,应为要考虑相同的情况,所以必须相对的时候也要加入里边去啊
                min.push(x);
            }
        }
        public void pop() {
            int delet=stack.peek();
            stack.pop();
            if (delet==min.peek()) {
                min.pop();
            }

        }
        public int top() {
            return stack.peek();
        }
        public int getMin() {
            return min.peek();
        }
    }
