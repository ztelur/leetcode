#include <stdio.h>
using namespace std;
class Solution {
public:
    void rotate(int nums[], int n, int k) {
  	k=k%n;
  	if(n<=0||k==0) {
  		return ;
  	}
  	int i=0;  // loop num
  	int location=0; //cur loop location
  	int pre=nums[location];
  	while(i<n) {
  		int temp;
  		if (location<=n-k-1) {   // 
 			temp=nums[location+k];
 			nums[location+k]=pre;
 			/*location=location+k;
 			nums[location+k]=pre;  errorrrrr!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 			*/
 			location+=k;
 			pre=temp;
  		} else {
  			temp=nums[location-(n-k)];
  			nums[location-(n-k)]=pre;
  			location=location-(n-k);
  			pre=temp;
  		}
  		i++;
  	}      
  	for(int i=0;i<n;i++) {
  		printf("%d\n", nums[i]);
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