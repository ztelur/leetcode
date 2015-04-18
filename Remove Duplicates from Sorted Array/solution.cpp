class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n<=1) {
        	return n;
        }
        int len=n;
        int i=len-1;
	// for循环一般都是用于次数确定的循环，而且要注意的是这里的数组的n是会变化的啊，不然会无限循环的啊！！！
        /**
        *  
        *
        */
        // while(i<len) {
        // 	if (A[i]==A[i-1]) {
        // 		for(int j=i+1;j<len;j++) {
        // 			A[j-1]=A[j];
        // 		}
        // 		len--;
        // 		i--;
        // 	}
        // 	i++;
        // }
        while(i>=1) {
        	if (A[i]==A[i-1]) {
        		for(int j=i+1;j<len;j++) {
        			A[j-1]=A[j];
        		}
        		len--;
        		// i++;
        	}
        	i--;
        }
        return len;
    }
};
int main() {
	
}
