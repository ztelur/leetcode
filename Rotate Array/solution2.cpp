#include <stdio.h>
using namespace std;
class Solution {
public:
    void rotate(int nums[], int n, int k) {
    	k=k%n;
    	if (n<=0||k==0) {
    		return ;
    	}
    	int start=k-1;
    	reverse(nums,0,n-1);
    	reverse(nums,0,start);
    	reverse(nums,start+1,n-1);
    }
    void reverse(int nums[],int start,int end) {
    	while(start<end) {
    		int temp=nums[start];
    		nums[start]=nums[end];
    		nums[end]=temp;
    		start++;
    		end--;
    	}
    }
};
int main() {
	int a[4];
	a[0]=-1;
	a[1]=-100;
	a[2]=3;
	a[3]=99;
	Solution solution;
	solution.rotate(a,4,3);
}