#include <stdio.h>
using namespace std;
class Solution {
public:
    void rotate(int nums[], int n, int k) {
  	/**
  		method 1 use a k-size array to store the last-k-int in the nums
  	**/
  	// figure the k and n
  	k=k%n;
  	if (k<=0) {
  		return ;
  	}
  	if(n/k>2) {  //    k is less than 1/2 of n
  		int last_k[k];
  		for(int i=n-1;i>=0;i--) {
  			printf("%d location is %d\n",i,nums[i]);
  			if (i>=n-k) {
  				printf("%d location store the last value\n",k-(n-i));
  				 last_k[k-(n-i)]=nums[i]; // notice the location 
  			} else {	
  				printf("%d location\n",i+k );
  				nums[i+k]=nums[i];
  			}
  		}
  		for(int j=0;j<k;j++) {
  			nums[j]=last_k[j];
  		}

  	} else {
  		int m=n-k ;// first m location
  		int first_k[m];
  		for(int i=0;i<n;i++) {
  			if (i<=m-1) {
  				first_k[i]=nums[i];
  			} else {
  				nums[i-m]=nums[i];
  			}
  		}
  		for(int j=n-1;j>=n-m;j--) {
  			nums[j]=first_k[m-(n-j)];
  		}
  	}
  	// for(int i=0;i<n;i++) {
  	// 	printf("%d\n",nums[i]);
  	// }
    }
};
int main() {
	int input[3];
	input[0]=1;
	input[1]=2;
	input[2]=3;
	Solution solution;
	solution.rotate(input,3,2);

}