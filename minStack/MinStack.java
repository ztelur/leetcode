package minStack;

/**
 * Created by randy on 15-4-5.
 */
class MinStack {
    Entry first=null;
    Entry min=null;

    public void push(int x) {
        if (first==null) {
            Entry insert=new Entry(x,null);
            first=insert;
            linkMin(insert);
        } else {
            Entry insert=new Entry(x,first);
            first=insert;
            linkMin(insert);
        }
    }
    private void linkMin(Entry entry) {
        /**
         * 插入的情况分析啊.
         * 1 min==null:这种情况是直接插入
         * 2 min!=null;进行寻找合适的位置
         *          2.1 找到链表尾,没有合适的位置 ,说明比链表中的所有的值都大,直接插入队尾
         *          2.2 找到了就是在min处,那么就是要联入链表头
         *          2.3 在中间的某个位置
         */
        if (min==null) {
            min=entry;
        } else {
            Entry itr=min;
            Entry pre=min;
            while (itr!=null&&itr.value<entry.value) {   //当entry的值比较大,而且min有比较大的值的时候
                pre=itr;
                itr=itr.big;
            }
            if (itr==null) {   //说明到了尾部啦.
                pre.big=entry;
                entry.small=pre;
            } else {  //说明找到了
                if (itr==min) {  //说明min要大于entry
                    entry.big=min;
                    min.small=entry;
                    min=entry;
                } else {   //说明是在中间位置
                    entry.big=itr;
                    entry.small=pre;
                    pre.big=entry;
                    itr.small=entry;
                }

            }
        }
    }


    public void pop() {
        if (first==null) {

        }
        Entry delete=first;
        first=first.next;
        deleteEntry(delete);

    }
    private void deleteEntry(Entry delete) {
        //需要从头开始找整个位置的.
        Entry itr=min;
        while (itr!=null) {
            if (itr.value==delete.value) {
                break;
            }
            itr=itr.big;  //error 忘记了循环题中的变化,这是whil中最常见的错误
        }
        if (itr==null) {
            //内部错误啊
        }
        /**
         * 这个时候问题又来啦
         *
         */
        if (itr.small!=null&&itr.big!=null) {
            itr.big.small=itr.small;
            itr.small.big=itr.big;
            itr=null;
        } else {
            if (itr.small!=null) {   //说明在尾部啦
                itr.small.big=null;
            }
            if (itr.big!=null) {
            }
        }
        itr=null;  //这就是链表中只有一个链的时候就是直接删除啦.
    }

    public int top() {
        return first.value;
    }

    public int getMin() {
        return min.value;
    }
    static class Entry implements Comparable<Entry>{
        int value;
        Entry next;  //栈的下一个
        Entry small;  //比它小的指针
        Entry big;//比他大的指针
        public Entry(int value,Entry next) {
            this.value=value;
            this.next=next;
        }

        @Override
        public int compareTo(Entry o) {
            if (value==o.value)
                return 0;
            return value>o.value?1:-1;
        }
    }
    public static void main(String[] args) {
        MinStack stack=new MinStack();
        stack.push(-2);
        stack.push(0);
        stack.push(-1);
        stack.getMin();
        stack.top();
        stack.pop();

        System.out.print(stack.getMin());

    }
}
