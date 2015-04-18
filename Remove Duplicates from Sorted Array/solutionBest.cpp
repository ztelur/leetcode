class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n<=1) {
        	return n;
        }
	//这个就是移动数组的最好的方法啊，有一个写的指针，来记录下一个要写的路径，这样就不用每次都移动后边的数组啦。
	//这是最基础的一个知识啊！！！！
        int mark=0;
        for(int i=1;i<n;i++) {
            if (A[i]==A[mark]) {
                //do nothing
            } else {
                A[++mark]=A[i];
            }
            
        }
        return min(mark,n);
};
int main() {
	
}
