class Solution {
public:
    int searchInsert(int A[], int n, int target) {
    	if (n==0) {
    		return 0;
    	}
	return binarySearch(A,n,0,n-1,target);  //because n-1 is a location for array so make sure it more than zero
    }
    int binarySearch(int A[],int n,int left,int right,int target) {
    	int value;
    	if (left<right&&right<n) {  //notice!!!
    		int mid=(left+right)/2;
    		value=A[mid];
    		if (value==target) {
    			 return mid;
    		} else if(value<target) {
    			return binarySearch(A,n,mid+1,right,target); //mid < target so next left is mid+1 if mid<=target so next left is mid
    		} else {
    			return binarySearch(A,n,left,mid,target);
    		}
    	} else if (left==right) {
    		value=A[left];
    		if (value==target) {
    			return left;
    		} else if(value<target) {
    			return left+1;
    		} else {
    			return left;//注意，返回应该是left，因为要插入的那个值会占据这个位置的啊。
    		}
    	} else {
    		//error
    	}
    }

};
int main() {

}
